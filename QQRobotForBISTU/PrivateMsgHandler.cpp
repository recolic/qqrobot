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
	if (m.fromQQ == Util::getMasterQQ()) {
		//test();
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