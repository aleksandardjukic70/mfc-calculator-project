#pragma once
#include <afxwin.h> 

#define exportClass __declspec(dllexport)

class exportClass CMathOperationsFunctions
{

public:
	int leftNumber;
	int rightNumber;
	int operation;

	int Addition(CString currentStringValue);
	int Subtraction(CString currentStringValue);
	int Multiplication(CString currentStringValue);
	int Division(CString currentStringValue);


};