//////////////////////////////////////////////////////////////////////////
// 星空用户名生成头文件
// 作者:Huanfeng
// 版本:1.1
//////////////////////////////////////////////////////////////////////////
#ifndef _CXKUsername_H_ 
#define _CXKUsername_H_ 
#include <string>
#include<iostream>
#include <unistd.h>
#include "CString.h"

using namespace std;

typedef int INT;
//typedef string CString ;
typedef long long   LONG64;

class CXKUsername
{
public:
	CXKUsername (CString username, INT ver = 18, long lasttimec = 0); 
	CString Realusername();
	long GetLastTimeC();
private:
	INT m_ver;				//星空的版本，V12和V18两种
	long m_lasttimec;		//上次成功的时间处理
	CString m_username;		//原始用户名
	CString m_realusername;	//真正的用户名
	const char* RADIUS;
	const char* LR;
};

#endif // _CXKUsername_H_ 
