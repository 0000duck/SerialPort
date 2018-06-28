
// SerialMFCDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SerialMFC.h"
#include "SerialMFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSerialMFCDlg �Ի���



CSerialMFCDlg::CSerialMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSerialMFCDlg::IDD, pParent)
	, m_setOk(false)
	, m_strTXData(_T(""))
	, m_strRXData(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSerialMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_C_SELECT, m_comboCom);
	DDX_Control(pDX, IDC_MSCOMM, m_ctrlComm);
	DDX_Text(pDX, IDC_E_RECEIVE, m_strRXData);
	DDX_Text(pDX, IDC_E_SEED, m_strTXData);
}

BEGIN_MESSAGE_MAP(CSerialMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_B_CLEAR, &CSerialMFCDlg::OnBnClickedBClear)
	ON_CBN_SELCHANGE(IDC_C_SELECT, &CSerialMFCDlg::OnCbnSelchangeCSelect)
	ON_BN_CLICKED(IDC_B_SEED, &CSerialMFCDlg::OnBnClickedBSeed)
END_MESSAGE_MAP()


// CSerialMFCDlg ��Ϣ�������

BOOL CSerialMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�
	m_comboCom.AddString(_T("COM1")); // Ϊ��Ͽ�ؼ����б������б���  
	m_comboCom.AddString(_T("COM2"));
	m_comboCom.AddString(_T("COM3"));
	m_comboCom.AddString(_T("COM4"));
	m_comboCom.AddString(_T("COM5"));
	m_comboCom.AddString(_T("COM6"));
	m_comboCom.AddString(_T("COM7"));
	m_comboCom.AddString(_T("COM8"));
	m_comboCom.AddString(_T("COM9"));
	m_comboCom.AddString(_T("COM10"));
	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CSerialMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CSerialMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CSerialMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSerialMFCDlg::OnBnClickedBClear()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_strRXData = "";
	UpdateData(FALSE);//���±༭������  
}


void CSerialMFCDlg::OnCbnSelchangeCSelect()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	int nSel;
	nSel = m_comboCom.GetCurSel();//��ȡ��Ͽ�ؼ����б����ѡ���������  

	m_ctrlComm.put_CommPort(nSel + 1);//ѡ�񴮿ں�(������Ϊ�б����������Ǵ�0��ʼ������(nSel+1)��Ӧ�Ĳ���������ѡ�Ĵ��ں�)  
	m_ctrlComm.put_PortOpen(TRUE);//�򿪴���  
	m_ctrlComm.put_RThreshold(2);//�յ������ֽ�����OnComm�¼�   
	m_ctrlComm.put_InputMode(1);//����ģʽѡΪ������   
	m_ctrlComm.put_Settings(_T("9600,n,8,1"));//���ô��ڲ����������ʣ�����żУ�飬λֹͣλ��λ����λ  
	m_ctrlComm.put_InputMode(1);  // �Զ����Ʒ�ʽ��ȡ����   
	m_ctrlComm.put_RThreshold(1); //����1��ʾÿ�����ڽ��ջ��������ж��ڻ����1���ַ�ʱ������һ���������ݵ�OnComm�¼�   
	m_ctrlComm.put_InputLen(0); //���õ�ǰ���������ݳ���Ϊ0   
	m_ctrlComm.get_Input();//��Ԥ���������������������    

	m_setOk = true;     //��Ǵ�������OK  
}
BEGIN_EVENTSINK_MAP(CSerialMFCDlg, CDialogEx)
	ON_EVENT(CSerialMFCDlg, IDC_MSCOMM, 1, CSerialMFCDlg::OnComm, VTS_NONE)
END_EVENTSINK_MAP()


void CSerialMFCDlg::OnComm()
{
	// TODO:  �ڴ˴������Ϣ����������
	VARIANT variant_inp;   //Variant ��һ��������������ͣ����˶���String���ݼ��û����������⣬���԰����κ���������ݡ�  
	COleSafeArray safearray_inp;
	LONG len, k;
	BYTE rxdata[2048]; //����BYTE���� An 8-bit integer that is not signed.       
	CString strtemp;
	if (m_ctrlComm.get_CommEvent() == 2) //�¼�ֵΪ2��ʾ���ջ����������ַ�       
	{
		////////��������Ը����Լ���ͨ��Э����봦�����   
		variant_inp = m_ctrlComm.get_Input();     //��������    
		safearray_inp = variant_inp;              //VARIANT�ͱ���ת��ΪColeSafeArray�ͱ���  
		len = safearray_inp.GetOneDimSize();      //�õ���Ч���ݳ���          
		for (k = 0; k < len; k++)
			safearray_inp.GetElement(&k, rxdata + k);//ת��ΪBYTE������           
		for (k = 0; k < len; k++)                    //������ת��ΪCstring�ͱ���      
		{
			BYTE bt = *(char*)(rxdata + k);//�ַ���        
			strtemp.Format(_T("%c"), bt); //���ַ�������ʱ����strtemp���     
			m_strRXData += strtemp; //������ձ༭���Ӧ�ַ���        
		}
	}
	UpdateData(FALSE); //���±༭������  
}


void CSerialMFCDlg::OnBnClickedBSeed()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (m_setOk == true)    //�ж��Ƿ�򿪲���ʼ������  
	{
		UpdateData(TRUE);  //��ȡ�༭������  
		m_ctrlComm.put_Output(COleVariant(m_strTXData)); //��������  
	}
	else
	{
		MessageBox(_T("����ѡ��COM��"));
	}
}
