// BciDrawWaveDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BciDrawWave.h"
#include "BciDrawWaveDlg.h"
#include "ProtocolPack.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBciDrawWaveDlg dialog

CBciDrawWaveDlg::CBciDrawWaveDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBciDrawWaveDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBciDrawWaveDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBciDrawWaveDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBciDrawWaveDlg)
	DDX_Control(pDX, IDC_STATIC_SPO2, m_ctrlSpo2);
	DDX_Control(pDX, IDC_STATIC_PR, m_ctrlPr);
	DDX_Control(pDX, IDC_STATIC_BAR, m_ctrlBar);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBciDrawWaveDlg, CDialog)
	//{{AFX_MSG_MAP(CBciDrawWaveDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_UART_SET, OnButtonUartSet)
	ON_BN_CLICKED(IDC_BUTTON_UART_OPEN, OnButtonUartOpen)
	ON_BN_CLICKED(IDC_BUTTON_UART_CLOSE, OnButtonUartClose)
	ON_MESSAGE(WM_COMM_RXCHAR,OnMessageCom)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_FILE_SAVE, OnButtonFileSave)
	ON_BN_CLICKED(IDC_BUTTON_FILE_REVIEW, OnButtonFileReview)
	ON_MESSAGE(WM_FILE_PLAY_REFRESH,OnPlayFile)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBciDrawWaveDlg message handlers

BOOL CBciDrawWaveDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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
	CRect rect;
	GetDlgItem(IDC_STATIC_RED)->GetWindowRect(rect) ;
	ScreenToClient(rect);
	m_OScopeCtrl.Create(WS_VISIBLE | WS_CHILD, rect, this) ; 

	GetDlgItem(IDC_STATIC_INFRARED)->GetWindowRect(rect) ;
	ScreenToClient(rect);
	m_OSCopeInfraRedCtrl.Create(WS_VISIBLE | WS_CHILD,rect,this) ;
	
	// customize the control
	m_OSCopeInfraRedCtrl.SetRange(0,1000000,0);
	m_OSCopeInfraRedCtrl.SetYUnits("");
	m_OSCopeInfraRedCtrl.SetXUnits("Infra-RED WAVE");
	m_OSCopeInfraRedCtrl.SetBackgroundColor(RGB(0, 0, 0)) ;
	m_OSCopeInfraRedCtrl.SetGridColor(RGB(192, 192, 255)) ;
	m_OSCopeInfraRedCtrl.SetPlotColor(RGB(255, 255, 255)) ;

	m_OScopeCtrl.SetRange(0, 1000000, 0) ;
	m_OScopeCtrl.SetYUnits("") ;
	m_OScopeCtrl.SetXUnits("RED WAVE") ;
	//m_OScopeCtrl.SetTitle("") ;
	m_OScopeCtrl.SetBackgroundColor(RGB(0, 0, 0)) ;
	m_OScopeCtrl.SetGridColor(RGB(192, 192, 255)) ;
	m_OScopeCtrl.SetPlotColor(RGB(255, 255, 255)) ;


	m_SerialPort.m_strBuad = "115200";
	m_SerialPort.m_strCheck = "NONE";

	m_PlayFile.m_pOwner = this;
	m_ctrlSpo2.SetTextHeight(20);
	m_ctrlBar.SetTextHeight(20);
	m_ctrlPr.SetTextHeight(20);
	//
	SetTimer(1,1000,NULL);
	InitWavePack();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBciDrawWaveDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBciDrawWaveDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBciDrawWaveDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CBciDrawWaveDlg::OnButtonUartSet() 
{
	// TODO: Add your control notification handler code here
	m_SerialPort.ConfigPort();
}

void CBciDrawWaveDlg::OnButtonUartOpen() 
{
	// TODO: Add your control notification handler code here
	m_SerialPort.OpenPort(this);
}

void CBciDrawWaveDlg::OnButtonUartClose() 
{
	// TODO: Add your control notification handler code here
	m_SerialPort.ClosePort();
}

void CBciDrawWaveDlg::OnMessageCom(WPARAM wp,LPARAM lp)
{
	UCHAR data;
	CString tempStr;
	int Red,InfraRed,Status;

	data = wp;
	if(m_FileSaveThread.m_bSaveFile)
		m_FileSaveThread.ReceiveData(&data,1);
	if(UnpackWaveData(data) > 0)
	{
		Red = GetPackData(Var_RedWave);
		InfraRed = GetPackData(Var_InfraRedWave);
		Status = GetPackData(Var_Debug_Status);
		tempStr.Format("%d",Red);
		m_ctrlBar.SetText(tempStr);

		tempStr.Format("%d",InfraRed);
		m_ctrlPr.SetText(tempStr);
		
		tempStr.Format("%d",Status);
		m_ctrlSpo2.SetText(tempStr);

		m_OScopeCtrl.AppendPoint(Red);
		m_OSCopeInfraRedCtrl.AppendPoint(InfraRed);
	}
}

void CBciDrawWaveDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
/*	UCHAR spo2,ss,pr,bar;
	CString strTmp,strTmp1="0",strTmp2="0",strTmp3="0";
	UCHAR data = 0;
	
	GetBciData(BCI_DATA_SPO2_VALUE,&spo2);
	if(spo2 == 0x7f)
		strTmp = "---";
	else
		strTmp.Format("%d",spo2);
	m_ctrlSpo2.SetText(strTmp);

	GetBciData(BCI_DATA_SIGNAL_STRONG,&ss);
	if(ss == 0x0f)
		strTmp1 = "---";
	else
	strTmp1.Format("%d",ss);
	m_ctrlSs.SetText(strTmp1);

	GetBciData(BCI_DATA_PULSE_RATE,&pr);
	if(pr == 0xff)
		strTmp2 = "---";
	else
	strTmp2.Format("%d",pr);
	m_ctrlPr.SetText(strTmp2);

	GetBciData(BCI_DATA_BAR_GRAPH,&bar);
	if(bar == 0x0f)
		strTmp3 = "---";
	else
	strTmp3.Format("%d",bar);
	m_ctrlBar.SetText(strTmp3);*/

	CDialog::OnTimer(nIDEvent);
}

void CBciDrawWaveDlg::OnButtonFileSave() 
{
	// TODO: Add your control notification handler code here
	m_FileSaveThread.ShowDlg();
}

void CBciDrawWaveDlg::OnButtonFileReview() 
{
	// TODO: Add your control notification handler code here
	m_PlayFile.ShowDlg();
}

void CBciDrawWaveDlg::OnPlayFile(WPARAM wp,LPARAM lp)	//Í¼Ïñ»Ø·Å£¿
{
	BOOL bStaticPlay;
	UCHAR *pChar,data;
	//UCHAR wave,sensor,stime;
	CString strTmp,strTmp1;

	bStaticPlay = wp; 
	if(!bStaticPlay)
	{
	
		if(m_PlayFile.m_strFileType == ".bin")
		{
			pChar = (UCHAR *)m_PlayFile.m_pData[0];
			while( m_PlayFile.m_nCurPos < m_PlayFile.m_nFileSize)
			{
				//m_EcgProtocol.m_DataUnpack.UnPackData(pChar[m_PlayFile.m_nCurPos]);
				data = pChar[m_PlayFile.m_nCurPos];
				SendMessage(WM_COMM_RXCHAR,data,0);
				m_PlayFile.m_nCurPos++;
				if(data >= 0x80)
					break;		
			}
			
		}
	}
}
