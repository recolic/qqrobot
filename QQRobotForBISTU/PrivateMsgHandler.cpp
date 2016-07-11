#include "stdafx.h"
#include "PrivateMsgHandler.h"
#include "DBUtil.h"
#include "Util.h"
#include "Robot.h"
//--------------test log ------------------

//--------------test log ------------------
PrivateMsgHandler::PrivateMsgHandler() {

}

PrivateMsgHandler::~PrivateMsgHandler() {

}

int32_t PrivateMsgHandler::handle(Message& m) {
	bool reply = false;

	//DBUtil db;
	//if (!db.isConnected()) {
	//	//error
	//	return EVENT_IGNORE;
	//}
	//db.use("test");

	//sql::ResultSet* res = db.executeQuery("select * from testtable");
	//if (res == NULL) {
	//	//erroe
	//	return EVENT_IGNORE;
	//}

	//while (res->next()) {
	//	string t = "";
	//	int id = res->getInt("id");
	//	char buffer[10] = { 0 };
	//	sprintf(buffer, "%d", id);
	//	t += buffer;
	//	t += "   ";
	//	t += res->getString("user");
	if (m.fromQQ == Util::getMasterQQ()) {
		Robot::sendPrivateMsg(m.fromQQ, m.content);
		test();
	}
	//	Sleep(1000);
	reply = true;
	if (reply){
		return EVENT_BLOCK;
	} else{
		return EVENT_IGNORE;
	}
}

void PrivateMsgHandler::test() {
	Robot::sendPrivateMsg(Util::getMasterQQ(), "hi master");
}