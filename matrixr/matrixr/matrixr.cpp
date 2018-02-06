// matrixr.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <iomanip>

#include "engine.h"   // 使用VC++和Matlab引擎混合编程就必须加这个头文件,它里面包含了<matrix.h>
#include <string.h>
using namespace std;
#pragma comment(lib, "libmat.lib")
#pragma comment(lib, "libmx.lib")
#pragma comment(lib, "libeng.lib")
void main()
{
	// 定义循环变量
	int i = 0, j = 0;
	// 状态变量
	int nStatus = 0;
	// 定义MATLAB引擎指针
	Engine *ep;
	// 定义mxArray变量指针
	mxArray *A, *B;
	// 定义矩阵数组, 注意：VC中矩阵的行列次序与MATLAB正好相反，需要转置
	double arData[3][3] = { { 7.5, 16.3, 9.6 }, { 13.2, 8.9, 12.3 }, { 9.6, 5.4, 13.7 } };
	double arResData[3][3];
	// 输出原矩阵
	cout << "原矩阵为：" << endl;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			cout << setw(10) << arData[i][j] << " ";
		}
		cout << endl;
	}
	// 打开MATLAB引擎
	ep = engOpen(NULL);        // 在Windows系统中该函数的参数都为“NULL”。
	if (ep == NULL)
	{
		cout << "无法打开MATLAB引擎。" << endl;
		exit(EXIT_FAILURE);
	}
	// 是否显示MATLAB窗口：true-显示；false-隐藏。
	nStatus = engSetVisible(ep, true);           // 设为ture运行时也只是一闪而过
	//nStatus = engSetVisible(ep, true);
	if (nStatus != 0)
	{
		cout << "设置MATLAB显示属性失败。" << endl;
		exit(EXIT_FAILURE);
	}
	// 为mxArray变量分配空间
	A = mxCreateDoubleMatrix(3, 3, mxREAL);
	B = mxCreateDoubleMatrix(3, 3, mxREAL);
	if (A == NULL || B == NULL)
	{
		cout << "为mxArray变量分配空间失败。" << endl;
		exit(EXIT_FAILURE);
	}
	// 将数组中的数据写入到mxArray空间中
	memcpy((void*)mxGetPr(A), (void*)arData, sizeof(arData));    // 使用内存数据复制函数memcpy进行复制
	// 将矩阵变量A写入到MATLAB引擎空间
	nStatus = engPutVariable(ep, "A", A);
	if (nStatus != 0)
	{
		cout << "矩阵变量写入MATLAB引擎空间失败。" << endl;
		exit(EXIT_FAILURE);
	}
	// 执行引擎命令求矩阵A的逆矩阵
	nStatus = engEvalString(ep, "B=inv(A)");   // B=inv(A)为要在MATLAB中运行的命令参数
	if (nStatus != 0)
	{
		cout << "执行MATLAB引擎命令失败。" << endl;
		exit(EXIT_FAILURE);
	}
	// 从MATLAB引擎空间中读取执行结果
	B = engGetVariable(ep, "B");
	// 将矩阵变量B复制到数组arResData中
	memcpy((void*)arResData, (void*)mxGetPr(B), sizeof(arResData));
	// 释放矩阵变量空间
	mxDestroyArray(A);
	mxDestroyArray(B);
	// 输出计算结果
	cout << "逆矩阵为：" << endl;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			cout << setw(10) << arResData[i][j] << " ";
		}
		cout << endl;
	}
	// 暂停程序，查看结果
	system("pause");
	// 关闭MATLAB引擎
	engClose(ep);
}