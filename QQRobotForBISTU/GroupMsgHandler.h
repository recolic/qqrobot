#ifndef QQROBOT_GROUP_MSG_HANDLER_H
#define QQROBOT_GROUP_MSG_HANDLER_H
#include "MsgHandler.h"
#include "signed.h"
#include <regex>
#include <map>
class GroupMsgHandler :
	public MsgHandler {
private:
	void test();
	static map<GroupId, int> count;
	static map<GroupId, int> nextInt;
	static regex patternCard;
	static regex pattern;
	static DBUtil db;
public:
	GroupMsgHandler();
	~GroupMsgHandler();
	int32_t handle(Message& m);
};

#endif // !GROUP_MSG_HANDLER_H
