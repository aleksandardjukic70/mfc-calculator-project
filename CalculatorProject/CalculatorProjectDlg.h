
// CalculatorProjectDlg.h : header file
//

#pragma once
#include <afxwin.h>
#include <afxbutton.h>
#include "../CMathOperations/CMathOperationsFunctions.h"


// CCalculatorProjectDlg dialog
class CCalculatorProjectDlg : public CDialogEx
{
// Construction
public:
	CCalculatorProjectDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATORPROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

	CString m_currentStringValue;
	CString m_operator;
	CString m_resultStringValue;
	CString m_result;
	CMathOperationsFunctions m_operation;
	int m_calculationValue;

	CRegKey m_regKey;
	CString m_keyPath = L"SOFTWARE\\CalculatorApplication";
	LONG result{};
	DWORD m_value;

	CEdit m_editStringControl;

	CMFCButton m_button0;
	CMFCButton m_button1;
	CMFCButton m_button2;
	CMFCButton m_button3;
	CMFCButton m_button4;
	CMFCButton m_button5;
	CMFCButton m_button6;
	CMFCButton m_button7;
	CMFCButton m_button8;
	CMFCButton m_button9;
	CMFCButton m_buttonDecimal;
	CMFCButton m_buttonClear;
	CMFCButton m_buttonAddition;
	CMFCButton m_buttonSubtraction;
	CMFCButton m_buttonMultiplication;
	CMFCButton m_buttonDivision;
	CMFCButton m_buttonEquals;

	afx_msg void OnBnClickedButtonZero();
	afx_msg void OnBnClickedButtonOne();
	afx_msg void OnBnClickedButtonTwo();
	afx_msg void OnBnClickedButtonThree();
	afx_msg void OnBnClickedButtonFour();
	afx_msg void OnBnClickedButtonFive();
	afx_msg void OnBnClickedButtonSix();
	afx_msg void OnBnClickedButtonSeven();
	afx_msg void OnBnClickedButtonEight();
	afx_msg void OnBnClickedButtonNine();
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnBnClickedButtonDecimal();
	afx_msg void OnBnClickedButtonAddition();
	afx_msg void OnBnClickedButtonSubtraction();
	afx_msg void OnBnClickedButtonMultiplication();
	afx_msg void OnBnClickedButtonDivision();
	afx_msg void OnBnClickedButtonEquals();
	afx_msg void ButtonFunction(CString m_operator);
	afx_msg void ResultFunction(CString m_currentStringValue, CString m_operator);

	afx_msg void RegKeyBtnStyleSwitch(DWORD useCButton);
	afx_msg void ApplyButtonStyleZero(CButton& button);
	afx_msg void ApplyButtonStyleOne(CMFCButton& button);
};



