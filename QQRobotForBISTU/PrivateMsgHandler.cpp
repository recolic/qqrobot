#include "stdafx.h"
#include "PrivateMsgHandler.h"
#include "DBUtil.h"
#include "Util.h"
#include "Robot.h"
#include "GroupMemberInfo.h"
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

		GroupMemberInfo info;
		string infoString(Robot::getGroupMemberInfo(20103153, 294269440, true));
		info.parse(infoString);
		Robot::sendToMaster(infoString);
		char* ret = new char[50];
		sprintf(ret,"%d",info.groupCard);
		Robot::sendToMaster(info.groupCard);

		delete ret;
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