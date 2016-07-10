#ifndef MSG_HANDLER
#define MSG_HANDLER
#include "public.h"
#include "Message.h"

class MsgHandler {
public:
	MsgHandler();
	virtual int32_t  handle(Message* m);
	void setAuthCode(int authCode);
protected:
	Message * m;
	int authCode;
};
#endif
