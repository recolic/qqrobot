#ifndef SIGNED_H
#define SIGNED_H
#include "public.h"
#include "Message.h"

class Signed {
private:
	QQ qq;
	Message& m;
	string reply;
	string lastTime;
	int	maxTimes;
	int score;
	bool exist();
	int insertQQ();
	int initSignRecord();
	int updateRecord();
	int getTimes();//获取今天次序
	bool isFirstSigned();
	void success();
public:
	int sign();
	Signed(Message& mm);
	~Signed();
};

#endif // !SIGNED_H

