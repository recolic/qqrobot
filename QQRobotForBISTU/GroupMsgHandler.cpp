#include "stdafx.h"
#include "GroupMsgHandler.h"
#include "Util.h"

GroupMsgHandler::GroupMsgHandler() {
}

GroupMsgHandler::GroupMsgHandler(int authCode) {
	this->authCode = authCode;
}


GroupMsgHandler::~GroupMsgHandler() {
}

int32_t GroupMsgHandler::handle(Message *m) {
	bool reply = false;
	//CQ_sendPrivateMsg(authCode, Util::getMasterQQ(), m->content);
	if (m->fromQQ == Util::getMasterQQ()) {
		CQ_sendGroupMsg(authCode, m->fromGroup, "hi master~");
		CQ_addLog(authCode, CQLOG_INFOSEND, "test", "hi~master~~");
	}
	reply = true;
	if (reply) {
		return EVENT_BLOCK;
	} else {
		return EVENT_IGNORE;
	}

}
