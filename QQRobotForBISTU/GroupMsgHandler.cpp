#include "stdafx.h"
#include "GroupMsgHandler.h"
#include "Util.h"
#include "Robot.h"
#include "PersonInfo.h"
#include "CQCode.h"
GroupMsgHandler::GroupMsgHandler() {
}

GroupMsgHandler::~GroupMsgHandler() {
}

int32_t GroupMsgHandler::handle(Message& m) {
	bool reply = false;
	if (m.isFromMaster()) {
		//Robot::sendGroupMsg(m.fromGroup, "hi master~");
		//Robot::addLog(CQLOG_INFOSEND, "test", "hi~master~~");
		//string str = CQCode::image("0A535B0E538FFAE8A1AA6AEF7CA61F6C.jpg.cqimg");
		//Robot::sendGroupMsg(m.fromGroup, Util::getWelComeMsg());
		//Robot::addLog(CQLOG_INFOSEND, "test",str);
	}
	test();
	reply = true;
	if (reply) {
		return EVENT_BLOCK;
	} else {
		return EVENT_IGNORE;
	}

}

void GroupMsgHandler::test() {
	
}