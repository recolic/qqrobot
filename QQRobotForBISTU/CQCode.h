/*
CREATE BY LZ
*/


#ifndef QQROBOT_CQCODE_H
#define QQROBOT_CQCODE_H

#include "public.h"
#include <iostream>
class CQCode
{
private:
	string ret;
	string format;
	string typeOfMusic;
	string fileName;
	string url;
	QQ qq;
	int value;
	bool magic;
	string generateForAt();
	string generateForRecord();
	string generateForImage();
	string generateForInt();
	string generateForMusic();
	string generateForRich();
	string trans(string str);
	void stringReplace(string & str, const string & strSrc, const string &strDst);
	CQCode();
	CQCode(int type, int value);
	CQCode(QQ qq);
	CQCode(string fileName);
	CQCode(string fileName, bool magic);
	CQCode(string typeOfMusic, int value);
	CQCode(string url, string fileName);
	~CQCode();
public:
	static const int FACETYPE_COMMON = 1;
	static const int FACETYPE_EMOJI = 2;
	static const int FACETYPE_BFACE = 3;
	static const int FACETYPE_SFACE = 4;
	static const int FACETYPE_RPS = 5;
	static const int FACETYPE_DICE = 6;
	static string at(QQ qq);
	static string face(int type, int value);
	static string image(string fileName);
	static string record(string fileName,bool magic);
	static string shareMusic(string typeOfMusic, int value);
	static string shareUrl(string url, string fileName);
};
#endif
