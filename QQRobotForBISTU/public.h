// 通过宏来控制是导入还是导出
//#ifdef _DLLCLASS
//#define DLLCLASS __declspec(dllexport)
//#else
//#define DLLCLASS __declspec(dllimport)
//#endif
//共用的头文件
#include <string>
#include <sstream>
#include "cqp.h"
#ifndef QQ
typedef int64_t QQ;
typedef int64_t GroupId;
#endif
using namespace std;