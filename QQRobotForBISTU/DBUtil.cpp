#include "stdafx.h"
#include "DBUtil.h"

sql::Connection* DBUtil::getConnection(string url, string username, string password) {
	//try {
		//获取驱动实例
		driver = get_driver_instance();
		if (driver != NULL) {
			//连接数据库  
			conn = driver->connect(url, username, password);
		} else {
			//驱动获取失败
		}
		if (conn != NULL) {
			//连接成功
		} else {
			//连接失败
		}
		
	//} catch (sql::SQLException &e) {
	//	//有异常的情况下，输出异常  
	//	cout << "# ERR: SQLException in " << __FILE__;
	//	cout << "(" << __FUNCTION__ << ") on line "
	//		<< __LINE__ << endl;
	//	cout << "# ERR: " << e.what();
	//	cout << " (MySQL error code: " << e.getErrorCode();
	//	cout << ", SQLState: " << e.getSQLState() << " )" << endl;

	//}
	return this->conn;
}

bool DBUtil::isConnected() {
	return conn != NULL;
}

void DBUtil::use(string dbName) {
	conn->setSchema(dbName);
}

sql::ResultSet * DBUtil::executeQuery(string sql) {
	sql::Statement* stmt = conn->createStatement();
	sql::ResultSet* res = stmt->executeQuery(sql);
	return res;
}

void DBUtil::close() {
	conn->close();
}


DBUtil::DBUtil() {
	//url = "tcp://hostname:3306";
	//username = "username";
	//password = "password";
	getConnection(url, username, password);
}

DBUtil::~DBUtil() {
	delete this->conn;
}

void DBUtil::example() {
	try {
		sql::Statement *stmt;
		sql::ResultSet *res;

		driver = get_driver_instance();
		if (driver != NULL)
			//CQ_addLog(authCode, CQLOG_INFORECV, "db", "driver load success");
		//连接数据库  
		conn = driver->connect("tcp://lz.hylstudio.cn:3306", "", "");
		if (conn != NULL) {
			//CQ_addLog(authCode, CQLOG_INFORECV, "db", "connect success");
		} else {
			//CQ_addLog(authCode, CQLOG_INFORECV, "db", "connect failed");
		}
		//选择要连接的数据库  
		conn->setSchema("test");
		//新建一个执行语句  
		stmt = conn->createStatement();
		//执行语句并返回结果集  
		res = stmt->executeQuery("SELECT * from testtable");
		//遍历结果集  
		while (res->next()) {
			//这里的ID是表中的字段名  
			string t = "";
			int id = res->getInt("id");
			char buffer[10] = { 0 };
			sprintf(buffer, "%d", id);
			t += buffer;
			t += "   ";
			t += res->getString("user");
			//CQ_addLog(authCode, CQLOG_INFORECV, "db", t.c_str());
			//CQ_sendPrivateMsg(authCode, 956237586, t.c_str());
		}
		
		delete res;
		delete stmt;
		delete conn;

	} catch (sql::SQLException &e) {
		//有异常的情况下，输出异常  
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line "
			<< __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;

	}

}