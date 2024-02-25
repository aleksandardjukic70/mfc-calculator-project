#pragma once
#include <afxwin.h> 

#define exportClass __declspec(dllexport)

class exportClass CMathOperationsFunctions
{

public:
	int separator;
	CString leftString;
	CString rightString;
	int leftOperand;
	int rightOperand;
	int result;

	int Addition(CString currentStringValue);
	int Subtraction(CString currentStringValue);
	int Multiplication(CString currentStringValue);
	int Division(CString currentStringValue);


};