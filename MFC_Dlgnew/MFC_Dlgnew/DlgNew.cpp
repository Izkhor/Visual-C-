// DlgNew.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFC_Dlgnew.h"
#include "DlgNew.h"
#include "afxdialogex.h"


// DlgNew 대화 상자입니다.

IMPLEMENT_DYNAMIC(DlgNew, CDialogEx)

DlgNew::DlgNew(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

DlgNew::~DlgNew()
{
}

void DlgNew::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DlgNew, CDialogEx)
//	ON_BN_CLICKED(IDC_BUT_NEW, &DlgNew::OnBnClickedButNew)
END_MESSAGE_MAP()


// DlgNew 메시지 처리기입니다.


void DlgNew::OnBnClickedButNew()
{
	
}
