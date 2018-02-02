// testDll.cpp : 定义控制台应用程序的入口点。
//

#include "mclmcrrt.h"
#include "mclmcr.h"
#include "matrix.h"
#include "mclcppclass.h"
#include "mydllAdd.h"               // *.m文件生成
#include <stdio.h>   
#include <iostream>   


using namespace std;
int main()
{
	double a;
	double b;
	double c;
	// initialize lib，这里必须做初始化！   
	if (!mydllAddInitialize())
	{//若失败执行
		cout << "Could not initialize mydllAdd!" << endl;
	}
	cout << "请输入a:" << endl;
	cin >> a;
	cout << "请输入b:" << endl;
	cin >> b;
	// 为变量分配内存空间，可以查帮助mwArray   文章附件有链接
	mwArray mwA(1, 1, mxDOUBLE_CLASS); // 1，1表示矩阵的大小（所有maltab只有一种变量，就是矩阵，为了和Cpp变量接轨，设置成1*1的矩阵，mxDOUBLE_CLASS表示变量的精度）   
	mwArray mwB(1, 1, mxDOUBLE_CLASS);
	mwArray mwC(1, 1, mxDOUBLE_CLASS);

	// set data 调用类里面的SetData函数给类赋值   
	mwA.SetData(&a, 1);
	mwB.SetData(&b, 1);
	// using my add，调用动态库里 写的函数   
	Add(1, mwC, mwA, mwB);
	// get data 调用类里面的Get函数获取取函数返回值   
	c = mwC.Get(1, 1);
	cout << "c=a+b=" << c << endl;

	// 后面是一些终止调用的程序   
	// terminate the lib   
	mydllAddTerminate();
	// terminate MCR   
	mclTerminateApplication();
	getchar();
	return 0;
}