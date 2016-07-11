#ifndef QQROBOT_MESSAGE_H
#define QQROBOT_MESSAGE_H
#include "public.h"
class Message {
public:
	Message();
	Message(int32_t subType, int32_t sendTime, QQ fromQQ, const char *content, int32_t font);
	Message(int32_t subType, int32_t sendTime, GroupId fromGroup, QQ fromQQ, const char *fromAnonymous, const char *content, int32_t font);
	~Message();
	int msgType;//0私聊,1群聊
	//subType 子类型，
	//11 / 来自好友 
	//1 / 来自在线状态 
	//2 / 来自群 
	//3 / 来自讨论组
	int32_t subType; 
	int32_t sendTime;
	GroupId fromGroup;
	QQ fromQQ;
	const char *fromAnonymous;
	const char *content;
	int32_t font;
};

#endif // !MESSAGE_H