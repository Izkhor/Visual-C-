
// MFC_DlgnewDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_Dlgnew.h"
#include "MFC_DlgnewDlg.h"
#include "afxdialogex.h"
#include "Dlgnew_2.h"
//#include "StringConversion.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define COLOR_LEBEL_BK RGB(0,255,0)
#define COLOR_LEBEL_TEXT RGB(255,0,0)

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


// CMFC_DlgnewDlg dialog



CMFC_DlgnewDlg::CMFC_DlgnewDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFC_DLGNEW_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_DlgnewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_DlgColor);
}

BEGIN_MESSAGE_MAP(CMFC_DlgnewDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC_DlgnewDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMFC_DlgnewDlg message handlers

BOOL CMFC_DlgnewDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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
	setColorBtn(&m_DlgColor);
	return TRUE;  // return TRUE  unless you set the focus to a control
}
void CMFC_DlgnewDlg::setColorBtn(CButtonST *pButton)
{
	CFont Font;
	pButton->SetFont(&Font);

	pButton->SetActiveBgColor(COLOR_LEBEL_BK);
	pButton->SetActiveFgColor(COLOR_LEBEL_TEXT);
	//pButton->SetDefaultActiveFgColor(FALSE);
	
	

	
}

void CMFC_DlgnewDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_DlgnewDlg::OnPaint()
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
HCURSOR CMFC_DlgnewDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_DlgnewDlg::OnBnClickedButton1()
{
	CDlgnew_2 dlgnew;
	dlgnew.DoModal();
	UpdateIni(true);
	UpdateData(false);
}
void CMFC_DlgnewDlg::UpdateIni(BOOL bLoad)
{
	CString fileName = CString("C:/Projects_Izkhor/Visual-C-/MFC_Dlgnew/ini/glim.ini");
	CIni filePath(fileName);
	filePath.WriteString(_T("Data"), _T("10 "), _T("Parameter"));


}
