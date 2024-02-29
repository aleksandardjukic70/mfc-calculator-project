
// CalculatorProjectDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "CalculatorProject.h"
#include "CalculatorProjectDlg.h"
#include "afxdialogex.h"
#include <afxwin.h> 
#include "../CMathOperations/CMathOperationsFunctions.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#define WM_CUSTOM_ABOUT_BUTTON_CLICKED (WM_USER + 100)

#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
	
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalculatorProjectDlg dialog



CCalculatorProjectDlg::CCalculatorProjectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATORPROJECT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	//	This is the way
	//  ID sa varijablom
	DDX_Control(pDX, IDC_BUTTON_ZERO, m_button0);
	DDX_Control(pDX, IDC_BUTTON_ONE, m_button1);
	DDX_Control(pDX, IDC_BUTTON_TWO, m_button2);
	DDX_Control(pDX, IDC_BUTTON_THREE, m_button3);
	DDX_Control(pDX, IDC_BUTTON_FOUR, m_button4);
	DDX_Control(pDX, IDC_BUTTON_FIVE, m_button5);
	DDX_Control(pDX, IDC_BUTTON_SIX, m_button6);
	DDX_Control(pDX, IDC_BUTTON_SEVEN, m_button7);
	DDX_Control(pDX, IDC_BUTTON_EIGHT, m_button8);
	DDX_Control(pDX, IDC_BUTTON_NINE, m_button9);
	DDX_Control(pDX, IDC_BUTTON_DECIMAL, m_buttonDecimal);
	DDX_Control(pDX, IDC_BUTTON_CLEAR, m_buttonClear);
	DDX_Control(pDX, IDC_BUTTON_ADDITION, m_buttonAddition);
	DDX_Control(pDX, IDC_BUTTON_SUBTRACTION, m_buttonSubtraction);
	DDX_Control(pDX, IDC_BUTTON_MULTIPLICATION, m_buttonMultiplication);
	DDX_Control(pDX, IDC_BUTTON_DIVISION, m_buttonDivision);
	DDX_Control(pDX, IDC_BUTTON_EQUALS, m_buttonEquals);
	DDX_Control(pDX, IDC_EDIT_CONTROL, m_editStringControl);
}

BEGIN_MESSAGE_MAP(CCalculatorProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	// ID sa onclickfunc
	ON_BN_CLICKED(IDC_BUTTON_ZERO, &CCalculatorProjectDlg::OnBnClickedButtonZero)
	ON_BN_CLICKED(IDC_BUTTON_ONE, &CCalculatorProjectDlg::OnBnClickedButtonOne)
	ON_BN_CLICKED(IDC_BUTTON_TWO, &CCalculatorProjectDlg::OnBnClickedButtonTwo)
	ON_BN_CLICKED(IDC_BUTTON_THREE, &CCalculatorProjectDlg::OnBnClickedButtonThree)
	ON_BN_CLICKED(IDC_BUTTON_FOUR, &CCalculatorProjectDlg::OnBnClickedButtonFour)
	ON_BN_CLICKED(IDC_BUTTON_FIVE, &CCalculatorProjectDlg::OnBnClickedButtonFive)
	ON_BN_CLICKED(IDC_BUTTON_SIX, &CCalculatorProjectDlg::OnBnClickedButtonSix)
	ON_BN_CLICKED(IDC_BUTTON_SEVEN, &CCalculatorProjectDlg::OnBnClickedButtonSeven)
	ON_BN_CLICKED(IDC_BUTTON_EIGHT, &CCalculatorProjectDlg::OnBnClickedButtonEight)
	ON_BN_CLICKED(IDC_BUTTON_NINE, &CCalculatorProjectDlg::OnBnClickedButtonNine)
	ON_BN_CLICKED(IDC_BUTTON_DECIMAL, &CCalculatorProjectDlg::OnBnClickedButtonDecimal)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CCalculatorProjectDlg::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_ADDITION, &CCalculatorProjectDlg::OnBnClickedButtonAddition)
	ON_BN_CLICKED(IDC_BUTTON_SUBTRACTION, &CCalculatorProjectDlg::OnBnClickedButtonSubtraction)
	ON_BN_CLICKED(IDC_BUTTON_MULTIPLICATION, &CCalculatorProjectDlg::OnBnClickedButtonMultiplication)
	ON_BN_CLICKED(IDC_BUTTON_DIVISION, &CCalculatorProjectDlg::OnBnClickedButtonDivision)
	ON_BN_CLICKED(IDC_BUTTON_EQUALS, &CCalculatorProjectDlg::OnBnClickedButtonEquals)

END_MESSAGE_MAP()


// CCalculatorProjectDlg message handlers

BOOL CCalculatorProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	RegKeyBtnStyleSwitch(0);

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application"s main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	//m_button4.OnFillBackground()
	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCalculatorProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCalculatorProjectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCalculatorProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// This is where the magic starts

void CCalculatorProjectDlg::OnBnClickedButtonZero()
{	
	m_editStringControl.SetWindowText(m_currentStringValue += _T("0"));
}


void CCalculatorProjectDlg::OnBnClickedButtonOne()
{
	m_editStringControl.SetWindowText(m_currentStringValue += _T("1"));
}


void CCalculatorProjectDlg::OnBnClickedButtonTwo()
{
	m_editStringControl.SetWindowText(m_currentStringValue += _T("2"));
}


void CCalculatorProjectDlg::OnBnClickedButtonThree()
{
	m_editStringControl.SetWindowText(m_currentStringValue += _T("3"));
}


void CCalculatorProjectDlg::OnBnClickedButtonFour()
{
	m_editStringControl.SetWindowText(m_currentStringValue += _T("4"));
}


void CCalculatorProjectDlg::OnBnClickedButtonFive()
{
	m_editStringControl.SetWindowText(m_currentStringValue += _T("5"));
}


void CCalculatorProjectDlg::OnBnClickedButtonSix()
{
	m_editStringControl.SetWindowText(m_currentStringValue += _T("6"));
}


void CCalculatorProjectDlg::OnBnClickedButtonSeven()
{
	m_editStringControl.SetWindowText(m_currentStringValue += _T("7"));
}


void CCalculatorProjectDlg::OnBnClickedButtonEight()
{
	m_editStringControl.SetWindowText(m_currentStringValue += _T("8"));
}


void CCalculatorProjectDlg::OnBnClickedButtonNine()
{
	m_editStringControl.SetWindowText(m_currentStringValue += _T("9"));
}


void CCalculatorProjectDlg::OnBnClickedButtonDecimal()
{
	//m_operator = _T('.');
	
		if (m_currentStringValue.IsEmpty())
		{
			OnBnClickedButtonZero();
			m_currentStringValue += _T('.');
		}
		// If there is '.' on index 1 but its not somewhere in the string add '.' but dont add two in a row
		else if (m_currentStringValue.GetAt(1) == _T('.') && m_currentStringValue.Find(_T('.'), 2) == -1 && m_currentStringValue[m_currentStringValue.GetLength() - 1] != _T('.'))
		{
			m_currentStringValue += _T('.');
		}

		// If the '.' is not on index 1, add one '.'
		else if (m_currentStringValue.GetAt(1) != _T('.') && m_currentStringValue.Find(_T('.')) == -1) {
			m_currentStringValue += _T('.');
		}

		m_editStringControl.SetWindowText(m_currentStringValue);
}


void CCalculatorProjectDlg::OnBnClickedButtonClear()
{
	m_currentStringValue.Empty();
	m_editStringControl.SetWindowText(_T(""));
}


void CCalculatorProjectDlg::OnBnClickedButtonAddition()
{
	m_operator = _T('+');
	ButtonFunction(m_operator);
}


void CCalculatorProjectDlg::OnBnClickedButtonSubtraction()
{
	m_operator = _T('-');

	// If there is '*' or '/' char, override operator and add '-'
	// This resolves programs confusion for which operator to use
	// when they are one by another
	if (m_currentStringValue.Find(_T('*')) != -1)
	{
		m_operator = _T('*');
		m_currentStringValue += _T('-');
	}

	else if (m_currentStringValue.Find(_T('/')) != -1)
	{
		m_operator = _T('/');
		m_currentStringValue += _T('-');
	}

	// If there is '-' on index 0 but its not somewhere in the string add '-' but dont add two in a row
	else if (m_currentStringValue.GetAt(0) == _T('-') && m_currentStringValue.Find(_T('-'), 1) == -1 && m_currentStringValue[m_currentStringValue.GetLength() - 1] != _T('-'))
	{
		
		if (m_operator == _T('*'))
		{
			m_currentStringValue += _T('-');
		}

		else if (m_operator == _T('/'))
		{
			m_currentStringValue += _T('-');
		}

		else
		{
			m_currentStringValue += _T('-');
		}
	}

	// If the '-' is not on index 0, add one '-' but dont set the operator
	else if (m_currentStringValue.GetAt(0) != _T('-') && m_currentStringValue.Find(_T('-')) == -1)
	{

		m_currentStringValue += _T('-');

	}
	
	m_editStringControl.SetWindowText(m_currentStringValue);
}


void CCalculatorProjectDlg::OnBnClickedButtonMultiplication()
{
	m_operator = _T('*');
	ButtonFunction(m_operator);
}


void CCalculatorProjectDlg::OnBnClickedButtonDivision()
{
	m_operator = _T('/');
	ButtonFunction(m_operator);
}

void CCalculatorProjectDlg::OnBnClickedButtonEquals()
{
	ResultFunction();
}


void CCalculatorProjectDlg::ButtonFunction(TCHAR m_operator)
{
	if (m_currentStringValue.IsEmpty())
	{
		OnBnClickedButtonZero();

		m_currentStringValue += m_operator;
		m_editStringControl.SetWindowText(m_currentStringValue);
	}

	else if (m_currentStringValue.Find(m_operator) == -1)
	{
		m_currentStringValue += m_operator;
		m_editStringControl.SetWindowText(m_currentStringValue);
	}
}

void CCalculatorProjectDlg::ArithmeticOperationPasser(double leftNumeber, double rightNumber, TCHAR m_operator)
{
	m_calculationValue = m_operation.MathOperation(leftNumber, rightNumber, m_operator);
}

void CCalculatorProjectDlg::StringSeparator(CString m_currentStringValue, TCHAR m_operator)
{
	CString leftNumberString;
	CString rightNumberString;
	bool operatorFound = false;

	for (int i = 0; i < m_currentStringValue.GetLength(); i++) // -5-5
	{
		TCHAR currentCharacter = m_currentStringValue.GetAt(i);

		if (currentCharacter == _T('-'))
		{
			if (operatorFound)
			{
				rightNumberString += currentCharacter;
				AfxMessageBox(_T("rightN" + rightNumberString));
			}

			else if (leftNumberString.GetLength() != 0)
			{
				operatorFound = true;
			} 

			else
			{
				leftNumberString += currentCharacter;
				AfxMessageBox(_T("leftN" + leftNumberString));   // -0.5 - 0.5
			}
		}

		else if (!operatorFound)
		{
			if (currentCharacter == m_operator)
			{
				operatorFound = true;
			}

			else
			{
				leftNumberString += currentCharacter;
				AfxMessageBox(_T("leftN" + leftNumberString));
			}
		}

		else
		{
			rightNumberString += currentCharacter;
			AfxMessageBox(_T("rightN" + rightNumberString));
		}
	}



	leftNumber = _tstof(leftNumberString);
	rightNumber = _tstof(rightNumberString);
}

void CCalculatorProjectDlg::ResultFunction()
{
	m_resultStringValue.Empty();
	

	if (m_operator == _T('+'))
	{
		StringSeparator(m_currentStringValue, m_operator);
		ArithmeticOperationPasser(leftNumber, rightNumber, m_operator);
	}

	else if (m_operator == _T('-'))
	{
		StringSeparator(m_currentStringValue, m_operator);
		ArithmeticOperationPasser(leftNumber, rightNumber, m_operator);
	}

	else if (m_operator == _T('*'))
	{
		StringSeparator(m_currentStringValue, m_operator);
		ArithmeticOperationPasser(leftNumber, rightNumber, m_operator);
	}

	else if (m_operator == _T('/'))
	{
		StringSeparator(m_currentStringValue, m_operator);
		ArithmeticOperationPasser(leftNumber, rightNumber, m_operator);
	}

	m_result.Format(_T("%.5f"), m_calculationValue);
	m_editStringControl.SetWindowText(m_resultStringValue += _T(" = ") + m_result);
	m_currentStringValue.Empty();
}



// Registry Functions

void CCalculatorProjectDlg::RegKeyBtnStyleSwitch(DWORD useCButton)
{
	result = m_regKey.Create(HKEY_CURRENT_USER, m_keyPath);

	if (result == ERROR_SUCCESS) 
	{
		result = m_regKey.SetDWORDValue(_T("UseCButton"), useCButton);

		if (result == ERROR_SUCCESS)
		{
			result = m_regKey.QueryDWORDValue(_T("UseCButton"), m_value);

			if (m_value == 0)
			{
				CButton* buttons[17] = { &m_button0, &m_button1, &m_button2, &m_button3, &m_button4, &m_button5, &m_button6, &m_button7, &m_button8, &m_button9,
					&m_buttonDecimal, &m_buttonClear, &m_buttonAddition, &m_buttonSubtraction, &m_buttonMultiplication, &m_buttonDivision , &m_buttonEquals };

				for (CButton* button : buttons)
				{
					ApplyButtonStyleZero(*button);
				}
			}

			else if (m_value == 1)
			{
				CMFCButton* buttons[17] = { &m_button0, &m_button1, &m_button2, &m_button3, &m_button4, &m_button5, &m_button6, &m_button7, &m_button8, &m_button9,
					&m_buttonDecimal, &m_buttonClear, &m_buttonAddition, &m_buttonSubtraction, &m_buttonMultiplication, &m_buttonDivision , &m_buttonEquals };

				for (CMFCButton* button : buttons)
				{
					ApplyButtonStyleOne(*button);
				}
			}
		}
	}

}

void CCalculatorProjectDlg::ApplyButtonStyleZero(CButton& button)
{
	button.RedrawWindow();
}

void CCalculatorProjectDlg::ApplyButtonStyleOne(CMFCButton& button)
{
	//button.SetFaceColor(RGB(9, 2, 1), TRUE);
	button.SetTextColor(RGB(255, 0, 255));
	button.m_nFlatStyle = CMFCButton::BUTTONSTYLE_NOBORDERS;
	button.m_bTransparent = FALSE;
	button.EnableWindowsTheming(FALSE);
	button.RedrawWindow();
}