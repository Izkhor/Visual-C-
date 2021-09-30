#ifndef _BTNST_H
#define _BTNST_H

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
#ifndef	BTNST_OK
#define	BTNST_OK						0
#endif
#ifndef	BTNST_INVALIDINDEX
#define	BTNST_INVALIDINDEX				3
#endif
// CBtnST.h : header file
//

// Comment this if you don't want that CButtonST hilights itself
// also when the window is inactive (like happens in Internet Explorer)
#define ST_LIKEIE

// Comment this if you don't want to use CMemDC class
#define ST_USE_MEMDC

/****************************************************************************/
/*  �ļ���: BtnST.h /BtnST.cpp				 								*/
/*  ��  ��: ״̬��ť��										                */
/*  ��  ��:														     		*/
/*            1. ���ݰ�ť״̬���ð�ť								    	*/	 
/*            2. ����������ڸ�ʵ��ģ���л���ť								*/	
/*  ��  ��:													                */
/*  �޸�����:  ����			                                                */
/*  �޶���: �����࣬�Բ��ֹ��������޸�                                      */
/****************************************************************************/
/////////////////////////////////////////////////////////////////////////////
// CButtonST window

class CButtonST : public CButton
{
// Construction
public:
    CButtonST();
	~CButtonST();
    //enum {ST_ALIGN_HORIZ, ST_ALIGN_VERT};
	enum {
		ST_ALIGN_HORIZ = 0,			// Icon/bitmap on the left, text on the right
		ST_ALIGN_VERT,					// Icon/bitmap on the top, text on the bottom
		ST_ALIGN_HORIZ_RIGHT,			// Icon/bitmap on the right, text on the left
		ST_ALIGN_OVERLAP				// Icon/bitmap on the same space as text
	};

	enum {
		BTNST_COLOR_BK_IN = 0,		// Background color when mouse is INside
		BTNST_COLOR_FG_IN,				// Text color when mouse is INside
		BTNST_COLOR_BK_OUT,				// Background color when mouse is OUTside
		BTNST_COLOR_FG_OUT,				// Text color when mouse is OUTside
		BTNST_COLOR_BK_FOCUS,			// Background color when the button is focused
		BTNST_COLOR_FG_FOCUS,			// Text color when the button is focused

		BTNST_MAX_COLORS
	};

	enum {
		BTNST_PRESSED_LEFTRIGHT = 0,	// Pressed style from left to right (as usual)
		BTNST_PRESSED_TOPBOTTOM			// Pressed style from top to bottom
	};

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CButtonST)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	bool m_bIsActive;
	//DWORD SetDefaultColors(BOOL bRepaint = TRUE);
	
	/*DWORD GetColor(BYTE byColorIndex, COLORREF* crpColor);
	DWORD OffsetColor(BYTE byColorIndex, short shOffset, BOOL bRepaint = TRUE);
	BOOL SetBtnCursor(int nCursorId = -1);
*/
	void SetFlatFocus(BOOL bDrawFlatFocus, BOOL bRepaint = FALSE);
	BOOL GetFlatFocus();
	void SetColor(BYTE byColorIndex, COLORREF crColor, BOOL bRepaint = TRUE);
	void SetDefaultActiveFgColor(BOOL bRepaint = FALSE);
	void SetActiveFgColor(COLORREF crNew, BOOL bRepaint = FALSE);
	const COLORREF GetActiveFgColor();
	
	void SetDefaultActiveBgColor(BOOL bRepaint = FALSE);
	void SetActiveBgColor(COLORREF crNew, BOOL bRepaint = FALSE);
	const COLORREF GetActiveBgColor();
	
	void SetDefaultInactiveFgColor(BOOL bRepaint = FALSE);
	void SetInactiveFgColor(COLORREF crNew, BOOL bRepaint = FALSE);
	const COLORREF GetInactiveFgColor();

	void SetDefaultInactiveBgColor(BOOL bRepaint = FALSE);
	void SetInactiveBgColor(COLORREF crNew, BOOL bRepaint = FALSE);
	const COLORREF GetInactiveBgColor();

	void SetShowText(BOOL bShow = TRUE);
	BOOL GetShowText();

	void SetAlign(int nAlign);
	int GetAlign();

	void SetFlat(BOOL bState = TRUE);
	BOOL GetFlat();

	void DrawBorder(BOOL bEnable = TRUE);
	void SetIcon(int nIconInId, int nIconOutId = NULL, BYTE cx = 32, BYTE cy = 32);

	static const short GetVersionI();
	static const char* GetVersionC();

protected:
    //{{AFX_MSG(CButtonST)
	afx_msg void OnCaptureChanged(CWnd *pWnd);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	void DrawTheIcon(CDC* pDC, CString* title, RECT* rcItem, CRect* captionRect, BOOL IsPressed, BOOL IsDisabled);

	int m_nAlign;
	BOOL m_bShowText;
	BOOL m_bDrawBorder;
	BOOL m_bIsFlat;
	BOOL m_MouseOnButton;
	BOOL m_bDrawFlatFocus;
	COLORREF	m_crColors[BTNST_MAX_COLORS];	// Colors to be used

	HCURSOR m_hCursor;

	HICON m_hIconIn;
	HICON m_hIconOut;
	BYTE m_cyIcon;
	BYTE m_cxIcon;

	COLORREF  m_crInactiveBg;
    COLORREF  m_crInactiveFg;
    COLORREF  m_crActiveBg;
    COLORREF  m_crActiveFg;
};


#ifdef ST_USE_MEMDC
//////////////////////////////////////////////////
// CMemDC - memory DC
//
// Author: Keith Rule
// Email:  keithr@europa.com
// Copyright 1996-1997, Keith Rule
//
// You may freely use or modify this code provided this
// Copyright is included in all derived versions.
//
// History - 10/3/97 Fixed scrolling bug.
//                   Added print support.
//           25 feb 98 - fixed minor assertion bug
//
// This class implements a memory Device Context

class CMemDC2 : public CDC
{
public:

    // constructor sets up the memory DC
    CMemDC2(CDC* pDC) : CDC()
    {
        ASSERT(pDC != NULL);

        m_pDC = pDC;
        m_pOldBitmap = NULL;
        m_bMemDC = !pDC->IsPrinting();
              
        if (m_bMemDC)    // Create a Memory DC
        {
            pDC->GetClipBox(&m_rect);
            CreateCompatibleDC(pDC);
            m_bitmap.CreateCompatibleBitmap(pDC, m_rect.Width(), m_rect.Height());
            m_pOldBitmap = SelectObject(&m_bitmap);
            SetWindowOrg(m_rect.left, m_rect.top);
        }
        else        // Make a copy of the relevent parts of the current DC for printing
        {
            m_bPrinting = pDC->m_bPrinting;
            m_hDC       = pDC->m_hDC;
            m_hAttribDC = pDC->m_hAttribDC;
        }
    }
    
    // Destructor copies the contents of the mem DC to the original DC
    ~CMemDC2()
    {
        if (m_bMemDC) 
        {    
            // Copy the offscreen bitmap onto the screen.
            m_pDC->BitBlt(m_rect.left, m_rect.top, m_rect.Width(), m_rect.Height(),
                          this, m_rect.left, m_rect.top, SRCCOPY);

            //Swap back the original bitmap.
            SelectObject(m_pOldBitmap);
        } else {
            // All we need to do is replace the DC with an illegal value,
            // this keeps us from accidently deleting the handles associated with
            // the CDC that was passed to the constructor.
            m_hDC = m_hAttribDC = NULL;
        }
    }

    // Allow usage as a pointer
    CMemDC2* operator->() {return this;}
        
    // Allow usage as a pointer
    operator CMemDC2*() {return this;}

private:
    CBitmap  m_bitmap;      // Offscreen bitmap
    CBitmap* m_pOldBitmap;  // bitmap originally found in CMemDC
    CDC*     m_pDC;         // Saves CDC passed in constructor
    CRect    m_rect;        // Rectangle of drawing area.
    BOOL     m_bMemDC;      // TRUE if CDC really is a Memory DC.
};

#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif
