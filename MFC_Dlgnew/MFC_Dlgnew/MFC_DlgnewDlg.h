
// MFC_DlgnewDlg.h : header file
//

#pragma once
#include "BtnST.h"
#include "ini.h"

// CMFC_DlgnewDlg dialog
class CMFC_DlgnewDlg : public CDialogEx
{
// Construction
public:
	CMFC_DlgnewDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_DLGNEW_DIALOG };
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
	afx_msg void OnBnClickedButton1();
	CButtonST m_DlgColor;

	void setColorBtn(CButtonST *pButton);
	void UpdateIni(BOOL bLoad);
};
