#include "stdafx.h"
#include "GroupMsgHandler.h"
#include "Util.h"
#include "Robot.h"

GroupMsgHandler::GroupMsgHandler() {
}

GroupMsgHandler::~GroupMsgHandler() {
}

int32_t GroupMsgHandler::handle(Message& m) {
	bool reply = false;
	//CQ_sendPrivateMsg(authCode, Util::getMasterQQ(), m->content);
	if (m.fromQQ == Util::getMasterQQ()) {
		Robot::sendGroupMsg(m.fromGroup, "hi master~");
		Robot::addLog(CQLOG_INFOSEND, "test", "hi~master~~");
	}
	reply = true;
	if (reply) {
		return EVENT_BLOCK;
	} else {
		return EVENT_IGNORE;
	}

}
