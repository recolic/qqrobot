#ifndef ROBOT_H
#define ROBOT_H
#include "public.h"
#include "Message.h"
#include "MsgHandler.h"
#include "PrivateMsgHandler.h"
#include "GroupMsgHandler.h"

class Robot {
private:
	int authCode;//授权码
	bool enabled;//是否开启
	int64_t masterQQ;
	MsgHandler * privateMsgHandler;
	MsgHandler * groupMsgHandler;
	//测试函数
	void test();
public:
	//构造函数
	Robot();
	//设置授权码
	void setAuthCode(int ac);
	//开关
	void enable();
	void disable();
	//状态判断
	bool isEnabled();
	//处理消息
	int32_t handleMsg(Message* m);
	//析构函数
	~Robot();
};
#undef DLLCLASS
#endif

