// CMathOperations.h : main header file for the CMathOperations DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CCMathOperationsApp
// See CMathOperations.cpp for the implementation of this class
//

class CCMathOperationsApp : public CWinApp
{
public:
	CCMathOperationsApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
