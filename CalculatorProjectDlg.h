
// CalculatorProjectDlg.h : header file
//

#pragma once
#include <afxwin.h>


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
	CButton* CreateButton(int staticId, int buttonId);
public:

	CEdit m_editStringControl;
	CString m_currentStringValue;
	CString buttonValue;
	//CEdit m_groupBoxStringValue;

	CRegKey m_regKey;
	CString m_keyPath = L"SOFTWARE\\CalculatorApplication";
	LONG result{};

	CButton m_button0;
	CButton m_button1;
	CButton m_button2;
	CButton m_button3;
	CButton m_button4;
	CButton m_button5;
	CButton m_button6;
	CButton m_button7;
	CButton m_button8;
	CButton m_button9;
	CButton m_buttonDecimal;
	CButton m_buttonClear;
	CButton m_buttonAddition;
	CButton m_buttonSubtraction;
	CButton m_buttonMultiplication;
	CButton m_buttonDivision;
	CButton m_buttonEquals;

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
	afx_msg void CreateRegistryKey();
	//afx_msg void ChangeGroupBoxName();
};
