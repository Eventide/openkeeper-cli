#include "CString.h"


CString CString::Left(int iPos){
	if(iPos<0)
		iPos = this->size();
  char * tmp = new char[iPos +1];
//int copy(char *s, int n, int pos = 0) const;//把当前串中以pos开始的n个字符拷贝到以s为起始位置的字符数 
  this->copy(tmp,iPos);
  tmp[iPos]='\0';
//  cout<<"left("<<iPos<<"):"<<tmp<<endl;
  CString cs(tmp);
  delete tmp;
  return cs;
}

int CString::FindOneOf(const string s){
//int find(char c, int pos = 0) const;//从pos开始查找字符c在当前字符串的位置
//int find_first_of(char c, int pos = 0) const;//从pos开始查找字符c第一次出现的位置
//int find_first_of(const string &s,int pos = 0) const;
	return  this->find_first_of(s);
}
