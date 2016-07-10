#ifndef PRIVATE_MSG_HANDLER_H
#define PRIVATE_MSG_HANDLER_H
#include "MsgHandler.h"

class PrivateMsgHandler :
	public MsgHandler {
public:
	PrivateMsgHandler();
	PrivateMsgHandler(int authCode);
	~PrivateMsgHandler();
	int32_t handle(Message* m);
private:
	void test();
};

#endif // !PRIVATE_MSG_HANDLER_H