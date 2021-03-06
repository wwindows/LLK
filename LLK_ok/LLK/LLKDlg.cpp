
// LLKDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LLK.h"
#include "LLKDlg.h"
#include "GameDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CLLKDlg 对话框



CLLKDlg::CLLKDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LLK_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLLKDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLLKDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_BASIC, &CLLKDlg::OnClickedBtnBasic)
	ON_BN_CLICKED(IDC_BTN_RELAX, &CLLKDlg::OnClickedBtnRelax)
	ON_BN_CLICKED(IDC_BTN_LEVEL, &CLLKDlg::OnClickedBtnLevel)
	ON_BN_CLICKED(IDC_BTN_RANK, &CLLKDlg::OnClickedBtnRank)
	ON_BN_CLICKED(IDC_BTN_HELP, &CLLKDlg::OnClickedBtnHelp)
	ON_BN_CLICKED(IDC_BTN_SET, &CLLKDlg::OnClickedBtnSet)
END_MESSAGE_MAP()


// CLLKDlg 消息处理程序

BOOL CLLKDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	InitBackground();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CLLKDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CLLKDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//创建CPaintDC对象
		CPaintDC dc(this);

		dc.BitBlt(0,0,800,600,&m_dcMem,0,0,SRCCOPY);
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CLLKDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CLLKDlg::InitBackground() {
	//加载位图
	CBitmap bmpMain;
	bmpMain.LoadBitmapW(IDB_MAIN_BG);

	//创建兼容DC
	CClientDC dc(this);
	m_dcMem.CreateCompatibleDC(&dc);

	//将位图选进DC
	m_dcMem.SelectObject(bmpMain);

}

void CLLKDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CLLKDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CLLKDlg::OnClickedBtnBasic()
{
	
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);	//隐藏主界面
	CGameControl *basicGC=new CGameControl;
	FLAG basicFlag;
	basicFlag.bProp = false;
	basicFlag.bTimer = true;
	basicFlag.csTitle = _T("欢乐连连看—基本模式 by 温皓");
	basicGC->SetGameFlag(basicFlag);
	CGameDlg dlg;
	dlg.SetGameModel(basicGC);
	dlg.DoModal();
	this->ShowWindow(SW_SHOW);
}


void CLLKDlg::OnClickedBtnRelax()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
	CGameControl *relaxGC = new CGameControl;
	FLAG relaxFlag;
	relaxFlag.bProp = true;
	relaxFlag.bTimer = true;
	relaxFlag.csTitle = _T("欢乐连连看—休闲模式 by 温皓");
	relaxGC->SetGameFlag(relaxFlag);
	CGameDlg dlg;
	dlg.SetGameModel(relaxGC);
	dlg.DoModal();
	this->ShowWindow(SW_SHOW);
}


void CLLKDlg::OnClickedBtnLevel()
{
	// TODO: 在此添加控件通知处理程序代码

	this->ShowWindow(SW_HIDE);
	CGameControl *levelGC = new CGameControl;
	FLAG levelFlag;
	levelFlag.bProp = true;
	levelFlag.bTimer = true;
	levelFlag.csTitle = _T("欢乐连连看—关卡模式 by 温皓");
	levelGC->SetGameFlag(levelFlag);
	CGameDlg dlg;
	dlg.SetGameModel(levelGC);
	dlg.DoModal();
	this->ShowWindow(SW_SHOW);
}


void CLLKDlg::OnClickedBtnRank()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(_T("暂时没其他人玩，所以没有排行~"));
}


void CLLKDlg::OnClickedBtnHelp()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strTitle;
	this->GetWindowTextW(strTitle);
	if (MessageBox(_T("立即充值，成为会员，即可享有帮助功能"), strTitle, MB_OKCANCEL) == IDOK)
	{
		MessageBox(_T("我的博客：http://blog.csdn.net/www_indows"), strTitle);
	}
	else
	{
		MessageBox(_T("不充钱你怎么变强？"), strTitle, MB_OKCANCEL);
	}
}


void CLLKDlg::OnClickedBtnSet()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(_T("暂时没有设置，如需可联系我，博客：http://blog.csdn.net/www_indows"));
}
