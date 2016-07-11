#ifndef QQROBOT_DBUTIL_H
#define QQROBOT_DBUTIL_H
#include "public.h"
#include <mysql_connection.h>
#include <driver.h>
#include <statement.h>

#include <resultset.h>
class DBUtil {
private:
	string url;
	string username;
	string password;
	sql::Driver *driver;
	sql::Connection *conn;
	void example();
public:
	//连接数据库
	sql::Connection* getConnection(string url, string username, string password);
	//判断当前是否连接成功
	bool isConnected();
	//切换数据库
	void use(string dbName);
	//关闭数据库
	void close();
	//执行查询sql
	sql::ResultSet* executeQuery(string sql);

	DBUtil();
	~DBUtil();
};

#endif