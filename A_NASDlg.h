
// A_NASDlg.h : header file
//

#pragma once


// CANASDlg dialog
class CANASDlg : public CDialogEx
{
// Construction
public:
	CANASDlg(CWnd* pParent = nullptr);	// standard constructor

	//void HideRichEdit21();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_A_NAS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnActivateApp(BOOL bActive, DWORD dwThreadID);
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
};
