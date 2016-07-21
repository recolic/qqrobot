#include "stdafx.h"
#include "GroupMsgHandler.h"
#include "Util.h"
#include "Robot.h"
#include "PersonInfo.h"
#include "CQCode.h"
#include "signed.h"
#include <regex>
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
		Signed s(m);
		reply = true;
	}/* else {
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