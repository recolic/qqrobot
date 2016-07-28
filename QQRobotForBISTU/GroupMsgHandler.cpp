#include "stdafx.h"
#include "GroupMsgHandler.h"
#include "Util.h"
#include "DBUtil.h"
#include "Robot.h"
#include "PersonInfo.h"
#include "CQCode.h"
#include "signed.h"
#include <regex>
#include <driver.h>
#include <statement.h>
#include <prepared_statement.h>
int GroupMsgHandler::flag = 0;
map<GroupId, int> GroupMsgHandler::count;
GroupMsgHandler::GroupMsgHandler() {
}

GroupMsgHandler::~GroupMsgHandler() {
}

int32_t GroupMsgHandler::handle(Message& m) {
	bool reply = false;
	//if (m.isFromMaster()) {
		//Robot::sendGroupMsg(m.fromGroup, "hi master~");
		//Robot::addLog(CQLOG_INFOSEND, "test", "hi~master~~");
		//string str = CQCode::image("0A535B0E538FFAE8A1AA6AEF7CA61F6C.jpg.cqimg");
		//Robot::sendGroupMsg(m.fromGroup, Util::getWelComeMsg());
		//Robot::addLog(CQLOG_INFOSEND, "test", str);
	string content(m.content);
	
	
	if (!content.compare("签到")) {
		Signed s;
		s.sign(m);
		reply = true;
	} else {
		if (flag == 0) {
			flag = 1;
			Robot::addLog(CQLOG_DEBUG, "db", "init");
			Signed::db.initConnections();
		}
		if (++count[m.fromGroup] == 100) {
			count[m.fromGroup] = 0;
			string msg = CQCode::at(m.fromQQ);
			DBUtil db;
			Signed s(m);
			if (s.existQQ(m.fromQQ)) {
				string sql = "UPDATE `db_users`.`t_users` SET `score` = score + 100 WHERE `qq` = ?;";
				sql::PreparedStatement *stmt = db.prepareStatement(sql);
				stmt->setInt(1, m.fromQQ);
				stmt->execute();
				msg += "你是第100句发言的\n奖励金币100~~,计数清零~\n当前余额：";
				char buff[20];
				sprintf(buff, "%d", s.getScore(m.fromQQ));
				msg += string(buff);
			} else {
				msg += "你从未签到过，本次金币赠送失败\n请发送“签到”后再试。";
			}
			Robot::sendGroupMsg(m.fromGroup, msg);
			reply = true;
		}
	}
	
	/* else {
		if (!content.substr(0, 1).compare("#")) {
			if (m.isFromMaster()) {
			}
			reply = true;
		}
	}*/
	//}
	//test();
	if (reply) {
		return EVENT_BLOCK;
	} else {
		return EVENT_IGNORE;
	}

}

void GroupMsgHandler::test() {
	
}