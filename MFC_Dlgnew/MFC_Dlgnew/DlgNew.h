#pragma once


// DlgNew ��ȭ �����Դϴ�.

class DlgNew : public CDialogEx
{
	DECLARE_DYNAMIC(DlgNew)

public:
	DlgNew(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~DlgNew();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButNew();
};
