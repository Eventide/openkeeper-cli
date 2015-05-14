//////////////////////////////////////////////////////////////////////////
// 星空用户名生成实现文件
// 作者:Huanfeng
// 版本:1.1
//////////////////////////////////////////////////////////////////////////

#include "CXKUsername.h"
#include "MD5.h"
#include<cstring>

CXKUsername::CXKUsername(CString username, INT ver, long lasttimec)
:m_username(username),RADIUS("cqxinliradius002"),LR("\r\n")
{
	m_ver = ver;
	m_lasttimec = lasttimec;
}

long CXKUsername::GetLastTimeC()
{
	return m_lasttimec;
}
CString CXKUsername::Realusername()
{
	time_t m_time;						//得到系统时间，从1970.01.01.00:00:00 开始的秒数
	long m_time1c;						//时间初处理m_time1c为结果,经过时间计算出的第一次加密
	long m_time1convert;				//对时间操作后的结果，此为格式字串的原始数据
	unsigned char ss[4] =
	{
		0,0,0,0
	};		//源数据1,对m_time1convert进行计算得到格式符源数据
	unsigned char ss2[4] =
	{
		0,0,0,0
	};		//md5加密参数的一部分,m_time1c的字符形式
	CString strS1;						//md5加密参数的一部分,ss2的整体形式
	CString m_formatsring;				//由m_timece算出的字符串,一般为可视字符
	CString m_md5;						//对初加密(m_timec字符串表示+m_username+radius)的MD5加密
	CString m_md5use;					//md5 Lower模式的前两位



	//取得系统时间m_time
	time(&m_time);
	//时间初处理m_time1c为结果,经过时间计算出的第一次加密
	//子函数////////////////////////////
	{
		LONG64 t;
		t = m_time;
		t *= 0x66666667;
		t >>= 0x20;
		t >>= 0x01;
		m_time1c = (long) t;
	}
	//5秒内动态用户名一致处理
	if (m_time1c <= m_lasttimec)
	{
		m_time1c = m_lasttimec + 1;
	}
	m_lasttimec = m_time1c;
	{
		long t;
		t = m_time1c;
		ss2[3] = (t & 0xFF);
		ss2[2] = (t & 0xFF00) / 0x100  ;
		ss2[1] = (t & 0xFF0000) / 0x10000;
		ss2[0] = (t & 0xFF000000) / 0x1000000;
		{
			//strS1必须用自加得到，真接加出问题
			for (int i = 0; i < 4; i++)
			{
				strS1 += ss2[i];
			}
		}
	}

	/////////////////////////////////////
	//倒置过程m_time1convert为结果
	//子函数////////////////////////////
	{
		int t, t1, t2, t3;
		t = m_time1c;
		t1 = t;
		t2 = t;
		t3 = t;
		t3 = t3 << 0x10;
		t1 = t1 & 0x0FF00;
		t1 = t1 | t3;
		t3 = t;
		t3 = t3 & 0x0FF0000;
		t2 = t2 >> 0x10;
		t3 = t3 | t2;
		t1 = t1 << 0x08;
		t3 = t3 >> 0x08;
		t1 = t1 | t3;
		m_time1convert = t1;
	}
	/////////////////////////////////////

	//源数据1,对m_time1convert进行计算得到格式符源数据
	//子函数////////////////////////////
	{
		long t;
		t = m_time1convert;
		ss[3] = (t & 0xFF);
		ss[2] = (t & 0xFF00) / 0x100  ;
		ss[1] = (t & 0xFF0000) / 0x10000;
		ss[0] = (t & 0xFF000000) / 0x1000000;
	}
	/////////////////////////////////////

	//格式符初加密
	unsigned char pp[4] =
	{
		0,0,0,0
	};
	//子函数////////////////////////////
	{
		int i = 0, j = 0, k = 0;
		for (i = 0; i < 0x20; i++)
		{
			j = i / 0x8;
			k = 3 - (i % 0x4);
			pp[k] *= 0x2;
			if (ss[j] % 2 == 1)
			{
				pp[k]++;
			}
			ss[j] /= 2;
		}
	}
	/////////////////////////////////////
	//格式符计算,m_formatsring为结果
	unsigned char pf[6] =
	{
		0,0,0,0,0,0
	};
	//子函数////////////////////////////
	{
	if(sizeof(int)==2){
		int t1, t2;
		t1 = pp[3];
		t1 /= 0x4;
		pf[0] = t1;
		t1 = pp[3];
		t1 = t1 & 0x3;
		t1 *= 0x10;
		pf[1] = t1;
		t2 = pp[2];
		t2 /= 0x10;
		t2 = t2 | t1;
		pf[1] = t2;
		t1 = pp[2];
		t1 = t1 & 0x0F;
		t1 *= 0x04;
		pf[2] = t1;
		t2 = pp[1];
		t2 /= 0x40;
		t2 = t2 | t1;
		pf[2] = t2;
		t1 = pp[1];
		t1 = t1 & 0x3F;
		pf[3] = t1;
		t2 = pp[0];
		t2 /= 0x04;
		pf[4] = t2;
		t1 = pp[0];
		t1 = t1 & 0x03;
		t1 *= 0x10;
		pf[5] = t1;
		}
	else{
	        short t1,t2 ;
		t1 = pp[3];
		t1 /= 0x4;
		pf[0] = t1;
		t1 = pp[3];
		t1 = t1 & 0x3;
		t1 *= 0x10;
		pf[1] = t1;
		t2 = pp[2];
		t2 /= 0x10;
		t2 = t2 | t1;
		pf[1] = t2;
		t1 = pp[2];
		t1 = t1 & 0x0F;
		t1 *= 0x04;
		pf[2] = t1;
		t2 = pp[1];
		t2 /= 0x40;
		t2 = t2 | t1;
		pf[2] = t2;
		t1 = pp[1];
		t1 = t1 & 0x3F;
		pf[3] = t1;
		t2 = pp[0];
		t2 /= 0x04;
		pf[4] = t2;
		t1 = pp[0];
		t1 = t1 & 0x03;
		t1 *= 0x10;
		pf[5] = t1;
		}
	}
	/////////////////////////////////////
	{
		int i;
		for (i = 0; i < 6; i++)
		{
			pf[i] += 0x20;
			if ((pf[i]) >= 0x40)
			{
				pf[i]++;
			}
		}
	}
	{
		for (int i = 0; i < 6; i++)
		{
			m_formatsring += pf[i];
		}
	}
	/////////////////////////////////////


	CString strInput;
	char temp[100];
	strInput = strS1 + m_username.Left(m_username.FindOneOf("@")) + RADIUS;
	strcpy(temp,strInput.c_str());
	m_md5 = MD5String(temp);
	m_md5use = m_md5.Left(2);
	m_realusername = m_formatsring + m_md5use + m_username;
	m_realusername = LR + m_realusername;//前面两位为回车换行0D0A,接着再是后续的

//#define _debug	
#ifdef _debug
cout<<"m_username.FindOneOf(\"@\"):"<<m_username.FindOneOf("@")<<endl;	
cout<<"sizeof(int):"<<sizeof(int)<<",m_formatsring:"<<m_formatsring<<endl<<"temp:"<<temp<<",m_md5:"<<m_md5<<endl<<"m_realusername:"<<m_realusername<<", m_md5use:"<< m_md5use<<endl;
#endif
	return m_realusername;
}


