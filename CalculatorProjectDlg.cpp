
// CalculatorProjectDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "CalculatorProject.h"
#include "CalculatorProjectDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
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
}

BEGIN_MESSAGE_MAP(CCalculatorProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CCalculatorProjectDlg::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_ADDITION, &CCalculatorProjectDlg::OnBnClickedButtonAddition)
	ON_BN_CLICKED(IDC_BUTTON_SUBTRACTION, &CCalculatorProjectDlg::OnBnClickedButtonSubtraction)
	ON_BN_CLICKED(IDC_BUTTON_MULTIPLICATION, &CCalculatorProjectDlg::OnBnClickedButtonMultiplication)
	ON_BN_CLICKED(IDC_BUTTON_DIVISION, &CCalculatorProjectDlg::OnBnClickedButtonDivision)
	ON_BN_CLICKED(IDC_BUTTON_EQUALS, &CCalculatorProjectDlg::OnBnClickedButtonEquals)
	ON_BN_CLICKED(IDC_BUTTON_DECIMAL, &CCalculatorProjectDlg::OnBnClickedButtonDecimal)
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
END_MESSAGE_MAP()


// CCalculatorProjectDlg message handlers

BOOL CCalculatorProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

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



void CCalculatorProjectDlg::OnBnClickedButtonClear()
{
	// TODO: Add your control notification handler code here
}


void CCalculatorProjectDlg::OnBnClickedButtonAddition()
{
	// TODO: Add your control notification handler code here
}


void CCalculatorProjectDlg::OnBnClickedButtonSubtraction()
{
	// TODO: Add your control notification handler code here
}


void CCalculatorProjectDlg::OnBnClickedButtonMultiplication()
{
	// TODO: Add your control notification handler code here
}


void CCalculatorProjectDlg::OnBnClickedButtonDivision()
{
	// TODO: Add your control notification handler code here
}


void CCalculatorProjectDlg::OnBnClickedButtonEquals()
{
	// TODO: Add your control notification handler code here
}


void CCalculatorProjectDlg::OnBnClickedButtonDecimal()
{
	// TODO: Add your control notification handler code here
}


void CCalculatorProjectDlg::OnBnClickedButtonZero()
{
	// TODO: Add your control notification handler code here
}


void CCalculatorProjectDlg::OnBnClickedButtonOne()
{
	// TODO: Add your control notification handler code here
}


void CCalculatorProjectDlg::OnBnClickedButtonTwo()
{
	// TODO: Add your control notification handler code here
}


void CCalculatorProjectDlg::OnBnClickedButtonThree()
{
	// TODO: Add your control notification handler code here
}


void CCalculatorProjectDlg::OnBnClickedButtonFour()
{
	// TODO: Add your control notification handler code here
}


void CCalculatorProjectDlg::OnBnClickedButtonFive()
{
	// TODO: Add your control notification handler code here
}


void CCalculatorProjectDlg::OnBnClickedButtonSix()
{
	// TODO: Add your control notification handler code here
}


void CCalculatorProjectDlg::OnBnClickedButtonSeven()
{
	// TODO: Add your control notification handler code here
}


void CCalculatorProjectDlg::OnBnClickedButtonEight()
{
	// TODO: Add your control notification handler code here
}


void CCalculatorProjectDlg::OnBnClickedButtonNine()
{
	// TODO: Add your control notification handler code here
}
