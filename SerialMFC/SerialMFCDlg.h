
// SerialMFCDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "mscomm1.h"


// CSerialMFCDlg �Ի���
class CSerialMFCDlg : public CDialogEx
{
// ����
public:
	CSerialMFCDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SERIALMFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBClear();
	afx_msg void OnCbnSelchangeCSelect();
	CComboBox m_comboCom;
	CMscomm1 m_ctrlComm;
private:
	bool m_setOk;
public:
	CString m_strTXData;
	CString m_strRXData;
	DECLARE_EVENTSINK_MAP()
	void OnComm();
	afx_msg void OnBnClickedBSeed();
};
