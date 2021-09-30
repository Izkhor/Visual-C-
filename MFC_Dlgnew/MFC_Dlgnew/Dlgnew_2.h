#pragma once


// CDlgnew_2 대화 상자입니다.

class CDlgnew_2 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgnew_2)

public:
	CDlgnew_2(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgnew_2();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_New2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
