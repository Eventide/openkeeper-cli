#ifndef _CString_H_ 
#define  _CString_H_  
#include <string>
#include <iostream>

using namespace std;

class CString :public string
{

public :	
 	CString():string("")
	{}
	CString(string str):string(str)
	{}
	CString(char * ch):string(ch)
	{} 
	CString(const CString &ch):string(ch.c_str())
	{} 
	CString Left(int i);
	int FindOneOf(const string);
};

typedef CString * LPCTSTR;

#endif  //_CString_H_ 
