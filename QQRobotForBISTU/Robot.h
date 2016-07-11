#ifndef QQROBOT_ROBOT_H
#define QQROBOT_ROBOT_H
#include "public.h"
#include "Message.h"
#include "MsgHandler.h"
#include "PrivateMsgHandler.h"
#include "GroupMsgHandler.h"

class Robot {
private:
	static int authCode;//授权码
	bool enabled;//是否开启
	QQ masterQQ;
	MsgHandler * privateMsgHandler;
	MsgHandler * groupMsgHandler;
	//测试函数
	void test();
public:
	//构造函数
	Robot();
	//开关
	void enable();
	void disable();
	//状态判断
	bool isEnabled();
	QQ getMasterQQ();
	//处理消息
	int32_t handleMsg(Message& m);
	//析构函数
	~Robot();
	//设置授权码
	static void setAuthCode(int ac);
	//发送群聊
	static void sendGroupMsg(QQ groupid, const char *msg);
	//发送私聊
	static void sendPrivateMsg(QQ QQID, const char *msg);
	//增加日志记录
	static void addLog(int32_t priority, const char *category, const char *content);
	//点赞
	static void sendLike(QQ QQID);
	//从群里踢出
	static void setGroupKick(GroupId groupid, QQ QQID, CQBOOL isRejectAddRequestAgain);
	//群内禁言
	static void setGroupBan(GroupId groupid, QQ QQID, int64_t duration);
	//设置群管
	static void setGroupAdmin(GroupId groupid, QQ QQID, CQBOOL setAdmin);
	//设置全员禁言
	static void setGroupWholeBan(GroupId groupid, CQBOOL enableBan);
	//匿名禁言
	static void setGroupAnonymousBan(GroupId groupid, const char *anomymous, int64_t duration);
	//设置是否允许匿名
	static void setGroupAnonymous(GroupId groupid, CQBOOL enableAnomymous);
	//发送群卡片
	static void setGroupCard(GroupId groupid, QQ QQID, const char *newCard);
	//退群
	static void setGroupLeave(GroupId groupid, CQBOOL isDismiss);
	//设置一个头衔
	static void setGroupSpecialTitle(GroupId groupid, QQ QQID, const char *newSpecialtitle, int64_t duration);
	//离开讨论组
	static void setDiscussLeave(int64_t discussid);
	//接受好友请求
	static void setFriendAddRequest(const char *responseFlag, int32_t responseOperation, const char *remark);
	//接收加群请求
	static void setGroupAddRequest(const char *responseFlag, int32_t requestType, int32_t responseOperation, const char *reason);


};
#endif

/*
CQAPI(const char *) CQ_getGroupMemberInfoV2(int32_t AuthCode, GroupId groupid, QQ QQID, CQBOOL nocache);
CQAPI(const char *) CQ_getStrangerInfo(int32_t AuthCode, QQ QQID, CQBOOL nocache);
CQAPI(const char *) CQ_getCookies(int32_t AuthCode);
static void getCsrfToken(int32_t AuthCode);
CQAPI(int64_t) CQ_getLoginQQ(int32_t AuthCode);
CQAPI(const char *) CQ_getLoginNick(int32_t AuthCode);
CQAPI(const char *) CQ_getAppDirectory(int32_t AuthCode);
static void setFatal(int32_t AuthCode, const char *errorinfo);
*/
