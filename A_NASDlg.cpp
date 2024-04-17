

// A_NASDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "A_NAS.h"
#include "A_NASDlg.h"
#include "afxdialogex.h"
#include <fstream>
#include <sstream>
#include <afxwin.h>
#include <string>  // Для работы со строками

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg void OnEnChangeEdit1();

	// AboutDlg.cpp


};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
	ON_WM_ACTIVATE()
	ON_EN_CHANGE(IDC_EDIT1, &CAboutDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CANASDlg dialog



CANASDlg::CANASDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_A_NAS_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CANASDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CANASDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_ACTIVATEAPP()
	ON_BN_CLICKED(IDC_BUTTON3, &CANASDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CANASDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON5, &CANASDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON8, &CANASDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON6, &CANASDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CANASDlg::OnBnClickedButton7)
END_MESSAGE_MAP()



// CANASDlg message handlers

BOOL CANASDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." пункт меню в системное меню.

	// IDM_ABOUTBOX должен находиться в диапазоне системных команд.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Установите значок для этого диалога.  Фреймворк делает это автоматически
	//  когда главное окно приложения не является диалогом
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	// Текстовые поля
	for (int i = IDC_EDIT1; i <= IDC_EDIT20; ++i)
	{
		CWnd* pWnd = GetDlgItem(i);
		if (pWnd)
		{
			pWnd->SetWindowText(_T("")); // Очистка текста
			pWnd->EnableWindow(TRUE); //включение
			//pWnd->ShowWindow(SW_HIDE); // Скрытие
		}
	}

	return TRUE;  // если вы не установили фокус на элемент управления
}

void CANASDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
// Если вы добавите кнопку свертывания в диалоговое окно, вам понадобится код ниже
// чтобы нарисовать значок. Для приложений MFC, использующих модель документа/представления,
// это автоматически делается платформой.

void CANASDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Центральный значок в клиентском прямоугольнике
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Рисуем значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию, чтобы получить курсор, который будет отображаться, пока пользователь перетаскивает
// свернутое окно
HCURSOR CANASDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CANASDlg::OnActivateApp(BOOL bActive, DWORD dwThreadID)
{
	CDialogEx::OnActivateApp(bActive, dwThreadID);

	// TODO: Add your message handler code here
	CWnd* pWnd;
	pWnd = GetDlgItem(IDC_EDIT21); // Получаем указатель на компонент
	if (pWnd)
	{
		// Устанавливаем новые размеры и позицию компонента
		pWnd->SetWindowPos(NULL, 118, 22, 393, 271, SWP_NOZORDER | SWP_NOACTIVATE);
		pWnd->ShowWindow(SW_HIDE); //отобразить компонент
	}
	//включение текстовых полей
	for (int i = IDC_EDIT1; i <= IDC_EDIT20; ++i)
	{
		pWnd = GetDlgItem(i);
		if (pWnd)
			pWnd->EnableWindow(TRUE); // Или TRUE, чтобы включить редактирование
	}
	//включение кнопки Сохранить
	pWnd = GetDlgItem(IDC_BUTTON7);
	if (pWnd)
		pWnd->EnableWindow(TRUE); // Или TRUE, чтобы включить редактирование
	pWnd->SetWindowText(_T("Сохранить"));
	//кнопка О разработчике
	pWnd = GetDlgItem(IDC_BUTTON8);
	if (pWnd)
		pWnd->EnableWindow(TRUE); // Или TRUE, чтобы включить редактирование
	pWnd->SetWindowText(_T("О разработчике"));

}


void CANASDlg::OnBnClickedButton3()
{
	//Режим "Заполнить", включаем редактирование текстовых полей
	// TODO: Add your control notification handler code here
	CWnd* pWnd;
	// Получаем указатели на компоненты IDC_EDIT1 до IDC_EDIT20
	CEdit* pEdits[20];
	pEdits[0] = (CEdit*)GetDlgItem(IDC_EDIT1);
	pEdits[1] = (CEdit*)GetDlgItem(IDC_EDIT2);
	pEdits[2] = (CEdit*)GetDlgItem(IDC_EDIT3);
	pEdits[3] = (CEdit*)GetDlgItem(IDC_EDIT4);
	pEdits[4] = (CEdit*)GetDlgItem(IDC_EDIT5);
	pEdits[5] = (CEdit*)GetDlgItem(IDC_EDIT6);
	pEdits[6] = (CEdit*)GetDlgItem(IDC_EDIT7);
	pEdits[7] = (CEdit*)GetDlgItem(IDC_EDIT8);
	pEdits[8] = (CEdit*)GetDlgItem(IDC_EDIT9);
	pEdits[9] = (CEdit*)GetDlgItem(IDC_EDIT10);
	pEdits[10] = (CEdit*)GetDlgItem(IDC_EDIT11);
	pEdits[11] = (CEdit*)GetDlgItem(IDC_EDIT12);
	pEdits[12] = (CEdit*)GetDlgItem(IDC_EDIT13);
	pEdits[13] = (CEdit*)GetDlgItem(IDC_EDIT14);
	pEdits[14] = (CEdit*)GetDlgItem(IDC_EDIT15);
	pEdits[15] = (CEdit*)GetDlgItem(IDC_EDIT16);
	pEdits[16] = (CEdit*)GetDlgItem(IDC_EDIT17);
	pEdits[17] = (CEdit*)GetDlgItem(IDC_EDIT18);
	pEdits[18] = (CEdit*)GetDlgItem(IDC_EDIT19);
	pEdits[19] = (CEdit*)GetDlgItem(IDC_EDIT20);
	for (int i = 0; i <= 19; ++i)
	{
		pWnd = pEdits[i];
		if (pWnd)
		{
			pWnd->EnableWindow(TRUE);
			pWnd->SetWindowText(_T(""));
		}
	}
	//включение кнопки Сохранить
	pWnd = GetDlgItem(IDC_BUTTON7);
	if (pWnd)
		pWnd->EnableWindow(TRUE); // Или TRUE, чтобы включить редактирование
		pWnd->SetWindowText(_T("Сохранить"));
}


void CANASDlg::OnBnClickedButton2()
{
	// Режим "Просмотр", отключаем редактирование текстовых полей
	// TODO: Add your control notification handler code here
	CWnd* pWnd;

	// Получаем указатели на компоненты IDC_EDIT1 до IDC_EDIT20
	CEdit* pEdits[20];
	pEdits[0] = (CEdit*)GetDlgItem(IDC_EDIT1);
	pEdits[1] = (CEdit*)GetDlgItem(IDC_EDIT2);
	pEdits[2] = (CEdit*)GetDlgItem(IDC_EDIT3);
	pEdits[3] = (CEdit*)GetDlgItem(IDC_EDIT4);
	pEdits[4] = (CEdit*)GetDlgItem(IDC_EDIT5);
	pEdits[5] = (CEdit*)GetDlgItem(IDC_EDIT6);
	pEdits[6] = (CEdit*)GetDlgItem(IDC_EDIT7);
	pEdits[7] = (CEdit*)GetDlgItem(IDC_EDIT8);
	pEdits[8] = (CEdit*)GetDlgItem(IDC_EDIT9);
	pEdits[9] = (CEdit*)GetDlgItem(IDC_EDIT10);
	pEdits[10] = (CEdit*)GetDlgItem(IDC_EDIT11);
	pEdits[11] = (CEdit*)GetDlgItem(IDC_EDIT12);
	pEdits[12] = (CEdit*)GetDlgItem(IDC_EDIT13);
	pEdits[13] = (CEdit*)GetDlgItem(IDC_EDIT14);
	pEdits[14] = (CEdit*)GetDlgItem(IDC_EDIT15);
	pEdits[15] = (CEdit*)GetDlgItem(IDC_EDIT16);
	pEdits[16] = (CEdit*)GetDlgItem(IDC_EDIT17);
	pEdits[17] = (CEdit*)GetDlgItem(IDC_EDIT18);
	pEdits[18] = (CEdit*)GetDlgItem(IDC_EDIT19);
	pEdits[19] = (CEdit*)GetDlgItem(IDC_EDIT20);
	for (int i = 0; i <= 19; ++i)
	{
		pWnd = pEdits[i];
		if (pWnd)
			pWnd->EnableWindow(FALSE); // Или TRUE, чтобы включить редактирование
	}

	// Отключение кнопки Сохранить
	pWnd = GetDlgItem(IDC_BUTTON7);
	if (pWnd)
		pWnd->EnableWindow(FALSE); // Или TRUE, чтобы включить редактирование

	// Чтение файла seti.dat и загрузка текста в компоненты IDC_EDIT1 до IDC_EDIT20
	std::ifstream inFile("seti.dat");
	if (!inFile.is_open())
	{
		AfxMessageBox(_T("Файл seti.dat не найден."));
		return;
	}

	std::string line;
	CString text;
	for (int i = 0; i <= 19; ++i)
	{
		if (std::getline(inFile, line))
		{
			pWnd = pEdits[i];
			if (pWnd)
			{
				text = CString(line.c_str());
				pWnd->SetWindowText(text);
			}
		}
	}

	inFile.close();
}


void CANASDlg::OnBnClickedButton5()
//о программе
{
	// Создаем новый объект диалога IDD_ABOUTBOX
	CDialog dlg(IDD_ABOUTBOX, this);

	// Вызываем модально диалоговое окно
	dlg.DoModal();
}




void CAboutDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


void CAboutDlg::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
	CDialogEx::OnActivate(nState, pWndOther, bMinimized);

	// TODO: Add your message handler code here
}



void CAboutDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CANASDlg::OnBnClickedButton8()
{
	// TODO: Add your control notification handler code here

		// Открываем текстовый файл для чтения
	std::ifstream file("author.txt");

	if (file.is_open())
	{
		// Считываем текст из файла
		std::stringstream buffer;
		buffer << file.rdbuf();
		std::string text = buffer.str();

		// Преобразуем текст в CString и устанавливаем его в компонент IDC_EDIT1
		CString cstrText(text.c_str());
		AfxMessageBox(cstrText, MB_OK | MB_ICONINFORMATION);

		// Закрываем файл
		file.close();
	}
	

}


void CANASDlg::OnBnClickedButton6()
{
	// Выход из приложения
	AfxGetMainWnd()->PostMessage(WM_CLOSE);
}


void CANASDlg::OnBnClickedButton7()
//сохранение файла
{
	// Получаем указатели на компоненты IDC_EDIT1 до IDC_EDIT20
	CEdit* pEdits[20];
	pEdits[0] = (CEdit*)GetDlgItem(IDC_EDIT1);
	pEdits[1] = (CEdit*)GetDlgItem(IDC_EDIT2);
	pEdits[2] = (CEdit*)GetDlgItem(IDC_EDIT3);
	pEdits[3] = (CEdit*)GetDlgItem(IDC_EDIT4);
	pEdits[4] = (CEdit*)GetDlgItem(IDC_EDIT5);
	pEdits[5] = (CEdit*)GetDlgItem(IDC_EDIT6);
	pEdits[6] = (CEdit*)GetDlgItem(IDC_EDIT7);
	pEdits[7] = (CEdit*)GetDlgItem(IDC_EDIT8);
	pEdits[8] = (CEdit*)GetDlgItem(IDC_EDIT9);
	pEdits[9] = (CEdit*)GetDlgItem(IDC_EDIT10);
	pEdits[10] = (CEdit*)GetDlgItem(IDC_EDIT11);
	pEdits[11] = (CEdit*)GetDlgItem(IDC_EDIT12);
	pEdits[12] = (CEdit*)GetDlgItem(IDC_EDIT13);
	pEdits[13] = (CEdit*)GetDlgItem(IDC_EDIT14);
	pEdits[14] = (CEdit*)GetDlgItem(IDC_EDIT15);
	pEdits[15] = (CEdit*)GetDlgItem(IDC_EDIT16);
	pEdits[16] = (CEdit*)GetDlgItem(IDC_EDIT17);
	pEdits[17] = (CEdit*)GetDlgItem(IDC_EDIT18);
	pEdits[18] = (CEdit*)GetDlgItem(IDC_EDIT19);
	pEdits[19] = (CEdit*)GetDlgItem(IDC_EDIT20);

	// Открываем файл для записи
	std::ofstream file("seti.dat");

	// Сохраняем текст из каждого компонента IDC_EDIT в файл
	if (file.is_open())
	{
	for (int i = 0; i < 20; ++i) {
		CString text;
		// Получаем текст из компонента IDC_EDIT
		pEdits[i]->GetWindowText(text);

		// Преобразуем CString в std::string и записываем в файл
		std::string strText(CW2A(text.GetString()));
		file << strText << std::endl;
	}

	// Закрываем файл
	file.close();

	AfxMessageBox(_T("Данные сохранены в файл seti.dat."), MB_OK | MB_ICONINFORMATION);
	}
	else
	{
		AfxMessageBox(_T("Ошибка при сохранении файла."), MB_OK | MB_ICONERROR);
	}
}
