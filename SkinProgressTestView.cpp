// SkinProgressTestView.cpp : implementation of the CSkinProgressTestView class
//

#include "stdafx.h"
#include "SkinProgressTest.h"

#include "SkinProgressTestDoc.h"
#include "SkinProgressTestView.h"
#ifdef dCSP_DIALOG_PROGRESS
#include "SkinProgressTestDialog.h"
#endif // dCSP_DIALOG_PROGRESS

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSkinProgressTestView

IMPLEMENT_DYNCREATE(CSkinProgressTestView, CFormView)

BEGIN_MESSAGE_MAP(CSkinProgressTestView, CFormView)
	//{{AFX_MSG_MAP(CSkinProgressTestView)
	ON_BN_CLICKED(IDC_BUTTON_TEST, OnButtonTest)
	ON_BN_CLICKED(IDC_RADIO_DEFAULT, OnRadioDefault)
	ON_BN_CLICKED(IDC_RADIO_AQUA, OnRadioAqua)
	ON_BN_CLICKED(IDC_RADIO_LUNA, OnRadioLuna)
	ON_BN_CLICKED(IDC_RADIO_PHOTON, OnRadioPhoton)
	ON_WM_SIZE()
#ifdef dCSP_DIALOG_PROGRESS
	ON_BN_CLICKED(IDC_BUTTON_DIALOG, OnButtonDialog)
#endif // dCSP_DIALOG_PROGRESS
	ON_CBN_SELCHANGE(IDC_COMBO_PROGRESS, OnSelchangeComboProgress)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSkinProgressTestView construction/destruction

CSkinProgressTestView::CSkinProgressTestView()
	: CFormView(CSkinProgressTestView::IDD)
{
	//{{AFX_DATA_INIT(CSkinProgressTestView)
	m_nLimit = 30000;
	m_nPane = 0;
	m_nSize = 200;
	m_strText = _T("This text allows to test the text wrapping");
	m_bCheckReverse = FALSE;
	//}}AFX_DATA_INIT
	// TODO: add construction code here
  m_poSkinProgress = NULL;
}

CSkinProgressTestView::~CSkinProgressTestView()
{
//  if(
//         (m_poSkinProgress != NULL)
//      && (IsWindow(m_poSkinProgress->m_hWnd))
//    )
//  {
//    delete m_poSkinProgress;
//    m_poSkinProgress = NULL;
//  }else{}  
}

void CSkinProgressTestView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSkinProgressTestView)
	DDX_Control(pDX, IDC_HEAD_REVERSE, m_cHeadReverse);
	DDX_Control(pDX, IDC_CHECK_REVERSE, m_cCheckReverse);
	DDX_Control(pDX, IDC_BUTTON_DIALOG, m_cButtonDialog);
	DDX_Control(pDX, IDC_PANE4, m_cPane4);
	DDX_Control(pDX, IDC_PANE3, m_cPane3);
	DDX_Control(pDX, IDC_PANE2, m_cPane2);
	DDX_Control(pDX, IDC_PANE1, m_cPane1);
	DDX_Control(pDX, IDC_PANE0, m_cPane0);
	DDX_Control(pDX, IDC_BOTTOM_RIGHT, m_cBottomRight);
	DDX_Control(pDX, IDC_COMBO_PROGRESS, m_cProgress);
	DDX_Control(pDX, IDC_SPIN_SIZE, m_cSize);
	DDX_Control(pDX, IDC_SPIN_PANE, m_cPane);
	DDX_Control(pDX, IDC_SPIN_LIMIT, m_cLimit);
	DDX_Control(pDX, IDC_BUTTON_TEST, m_cButtonTest);
	DDX_Text(pDX, IDC_EDIT_LIMIT, m_nLimit);
	DDV_MinMaxInt(pDX, m_nLimit, 1, 65535);
	DDX_Text(pDX, IDC_EDIT_PANE, m_nPane);
	DDV_MinMaxInt(pDX, m_nPane, 0, 4);
	DDX_Text(pDX, IDC_EDIT_SIZE, m_nSize);
	DDV_MinMaxInt(pDX, m_nSize, -1280, 1280);
	DDX_Text(pDX, IDC_EDIT_TEXT, m_strText);
	DDV_MaxChars(pDX, m_strText, 256);
	DDX_Check(pDX, IDC_CHECK_REVERSE, m_bCheckReverse);
	//}}AFX_DATA_MAP
}

BOOL CSkinProgressTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CSkinProgressTestView::OnInitialUpdate()
{

  // Init


  // Process

	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

  // Select AUTOSIZE
  m_cProgress.SetCurSel(6);

  // Select Default bitmap
  CheckRadioButton(IDC_RADIO_DEFAULT, IDC_RADIO_PHOTON, IDC_RADIO_DEFAULT);

  // Select Size
  m_cSize.SetRange32(-1280, 1280);
  m_cSize.SetPos(200);

  // Select Limit
  m_cLimit.SetRange32(1, 65535);
  m_cLimit.SetPos(30000);

  // Select Pane
  m_cPane.SetRange32(0, 4);
  m_cPane.SetPos(0);

  // Don't reverse the bitmap
  m_bCheckReverse = false;

#ifdef dCSP_DIALOG_PROGRESS
  m_cButtonDialog.EnableWindow(true);
#else
  m_cButtonDialog.EnableWindow(false);
#endif // dCSP_DIALOG_PROGRESS

#ifdef dCSP_SLIDERBAR_METHOD
  m_cHeadReverse.EnableWindow(true);
  m_cCheckReverse.EnableWindow(true);
#else
  m_cHeadReverse.EnableWindow(false);
  m_cCheckReverse.EnableWindow(false);
#endif // dCSP_SLIDERBAR_METHOD

  // Shows pane text
  m_cPane0.ShowWindow(SW_SHOW);
  m_cPane1.ShowWindow(SW_SHOW);
  m_cPane2.ShowWindow(SW_SHOW);
  m_cPane3.ShowWindow(SW_SHOW);
  m_cPane4.ShowWindow(SW_SHOW);
}

/////////////////////////////////////////////////////////////////////////////
// CSkinProgressTestView diagnostics

#ifdef _DEBUG
void CSkinProgressTestView::AssertValid() const
{
	CFormView::AssertValid();
}

void CSkinProgressTestView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CSkinProgressTestDoc* CSkinProgressTestView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSkinProgressTestDoc)));
	return (CSkinProgressTestDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSkinProgressTestView message handlers

void CSkinProgressTestView::OnButtonTest() 
{
	// TODO: Add your control notification handler code here
  UpdateData(true); // Update variables
  m_cButtonTest.EnableWindow(false); // Disable the 'TEST' button

  CBitmap* poBitmap = NULL;

  // Select the bitmap
  int nCheckedRadio = GetCheckedRadioButton(IDC_RADIO_DEFAULT, IDC_RADIO_PHOTON);
  switch(nCheckedRadio)
  {
    case IDC_RADIO_DEFAULT :
      poBitmap = NULL;
      break;
    case IDC_RADIO_AQUA :
      poBitmap = new CBitmap();
      poBitmap->LoadBitmap(IDB_BMP_AQUA);
      break;
    case IDC_RADIO_LUNA :
      poBitmap = new CBitmap();
      poBitmap->LoadBitmap(IDB_BMP_LUNA);
      break;
    case IDC_RADIO_PHOTON :
      poBitmap = new CBitmap();
      poBitmap->LoadBitmap(IDB_BMP_PHOTON);
      break;
    default :
      poBitmap = NULL;
      break;
  }

//  m_poSkinProgress = new CSkinProgress(m_strText, m_nSize, m_nLimit, m_nPane, m_cProgress.GetCurSel(), poBitmap
//#ifdef dCSP_SLIDERBAR_METHOD
//    ,m_bCheckReverse
//#endif // dCSP_SLIDERBAR_METHOD
//  );

  { // Direct creation (instead of using pointer) - the CSkinProgress object only exists between the brakets
    CSkinProgress SkinProgress
    (
      m_strText,
      m_nLimit,
      m_cProgress.GetCurSel() - (cSPT_EnumElements - 1),
      m_nPane,
      m_nSize,
      poBitmap
#ifdef dCSP_SLIDERBAR_METHOD
      ,m_bCheckReverse
#endif // dCSP_SLIDERBAR_METHOD
    );
    m_poSkinProgress = &SkinProgress; // For event management, see below, [OnRadioDefault] -> [OnRadioPhoton]

/*
// dCSP_TIMED_REDRAW test purpose
    SYSTEMTIME     TimeIn;
    FILETIME       TimeOut;
   
    ULARGE_INTEGER TimeOne;
    ULARGE_INTEGER TimeTwo;

    GetLocalTime(&TimeIn);
    SystemTimeToFileTime(&TimeIn, &TimeOut);
    TimeOne.QuadPart   = TimeOut.dwHighDateTime;
    TimeOne.QuadPart <<= 32;
    TimeOne.QuadPart  |= TimeOut.dwLowDateTime;
*/

	  for(int i = 0; i < m_nLimit; i += 1)
    {
/*
// dCSP_TIMED_REDRAW test purpose
      TimeOne.QuadPart += 5;

      do
      {
        GetLocalTime(&TimeIn);
        SystemTimeToFileTime(&TimeIn, &TimeOut);
        TimeTwo.QuadPart   = TimeOut.dwHighDateTime;
        TimeTwo.QuadPart <<= 32;
        TimeTwo.QuadPart  |= TimeOut.dwLowDateTime;

      }
      while(TimeTwo.QuadPart < TimeOne.QuadPart);
      TimeOne = TimeTwo;
*/

	    SkinProgress.StepIt();
#ifdef dCSP_SLIDERBAR_METHOD
//      SkinProgress.SetStart(i >> 1);
#endif // dCSP_SLIDERBAR_METHOD
	    PeekAndPump();
	  }

    m_poSkinProgress = NULL;
  } // Here the CSkinProgress is deleted

  // Use this for testing the way to make a CSkinProgress living as a pointer - CHANGE THE CSkinProgressTestView DESTRUCTOR ABOVE !!!
//  if(
//         (m_poSkinProgress != NULL)
//      && (IsWindow(m_poSkinProgress->m_hWnd))
//    )
//  { // If you close the application while the bar is in progress, the objects are already deleted, so avoid to delete a deleted object
//    delete m_poSkinProgress;
//    m_poSkinProgress = NULL;
//  }else{}  

  if(poBitmap != NULL)
  {
    delete poBitmap;
  }else{}  

  if(IsWindow(m_cButtonTest.m_hWnd))
  { // If you close the application while the bar is in progress, the objects are already deleted, so avoid to enable a deleted object
    m_cButtonTest.EnableWindow(true); 
  }else{}
}

void CSkinProgressTestView::OnRadioDefault() 
{ // Set the Default bitmap
//  CheckRadioButton(IDC_RADIO_DEFAULT, IDC_RADIO_PHOTON, IDC_RADIO_DEFAULT);

  if(m_poSkinProgress != NULL)
  {
    m_poSkinProgress->SetBitmap(); // Default bitmap
  }else{}
}

void CSkinProgressTestView::OnRadioAqua() 
{ // Set the AQUA bitmap
//  CheckRadioButton(IDC_RADIO_DEFAULT, IDC_RADIO_PHOTON, IDC_RADIO_AQUA);

  if(m_poSkinProgress != NULL)
  {
    CBitmap oBitmap;
    oBitmap.LoadBitmap(IDB_BMP_AQUA);

    m_poSkinProgress->SetBitmap(&oBitmap);
  }else{}
}

void CSkinProgressTestView::OnRadioLuna() 
{ // Set the LUNA bitmap
//  CheckRadioButton(IDC_RADIO_DEFAULT, IDC_RADIO_PHOTON, IDC_RADIO_LUNA);

  if(m_poSkinProgress != NULL)
  {
    CBitmap oBitmap;
    oBitmap.LoadBitmap(IDB_BMP_LUNA);

    m_poSkinProgress->SetBitmap(&oBitmap);
  }else{}
}

void CSkinProgressTestView::OnRadioPhoton() 
{ // Set the PHOTON bitmap
//  CheckRadioButton(IDC_RADIO_DEFAULT, IDC_RADIO_PHOTON, IDC_RADIO_PHOTON);

  if(m_poSkinProgress != NULL)
  {
    CBitmap oBitmap;
    oBitmap.LoadBitmap(IDB_BMP_PHOTON);

    m_poSkinProgress->SetBitmap(&oBitmap);
  }else{}
}

void CSkinProgressTestView::OnSize(UINT nType, int cx, int cy) 
{ // On resizing
  CView::OnSize(nType, cx, cy);

  CWnd*       pMainWnd;
  CWnd*       pMessageBar;

  CRect       rcWindow;
  CRect       rcPane;
  CRect       rcSetPane;

  pMainWnd = AfxGetMainWnd();
  if(pMainWnd != NULL)
  { // If the window exists
    if(pMainWnd->IsKindOf(RUNTIME_CLASS(CFrameWnd)))
    { // If main window is a frame window, use normal methods
      pMessageBar = ((CFrameWnd*) pMainWnd)->GetMessageBar();

      // Get coordinate of the most bottom-right object
      m_cBottomRight.GetWindowRect(rcWindow);
      m_cPane0.GetWindowRect(rcPane);
      ScreenToClient(rcWindow);
      ScreenToClient(rcPane);

      // Set minimal frame window size
      ((CMainFrame*) AfxGetMainWnd())->m_nWidth  = rcWindow.right  + rcWindow.Width();
      ((CMainFrame*) AfxGetMainWnd())->m_nHeight = rcWindow.bottom + rcWindow.Height() + rcPane.Height() + rcPane.Height() + rcPane.Height();

      if(pMessageBar->IsWindowVisible())
      {
        // Relocate pane text 0
        ((CStatusBar*) pMessageBar)->GetItemRect(0, rcWindow);
        rcSetPane.left   = (rcWindow.left + rcWindow.right - rcPane.Width()) / 2;
        rcSetPane.right  = rcSetPane.left + rcPane.Width();
        rcSetPane.top    = cy - rcPane.Height();
        rcSetPane.bottom = cy;
        m_cPane0.MoveWindow(rcSetPane);
        m_cPane0.ShowWindow(SW_SHOW);

        // Relocate pane text 1
        m_cPane1.GetWindowRect(rcPane);
        ScreenToClient(rcPane);
        ((CStatusBar*) pMessageBar)->GetItemRect(1, rcWindow);
        rcSetPane.left   = (rcWindow.left + rcWindow.right - rcPane.Width()) / 2;
        rcSetPane.right  = rcSetPane.left + rcPane.Width();
        rcSetPane.top    = cy - rcPane.Height();
        rcSetPane.bottom = cy;
        m_cPane1.MoveWindow(rcSetPane);
        m_cPane1.ShowWindow(SW_SHOW);

        // Relocate pane text 2
        m_cPane2.GetWindowRect(rcPane);
        ScreenToClient(rcPane);
        ((CStatusBar*) pMessageBar)->GetItemRect(2, rcWindow);
        rcSetPane.left   = (rcWindow.left + rcWindow.right - rcPane.Width()) / 2;
        rcSetPane.right  = rcSetPane.left + rcPane.Width();
        rcSetPane.top    = cy - rcPane.Height();
        rcSetPane.bottom = cy;
        m_cPane2.MoveWindow(rcSetPane);
        m_cPane2.ShowWindow(SW_SHOW);

        // Relocate pane text 3
        m_cPane3.GetWindowRect(rcPane);
        ScreenToClient(rcPane);
        ((CStatusBar*) pMessageBar)->GetItemRect(3, rcWindow);
        rcSetPane.left   = (rcWindow.left + rcWindow.right - rcPane.Width()) / 2;
        rcSetPane.right  = rcSetPane.left + rcPane.Width();
        rcSetPane.top    = cy - rcPane.Height();
        rcSetPane.bottom = cy;
        m_cPane3.MoveWindow(rcSetPane);
        m_cPane3.ShowWindow(SW_SHOW);

        // Relocate pane text 4
        m_cPane4.GetWindowRect(rcPane);
        ScreenToClient(rcPane);
        ((CStatusBar*) pMessageBar)->GetItemRect(4, rcWindow);
        rcSetPane.left   = (rcWindow.left + rcWindow.right - rcPane.Width()) / 2;
        rcSetPane.right  = rcSetPane.left + rcPane.Width();
        rcSetPane.top    = cy - rcPane.Height();
        rcSetPane.bottom = cy;
        m_cPane4.MoveWindow(rcSetPane);
        m_cPane4.ShowWindow(SW_SHOW);
      }
      else
      { // If status bar hidden, hide pane text
        m_cPane0.ShowWindow(SW_HIDE);
        m_cPane1.ShowWindow(SW_HIDE);
        m_cPane2.ShowWindow(SW_HIDE);
        m_cPane3.ShowWindow(SW_HIDE);
        m_cPane4.ShowWindow(SW_HIDE);
      }
    }else{}
  }else{}
}

#ifdef dCSP_DIALOG_PROGRESS
void CSkinProgressTestView::OnButtonDialog() 
{
	// TODO: Add your control notification handler code here
  // Open the dialog
  CSkinProgressTestDialog TestDialog;

  TestDialog.DoModal();
}
#endif // dCSP_DIALOG_PROGRESS

void CSkinProgressTestView::OnSelchangeComboProgress() 
{
	// TODO: Add your control notification handler code here
	if(m_poSkinProgress != NULL)
  {
    m_poSkinProgress->SetProgress(m_cProgress.GetCurSel() - (cSPT_EnumElements - 1));
  }else{}	
}
