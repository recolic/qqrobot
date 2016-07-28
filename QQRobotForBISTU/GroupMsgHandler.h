#ifndef QQROBOT_GROUP_MSG_HANDLER_H
#define QQROBOT_GROUP_MSG_HANDLER_H
#include "MsgHandler.h"
#include "signed.h"
#include <map>
class GroupMsgHandler :
	public MsgHandler {
private:
	void test();
	static map<GroupId, int> count;
public:
	GroupMsgHandler();
	~GroupMsgHandler();
	int32_t handle(Message& m);
};

#endif // !GROUP_MSG_HANDLER_H
