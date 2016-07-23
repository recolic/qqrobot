#include "stdafx.h"
#include "CQCode.h"


CQCode::CQCode() {
}

CQCode::CQCode(int type, int value) {
	this->value = value;
	if (type == 1)
		this->format = "[CQ:face,id=";
	else if (type == 2)
		this->format = "[CQ:emoji,id=";
	else if (type == 3)
		this->format = "[CQ:bface,id=";
	else if (type == 4)
		this->format = "[CQ:sface,id=";
	else if (type == 5)
		this->format = "[CQ:rps,type=";
	else if (type == 6)
		this->format = "[CQ:dice,type=";

}

CQCode::CQCode(QQ qq) {
	this->qq = qq;
	this->format = this->format = "[CQ:at,qq=";
}

CQCode::CQCode(string fileName) {
	this->format = "[CQ:image,file=";
	this->fileName = trans(fileName);
}

CQCode::CQCode(string fileName, bool magic) {
	this->fileName = trans(fileName);
	this->magic = magic;
	if (magic == 1)
		this->format = "[CQ:record,file=";
	else
		this->format = "[CQ:record,file=";
}

CQCode::CQCode(string typeOfMusic, int value) {
	this->typeOfMusic = trans(typeOfMusic);
	this->value = value;
	this->format = "[CQ:music,type=";
}

CQCode::CQCode(string url, string fileName) {
	this->url = trans(url);
	this->fileName = trans(fileName);
	format = "[CQ:share,url=";
}


CQCode::~CQCode() {
}

string CQCode::generateForAt() {
	char* buff = new char[20];
	sprintf(buff, "%u", qq & 0xFFFFFFFF);
	ret += format;
	ret.append(string(buff));
	ret += "]";
	delete buff;
	return ret;
}

string CQCode::generateForRecord() {
	if (magic == 1)
		ret = format + fileName + ",magic=true]";
	else
		ret = format + fileName + ",magic=false]";
	return ret;
}

string CQCode::generateForImage() {
	ret = format + fileName + "]";
	return ret;
}

string CQCode::generateForInt() {
	char* buff = new char[20];
	sprintf(buff, "%d", value);
	ret += format;
	ret.append(string(buff));
	ret += "]";
	delete buff;
	return ret;
}

string CQCode::generateForMusic() {
	string newValue = "" + value;
	ret = format + typeOfMusic + ",id=" + newValue + "]";
}

string CQCode::generateForRich() {
	ret = format + url + ",text=" + fileName + "]";
	return ret;
}

string CQCode::trans(string str) {
	stringReplace(str, "&", "&amp;");
	stringReplace(str, "[", "&#91;");
	stringReplace(str, "]", "&#93;");
	stringReplace(str, ",", "&#44;");
	return str;
}

string CQCode::at(QQ qq) {
	return CQCode(qq).generateForAt();
}

string CQCode::face(int type, int value) {
	return CQCode(type, value).generateForInt();
}

string CQCode::image(string fileName) {
	return CQCode(fileName).generateForImage();
}

string CQCode::record(string fileName, bool magic) {
	return CQCode(fileName,magic).generateForRecord();
}

string CQCode::shareMusic(string typeOfMusic, int value) {
	return CQCode(typeOfMusic,value).generateForMusic();
}

string CQCode::shareUrl(string url, string fileName) {
	return CQCode(url,fileName).generateForRich();
}

void CQCode::stringReplace(string & str, const string & strSrc, const string & strDst) {
	string::size_type pos = 0;
	string::size_type srcLen = strSrc.size();
	string::size_type dstLen = strDst.size();
	while ((pos = str.find(strSrc, pos)) != string::npos) {
		str.replace(pos, srcLen, strDst);
		pos += dstLen;
	}
}