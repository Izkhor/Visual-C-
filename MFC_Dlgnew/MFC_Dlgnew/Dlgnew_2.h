#pragma once


// CDlgnew_2 ��ȭ �����Դϴ�.

class CDlgnew_2 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgnew_2)

public:
	CDlgnew_2(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgnew_2();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_New2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
