#include "stdafx.h"
#include <mysql_connection.h>
#include <driver.h>
#include <resultset.h>
#include <statement.h>
#include <prepared_statement.h>

#include "signed.h"
#include "public.h"
#include "Robot.h"
#include "DBUtil.h"
#include "Message.h"
#include "CQCode.h"

DBUtil Signed::db;
bool Signed::exist() {
	string sql = "SELECT * FROM db_users.t_users where qq=?";
	sql::PreparedStatement* stmt = db.prepareStatement(sql);
	stmt->setInt(1, qq);
	sql::ResultSet* res = stmt->executeQuery();
	bool ret = res->next();
	if (ret) {
		score = res->getInt(3);
	}
	delete stmt;
	delete res;
	return ret;
}

int Signed::insertQQ() {
	int ret = -1;
	//如果没有
	string sql = "INSERT INTO `db_users`.`t_users` (`qq`,`nickname`,`score`,`enabled`)"
		" VALUES(?,?,?,?);";
	sql::PreparedStatement* stmt = db.prepareStatement(sql);
	stmt->setInt(1, qq);
	char buff[20];
	sprintf(buff, "%u", qq & 0xFFFFFFFF);
	stmt->setString(2, buff);
	stmt->setInt(3, 100);
	stmt->setInt(4, 1);
	ret = stmt->executeUpdate();
	delete stmt;
	return ret;
}

int Signed::initSignRecord() {
	int ret = -1;
	//之前没签过
	string sql = "INSERT INTO `db_users`.`t_signedrecord`(`qq`,`lastTime`,`maxTimes`) "
		" VALUES(?, curdate(), 1)";
	sql::PreparedStatement* stmt = db.prepareStatement(sql);
	stmt->setInt(1, qq);
	ret = stmt->executeUpdate();
	delete stmt;
	return ret;
}

int Signed::updateRecord() {
	//如果有
	string sql = "UPDATE `db_users`.`t_signedrecord` SET "
		"`lastTime` = curdate(),"
		"`maxTimes` = ? "
		"WHERE `qq` = ?;";
	sql::PreparedStatement *stmt = db.prepareStatement(sql);
	stmt->setInt(1, maxTimes);
	stmt->setInt(2, qq);
	int ret = -2;
	ret += stmt->executeUpdate();
	delete stmt;
	
	sql = "UPDATE `db_users`.`t_users` SET `score` = score + ? WHERE `qq` = ?;";
	stmt = db.prepareStatement(sql);
	stmt->setInt(1, maxTimes * 10);
	stmt->setInt(2, qq);
	ret += stmt->executeUpdate();
	delete stmt;
	return ret;
}

int Signed::getTimes() {
	string sql = "select count(*) from `db_users`.`t_signedrecord` where lastTime = curdate();";
	sql::PreparedStatement *stmt = db.prepareStatement(sql);
	sql::ResultSet* res = stmt->executeQuery();
	res->next();
	int ret = res->getInt(1);
	delete res;
	delete stmt;
	return ret;
}

bool Signed::isFirstSigned() {
	bool ret;
	string sql = "SELECT * FROM db_users.t_signedrecord where qq=?";
	sql::PreparedStatement* stmt = db.prepareStatement(sql);
	stmt->setInt(1, qq);

	sql::ResultSet* res = stmt->executeQuery();
	res->next();

	lastTime = res->getString("lastTime");
	maxTimes = res->getInt("maxTimes");
	cout << lastTime << endl;
	cout << maxTimes << endl;

	sql = "select date_sub(curdate(),interval 1 day);";
	delete stmt;
	stmt = db.prepareStatement(sql);
	delete res;
	res = stmt->executeQuery();
	res->next();
	if (!lastTime.compare(res->getString(1))) {
		maxTimes += 1;
	} else {
		maxTimes = 1;
	}

	sql = "select curdate();";
	delete stmt;
	stmt = db.prepareStatement(sql);
	delete res;
	res = stmt->executeQuery();
	res->next();
	string now = res->getString(1);
	if (!lastTime.compare(now)) {
		ret = false;
	}else{
		ret = true;
	}
	delete res;
	delete stmt;
	return ret;
}

void Signed::success() {
	char buff[100];
	int t = maxTimes * 10;
	sprintf(buff, "签到成功~~\n你是今天第%d个签到的~\n已连续%d天，奖励金币%d,请继续坚持~\n当前余额%d。", 
		getTimes(), maxTimes, t, score + t);
	reply += string(buff);
}

int Signed::sign(Message & m) {
	maxTimes = 1;
	score = 100;
	int ret = 0;
	qq = m.fromQQ;
	reply = CQCode::at(m.fromQQ);
	if (!exist()) {
		ret += insertQQ();
		reply += "首次使用本系统，赠送金币100。\n";
		ret += initSignRecord();
		success();
	} else {
		if (isFirstSigned()){
			ret += updateRecord();
			success();
		} else {
			reply += "重复签到！！禁言10分钟";
			Robot::setGroupBan(m.fromGroup, m.fromQQ, 600);
		}
	}
	Robot::sendGroupMsg(m.fromGroup, reply);
	return ret;
}

Signed::Signed() {
}

Signed::Signed(Message & m){
	sign(m);
}

Signed::~Signed() {
}
