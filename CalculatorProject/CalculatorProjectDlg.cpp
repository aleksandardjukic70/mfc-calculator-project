
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
	//DDX_Control(pDX, IDC_STATIC, m_groupBoxStringValue);

}

BEGIN_MESSAGE_MAP(CCalculatorProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
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

	SwitchStyles();

	//CreateRegistryKeyZero();
	//CreateRegistryKeyOne();
	// Set colors
	/*CMFCButton* buttons[17] = { &m_button0, &m_button1, &m_button2, &m_button3, &m_button4, &m_button5, &m_button6, &m_button7, &m_button8, &m_button9,
			&m_buttonDecimal, &m_buttonClear, &m_buttonAddition, &m_buttonSubtraction, &m_buttonMultiplication, &m_buttonDivision , &m_buttonEquals };
	for (CMFCButton* button : buttons)
	{
		ApplyButtonStylesZero(*button);
	}*/


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
	//  when the application's main window is not a dialog
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

// This is where magic starts

void CCalculatorProjectDlg::OnBnClickedButtonZero()
{	
	//CreateRegistryKeyZero();
	m_button0.GetWindowText(m_buttonValue);
	m_currentStringValue += m_buttonValue;
	m_editStringControl.SetWindowText(m_currentStringValue);
}


void CCalculatorProjectDlg::OnBnClickedButtonOne()
{
	//CreateRegistryKeyOne();
	m_button1.GetWindowText(m_buttonValue);
	m_currentStringValue += m_buttonValue;
	m_editStringControl.SetWindowText(m_currentStringValue);
}


void CCalculatorProjectDlg::OnBnClickedButtonTwo()
{
	m_button2.GetWindowText(m_buttonValue);
	m_currentStringValue += m_buttonValue;
	m_editStringControl.SetWindowText(m_currentStringValue);
}


void CCalculatorProjectDlg::OnBnClickedButtonThree()
{
	m_button3.GetWindowText(m_buttonValue);
	m_currentStringValue += m_buttonValue;
	m_editStringControl.SetWindowText(m_currentStringValue);
}


void CCalculatorProjectDlg::OnBnClickedButtonFour()
{
	m_button4.GetWindowText(m_buttonValue);
	m_currentStringValue += m_buttonValue;
	m_editStringControl.SetWindowText(m_currentStringValue);
}


void CCalculatorProjectDlg::OnBnClickedButtonFive()
{
	m_button5.GetWindowText(m_buttonValue);
	m_currentStringValue += m_buttonValue;
	m_editStringControl.SetWindowText(m_currentStringValue);
}


void CCalculatorProjectDlg::OnBnClickedButtonSix()
{
	m_button6.GetWindowText(m_buttonValue);
	m_currentStringValue += m_buttonValue;
	m_editStringControl.SetWindowText(m_currentStringValue);
}


void CCalculatorProjectDlg::OnBnClickedButtonSeven()
{
	m_button7.GetWindowText(m_buttonValue);
	m_currentStringValue += m_buttonValue;
	m_editStringControl.SetWindowText(m_currentStringValue);
}


void CCalculatorProjectDlg::OnBnClickedButtonEight()
{
	m_button8.GetWindowText(m_buttonValue);
	m_currentStringValue += m_buttonValue;
	m_editStringControl.SetWindowText(m_currentStringValue);
}


void CCalculatorProjectDlg::OnBnClickedButtonNine()
{
	m_button9.GetWindowText(m_buttonValue);
	m_currentStringValue += m_buttonValue;
	m_editStringControl.SetWindowText(m_currentStringValue);
}

void CCalculatorProjectDlg::OnBnClickedButtonDecimal()
{
	if (m_currentStringValue.IsEmpty()) 
	{
		OnBnClickedButtonZero();
		m_buttonDecimal.GetWindowText(m_buttonValue);
		m_currentStringValue += m_buttonValue;
		m_editStringControl.SetWindowText(m_currentStringValue);
	}

	else if (m_currentStringValue.Find(_T('.')) == -1)
	{
		m_buttonDecimal.GetWindowText(m_buttonValue);
		m_currentStringValue += m_buttonValue;
		m_editStringControl.SetWindowText(m_currentStringValue);
	}

}

void CCalculatorProjectDlg::OnBnClickedButtonClear()
{
	m_editStringControl.SetWindowText(_T(""));
	m_currentStringValue.Empty();
}


void CCalculatorProjectDlg::OnBnClickedButtonAddition()
{
	if (m_currentStringValue.IsEmpty())
	{
		OnBnClickedButtonZero();
		m_currentStringValue += '+';
		m_operator = '+';
		m_editStringControl.SetWindowText(m_currentStringValue);
	}

	else if (m_currentStringValue.Find(_T('+')) == -1)
	{
		m_currentStringValue += '+';
		m_operator = '+';
		m_editStringControl.SetWindowText(m_currentStringValue);
	}
}


void CCalculatorProjectDlg::OnBnClickedButtonSubtraction()
{
	// napraviti logiku za operator '-'
	m_currentStringValue += '-';
	m_operator = '-';
	m_editStringControl.SetWindowText(m_currentStringValue);
}


void CCalculatorProjectDlg::OnBnClickedButtonMultiplication()
{
	if (m_currentStringValue.IsEmpty()) 
	{
		OnBnClickedButtonZero();
		m_currentStringValue += '*';
		m_operator = '*';
		m_editStringControl.SetWindowText(m_currentStringValue);
	}

	else if (m_currentStringValue.Find(_T('*')) == -1)
	{
		m_currentStringValue += '*';
		m_operator = '*';
		m_editStringControl.SetWindowText(m_currentStringValue);
	}
	
}


void CCalculatorProjectDlg::OnBnClickedButtonDivision()
{
	if (m_currentStringValue.IsEmpty())
	{
		OnBnClickedButtonZero();
		m_currentStringValue += '/';
		m_operator = '/';
		m_editStringControl.SetWindowText(m_currentStringValue);
	}

	else if (m_currentStringValue.Find(_T('/')) == -1)
	{
		m_currentStringValue += '/';
		m_operator = '/';
		m_editStringControl.SetWindowText(m_currentStringValue);
	}
	
}


void CCalculatorProjectDlg::OnBnClickedButtonEquals()
{
	if (m_operator == '+')
	{ 
		m_calculationValue = m_operation.Addition(m_currentStringValue);
		m_result.Format(_T("%d"), m_calculationValue);
	}

	else if (m_operator == '-')
	{
		m_calculationValue = m_operation.Subtraction(m_currentStringValue);
		m_result.Format(_T("%d"), m_calculationValue);
	}

	else if (m_operator == '*')
	{
		m_calculationValue = m_operation.Multiplication(m_currentStringValue);
		m_result.Format(_T("%d"), m_calculationValue);
	}

	else if (m_operator == '/')
	{
		m_calculationValue = m_operation.Division(m_currentStringValue);
		m_result.Format(_T("%d"), m_calculationValue);
	}

	m_editStringControl.GetWindowText(m_resultStringValue);
	m_resultStringValue += _T(" = ") + m_result + _T("\r\n");
	m_editStringControl.SetWindowText(m_resultStringValue);

}

void CCalculatorProjectDlg::CreateRegistryKeyZero()
{
	result = m_regKey.Create(HKEY_CURRENT_USER, m_keyPath);
	if (result == ERROR_SUCCESS) 
	{
		DWORD useCButton = 0;
		result = m_regKey.SetDWORDValue(_T("UseCButton"), useCButton);
	}

}

void CCalculatorProjectDlg::CreateRegistryKeyOne()
{
	result = m_regKey.Create(HKEY_CURRENT_USER, m_keyPath);
	if (result == ERROR_SUCCESS)
	{
		DWORD useCButton = 1;
		result = m_regKey.SetDWORDValue(_T("UseCButton"), useCButton);
	}

}

void CCalculatorProjectDlg::ApplyButtonStylesZero(CMFCButton& button)
{
	button.EnableWindowsTheming(TRUE);
	//button.m_nFlatStyle = CMFCButton::BUTTONSTYLE_NOBORDERS;
	//button.m_bTransparent = FALSE;
	//button.SetFaceColor(RGB(255, 255, 255), TRUE);
	//button.SetTextColor(RGB(0, 0, 255));
	button.RedrawWindow();
	button.Invalidate();
	button.UpdateWindow();

}

void CCalculatorProjectDlg::ApplyButtonStylesOne(CMFCButton& button)
{
	button.EnableWindowsTheming(FALSE);
	button.m_nFlatStyle = CMFCButton::BUTTONSTYLE_NOBORDERS;
	button.m_bTransparent = FALSE;
	//button.SetFaceColor(RGB(9, 2, 1), TRUE);
	button.SetTextColor(RGB(255, 0, 255));
	button.RedrawWindow();
	button.Invalidate();
	button.UpdateWindow();

}

void CCalculatorProjectDlg::SwitchStyles()
{	
	result = m_regKey.Open(HKEY_CURRENT_USER, m_keyPath);
	if (ERROR_SUCCESS == result)
	{
		result = m_regKey.QueryDWORDValue(_T("UseCButton"), value);

			if (value == 0)
			{
				CMFCButton* buttons[17] = { &m_button0, &m_button1, &m_button2, &m_button3, &m_button4, &m_button5, &m_button6, &m_button7, &m_button8, &m_button9,
					&m_buttonDecimal, &m_buttonClear, &m_buttonAddition, &m_buttonSubtraction, &m_buttonMultiplication, &m_buttonDivision , &m_buttonEquals };

				for (CMFCButton* button : buttons)
				{
					ApplyButtonStylesZero(*button);
				}
			}
			
			else if (value == 1)
			{
				CMFCButton* buttons[17] = { &m_button0, &m_button1, &m_button2, &m_button3, &m_button4, &m_button5, &m_button6, &m_button7, &m_button8, &m_button9,
					&m_buttonDecimal, &m_buttonClear, &m_buttonAddition, &m_buttonSubtraction, &m_buttonMultiplication, &m_buttonDivision , &m_buttonEquals };

				for (CMFCButton* button : buttons)
				{
					ApplyButtonStylesOne(*button);
				}
			}
		

		
	}

}
