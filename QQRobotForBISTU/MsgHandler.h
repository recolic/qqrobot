#ifndef QQROBOT_MSG_HANDLER
#define QQROBOT_MSG_HANDLER
#include "public.h"
#include "Message.h"

class MsgHandler {
public:
	MsgHandler();
	virtual int32_t  handle(Message& m);
protected:
	Message * m;
};
#endif
