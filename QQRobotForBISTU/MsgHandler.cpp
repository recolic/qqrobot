#include "stdafx.h"
#include "MsgHandler.h"

MsgHandler::MsgHandler() {
}

int32_t MsgHandler::handle(Message* m) {
	return 0;
}

void MsgHandler::setAuthCode(int authCode) {
	this->authCode = authCode;
}
