#ifndef SIGNED_H
#define SIGNED_H
#include "public.h"
#include "Message.h"
#include "DBUtil.h"
class Signed {
private:
	QQ qq;
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
	static DBUtil db;
	bool existQQ(QQ qq);
	int getScore(QQ qq);
	int sign(Message& m);
	Signed();
	Signed(Message& mm);
	~Signed();
};

#endif // !SIGNED_H

