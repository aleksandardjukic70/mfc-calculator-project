#pragma once
#include <afxwin.h> 

#define exportClass __declspec(dllexport)

class exportClass CMathOperationsFunctions
{

public:

	int leftNumber;
	int rightNumber;
	int operation;

	// member function
	int MathOperation(CString currentStringValue, CString m_operator);

};