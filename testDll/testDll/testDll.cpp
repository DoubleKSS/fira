// testDll.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "mclmcrrt.h"
#include "mclmcr.h"
#include "matrix.h"
#include "mclcppclass.h"
#include "mydllAdd.h"               // *.m�ļ�����
#include <stdio.h>   
#include <iostream>   


using namespace std;
int main()
{
	double a;
	double b;
	double c;
	// initialize lib�������������ʼ����   
	if (!mydllAddInitialize())
	{//��ʧ��ִ��
		cout << "Could not initialize mydllAdd!" << endl;
	}
	cout << "������a:" << endl;
	cin >> a;
	cout << "������b:" << endl;
	cin >> b;
	// Ϊ���������ڴ�ռ䣬���Բ����mwArray   ���¸���������
	mwArray mwA(1, 1, mxDOUBLE_CLASS); // 1��1��ʾ����Ĵ�С������maltabֻ��һ�ֱ��������Ǿ���Ϊ�˺�Cpp�����ӹ죬���ó�1*1�ľ���mxDOUBLE_CLASS��ʾ�����ľ��ȣ�   
	mwArray mwB(1, 1, mxDOUBLE_CLASS);
	mwArray mwC(1, 1, mxDOUBLE_CLASS);

	// set data �����������SetData�������ำֵ   
	mwA.SetData(&a, 1);
	mwB.SetData(&b, 1);
	// using my add�����ö�̬���� д�ĺ���   
	Add(1, mwC, mwA, mwB);
	// get data �����������Get������ȡȡ��������ֵ   
	c = mwC.Get(1, 1);
	cout << "c=a+b=" << c << endl;

	// ������һЩ��ֹ���õĳ���   
	// terminate the lib   
	mydllAddTerminate();
	// terminate MCR   
	mclTerminateApplication();
	getchar();
	return 0;
}