#include "stdafx.h"
#include "GroupMsgHandler.h"
#include "Util.h"
#include "Robot.h"
#include "PersonInfo.h"

GroupMsgHandler::GroupMsgHandler() {
}

GroupMsgHandler::~GroupMsgHandler() {
}

int32_t GroupMsgHandler::handle(Message& m) {
	bool reply = false;
	if (m.isFromMaster()) {
		//Robot::sendGroupMsg(m.fromGroup, "hi master~");
		//Robot::addLog(CQLOG_INFOSEND, "test", "hi~master~~");
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