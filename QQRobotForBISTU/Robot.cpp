#include "stdafx.h"
#include "Robot.h"
#include "DBUtil.h"
#include "Util.h"

using namespace std;
Robot::Robot() {
	privateMsgHandler = new PrivateMsgHandler(authCode);
	groupMsgHandler = new GroupMsgHandler(authCode);
}

void Robot::setAuthCode(int ac) {
	this->authCode = ac;
	privateMsgHandler->setAuthCode(ac);
	groupMsgHandler->setAuthCode(ac);
}

void Robot::enable() {
	this->enabled = true;
}

void Robot::disable() {
	this->enabled = false;
}

bool Robot::isEnabled() {
	return enabled;
}

int32_t Robot::handleMsg(Message * m) {
	int32_t ret = 0;
	switch (m->msgType) {
	case 0: 
		//CQ_addLog(authCode, CQLOG_INFORECV, "↓private", msg);
		ret = privateMsgHandler->handle(m); 
		break;//私聊
	case 1: 
		//CQ_addLog(authCode, CQLOG_INFORECV, "↓group", m->msg);
		ret = groupMsgHandler->handle(m); 
		break;//群聊
	default: break;
	}
	return ret;
	//如果要回复消息，请调用酷Q方法发送，并且这里 return EVENT_BLOCK - 截断本条消息，不再继续处理  注意：应用优先级设置为"最高"(10000)时，不得使用本返回值
	//如果不回复消息，交由之后的应用/过滤器处理，这里 return EVENT_IGNORE - 忽略本条消息
}

Robot::~Robot() {
	delete privateMsgHandler;
	delete groupMsgHandler;
}

