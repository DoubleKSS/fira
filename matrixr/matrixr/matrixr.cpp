// matrixr.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <iomanip>

#include "engine.h"   // ʹ��VC++��Matlab�����ϱ�̾ͱ�������ͷ�ļ�,�����������<matrix.h>
#include <string.h>
using namespace std;
#pragma comment(lib, "libmat.lib")
#pragma comment(lib, "libmx.lib")
#pragma comment(lib, "libeng.lib")
void main()
{
	// ����ѭ������
	int i = 0, j = 0;
	// ״̬����
	int nStatus = 0;
	// ����MATLAB����ָ��
	Engine *ep;
	// ����mxArray����ָ��
	mxArray *A, *B;
	// �����������, ע�⣺VC�о�������д�����MATLAB�����෴����Ҫת��
	double arData[3][3] = { { 7.5, 16.3, 9.6 }, { 13.2, 8.9, 12.3 }, { 9.6, 5.4, 13.7 } };
	double arResData[3][3];
	// ���ԭ����
	cout << "ԭ����Ϊ��" << endl;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			cout << setw(10) << arData[i][j] << " ";
		}
		cout << endl;
	}
	// ��MATLAB����
	ep = engOpen(NULL);        // ��Windowsϵͳ�иú����Ĳ�����Ϊ��NULL����
	if (ep == NULL)
	{
		cout << "�޷���MATLAB���档" << endl;
		exit(EXIT_FAILURE);
	}
	// �Ƿ���ʾMATLAB���ڣ�true-��ʾ��false-���ء�
	nStatus = engSetVisible(ep, true);           // ��Ϊture����ʱҲֻ��һ������
	//nStatus = engSetVisible(ep, true);
	if (nStatus != 0)
	{
		cout << "����MATLAB��ʾ����ʧ�ܡ�" << endl;
		exit(EXIT_FAILURE);
	}
	// ΪmxArray��������ռ�
	A = mxCreateDoubleMatrix(3, 3, mxREAL);
	B = mxCreateDoubleMatrix(3, 3, mxREAL);
	if (A == NULL || B == NULL)
	{
		cout << "ΪmxArray��������ռ�ʧ�ܡ�" << endl;
		exit(EXIT_FAILURE);
	}
	// �������е�����д�뵽mxArray�ռ���
	memcpy((void*)mxGetPr(A), (void*)arData, sizeof(arData));    // ʹ���ڴ����ݸ��ƺ���memcpy���и���
	// ���������Aд�뵽MATLAB����ռ�
	nStatus = engPutVariable(ep, "A", A);
	if (nStatus != 0)
	{
		cout << "�������д��MATLAB����ռ�ʧ�ܡ�" << endl;
		exit(EXIT_FAILURE);
	}
	// ִ���������������A�������
	nStatus = engEvalString(ep, "B=inv(A)");   // B=inv(A)ΪҪ��MATLAB�����е��������
	if (nStatus != 0)
	{
		cout << "ִ��MATLAB��������ʧ�ܡ�" << endl;
		exit(EXIT_FAILURE);
	}
	// ��MATLAB����ռ��ж�ȡִ�н��
	B = engGetVariable(ep, "B");
	// ���������B���Ƶ�����arResData��
	memcpy((void*)arResData, (void*)mxGetPr(B), sizeof(arResData));
	// �ͷž�������ռ�
	mxDestroyArray(A);
	mxDestroyArray(B);
	// ���������
	cout << "�����Ϊ��" << endl;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			cout << setw(10) << arResData[i][j] << " ";
		}
		cout << endl;
	}
	// ��ͣ���򣬲鿴���
	system("pause");
	// �ر�MATLAB����
	engClose(ep);
}