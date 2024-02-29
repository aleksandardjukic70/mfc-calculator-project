#pragma once
#include <afxwin.h> 

#define exportClass __declspec(dllexport)

class exportClass CMathOperationsFunctions
{

public:

	double leftNumber;
	double rightNumber;
	double operation;

	// member function
	double MathOperation(double leftNumber, double rightNumber, TCHAR m_operator);

};