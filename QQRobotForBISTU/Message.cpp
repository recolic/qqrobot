#include "stdafx.h"
#include "Message.h"
#include "Util.h"


Message::Message() {
}

Message::Message(int32_t subType, int32_t sendTime, QQ fromQQ, const char * content, int32_t font) {
	this->msgType = 0;
	this->subType = subType;
	this->sendTime = sendTime;
	this->fromQQ = fromQQ;
	this->content = content;
	this->font = font;
}

Message::Message(int32_t subType, int32_t sendTime, GroupId fromGroup, QQ fromQQ, const char * fromAnonymous, const char * content, int32_t font) {
	this->msgType = 1;
	this->subType = subType;
	this->sendTime = sendTime;
	this->fromGroup = fromGroup;
	this->fromQQ = fromQQ;
	this->fromAnonymous = fromAnonymous;
	this->content = content;
	this->font = font;
}

bool Message::isFromMaster() {
	return fromQQ == Util::getMasterQQ();
}


Message::~Message() {
}
