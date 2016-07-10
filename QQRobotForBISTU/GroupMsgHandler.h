#ifndef GROUP_MSG_HANDLER_H
#define GROUP_MSG_HANDLER_H
#include "MsgHandler.h"
class GroupMsgHandler :
	public MsgHandler {
public:
	GroupMsgHandler();
	GroupMsgHandler(int authCode);
	~GroupMsgHandler();
	int32_t handle(Message* m);
};

#endif // !GROUP_MSG_HANDLER_H
