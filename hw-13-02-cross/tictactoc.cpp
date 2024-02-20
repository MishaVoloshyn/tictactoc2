// hw-13-02-cross.cpp : Определяет точку входа для приложения.
//

#include <windows.h>
#include <tchar.h>
#include <cstring>
#include <vector>
#include <string>
#include <time.h>
#include "Resource.h"

#define BUTTON_COUNT 9
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

using namespace std;

HWND hCheck;
vector<HWND>Buttons;
vector<int>chosen;

void Check(HWND hDlg, WPARAM wParam, LPARAM lParam);
void InitButton(HWND hDlg, WPARAM wParam, LPARAM lParam);


void Check(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
    hCheck = GetDlgItem(hDlg, IDC_CHECK1);

}

void InitButton(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
    for (int i = 0; i < BUTTON_COUNT; i++)
    {
        Buttons.push_back(GetDlgItem(hDlg, IDC_BUTTON1 + i));
        SetDlgItemText(hDlg, IDC_BUTTON1 + i, TEXT(" "));
        EnableWindow(Buttons[i], TRUE);
    }
}


void ResetGame(HWND hDlg, WPARAM wParam, LPARAM lParam) {
    Check(hDlg, wParam, lParam);

    chosen.clear();
}


void MakeComputerMove(HWND hDlg) {
    srand(time(NULL));
    int num;
    if (chosen.size() != NULL)
    {
        do {
            num = rand() % BUTTON_COUNT;
        } while (find(chosen.begin(), chosen.end(), num) != chosen.end());
    }
    else
    {
        num = rand() % BUTTON_COUNT;
    }
    SetDlgItemText(hDlg, IDC_BUTTON1 + num, TEXT("O"));
    EnableWindow(Buttons[num], FALSE);
    chosen.push_back(num);

    
}

void CheckForWinner(HWND hDlg, WPARAM wParam, LPARAM lParam) {
    TCHAR buf[100];


    //Х по вертикали
    GetDlgItemText(hDlg, IDC_BUTTON1, buf, sizeof(buf) / sizeof(buf[0]));

    if (_tcscmp(buf, TEXT("X")) == 0) 
    {
        GetDlgItemText(hDlg, IDC_BUTTON4, buf, sizeof(buf) / sizeof(buf[0]));
        if (_tcscmp(buf, TEXT("X")) == 0) 
        {
            GetDlgItemText(hDlg, IDC_BUTTON7, buf, sizeof(buf) / sizeof(buf[0]));
            if (_tcscmp(buf, TEXT("X")) == 0) 
            {
                MessageBox(hDlg, TEXT("Вы победили!"), TEXT("Поздравляем!"), MB_OK);
                ResetGame(hDlg, wParam, lParam);
            }
        }
    }

    GetDlgItemText(hDlg, IDC_BUTTON2, buf, sizeof(buf) / sizeof(buf[0]));

    if (_tcscmp(buf, TEXT("X")) == 0)
    {
        GetDlgItemText(hDlg, IDC_BUTTON5, buf, sizeof(buf) / sizeof(buf[0]));
        if (_tcscmp(buf, TEXT("X")) == 0)
        {
            GetDlgItemText(hDlg, IDC_BUTTON8, buf, sizeof(buf) / sizeof(buf[0]));
            if (_tcscmp(buf, TEXT("X")) == 0)
            {
                MessageBox(hDlg, TEXT("Вы победили!"), TEXT("Поздравляем!"), MB_OK);
                ResetGame(hDlg, wParam, lParam);
            }
        }
    }

    GetDlgItemText(hDlg, IDC_BUTTON3, buf, sizeof(buf) / sizeof(buf[0]));

    if (_tcscmp(buf, TEXT("X")) == 0)
    {
        GetDlgItemText(hDlg, IDC_BUTTON6, buf, sizeof(buf) / sizeof(buf[0]));
        if (_tcscmp(buf, TEXT("X")) == 0)
        {
            GetDlgItemText(hDlg, IDC_BUTTON9, buf, sizeof(buf) / sizeof(buf[0]));
            if (_tcscmp(buf, TEXT("X")) == 0)
            {
                MessageBox(hDlg, TEXT("Вы победили!"), TEXT("Поздравляем!"), MB_OK);
                ResetGame(hDlg, wParam, lParam);
            }
        }
    }

    //О по вертикали

    GetDlgItemText(hDlg, IDC_BUTTON1, buf, sizeof(buf) / sizeof(buf[0]));

    if (_tcscmp(buf, TEXT("O")) == 0)
    {
        GetDlgItemText(hDlg, IDC_BUTTON4, buf, sizeof(buf) / sizeof(buf[0]));
        if (_tcscmp(buf, TEXT("O")) == 0)
        {
            GetDlgItemText(hDlg, IDC_BUTTON7, buf, sizeof(buf) / sizeof(buf[0]));
            if (_tcscmp(buf, TEXT("O")) == 0)
            {
                MessageBox(hDlg, TEXT("Вы проиграли!"), TEXT("Результат"), MB_OK);
                ResetGame(hDlg, wParam, lParam);
            }
        }
    }

    GetDlgItemText(hDlg, IDC_BUTTON2, buf, sizeof(buf) / sizeof(buf[0]));

    if (_tcscmp(buf, TEXT("O")) == 0)
    {
        GetDlgItemText(hDlg, IDC_BUTTON5, buf, sizeof(buf) / sizeof(buf[0]));
        if (_tcscmp(buf, TEXT("O")) == 0)
        {
            GetDlgItemText(hDlg, IDC_BUTTON8, buf, sizeof(buf) / sizeof(buf[0]));
            if (_tcscmp(buf, TEXT("O")) == 0)
            {
                MessageBox(hDlg, TEXT("Вы проиграли!"), TEXT("Результат"), MB_OK);
                ResetGame(hDlg, wParam, lParam);
            }
        }
    }

    GetDlgItemText(hDlg, IDC_BUTTON3, buf, sizeof(buf) / sizeof(buf[0]));

    if (_tcscmp(buf, TEXT("O")) == 0)
    {
        GetDlgItemText(hDlg, IDC_BUTTON6, buf, sizeof(buf) / sizeof(buf[0]));
        if (_tcscmp(buf, TEXT("O")) == 0)
        {
            GetDlgItemText(hDlg, IDC_BUTTON9, buf, sizeof(buf) / sizeof(buf[0]));
            if (_tcscmp(buf, TEXT("O")) == 0)
            {
                MessageBox(hDlg, TEXT("Вы проиграли!"), TEXT("Результат"), MB_OK);
                ResetGame(hDlg, wParam, lParam);
            }
        }
    }


    //Х по горизонтали
    GetDlgItemText(hDlg, IDC_BUTTON4, buf, sizeof(buf) / sizeof(buf[0]));

    if (_tcscmp(buf, TEXT("X")) == 0)
    {
        GetDlgItemText(hDlg, IDC_BUTTON5, buf, sizeof(buf) / sizeof(buf[0]));
        if (_tcscmp(buf, TEXT("X")) == 0)
        {
            GetDlgItemText(hDlg, IDC_BUTTON6, buf, sizeof(buf) / sizeof(buf[0]));
            if (_tcscmp(buf, TEXT("X")) == 0)
            {
                MessageBox(hDlg, TEXT("Вы победили!"), TEXT("Поздравляем!"), MB_OK);
                ResetGame(hDlg, wParam, lParam);
            }
        }
    }


    //О по горизонтали

    GetDlgItemText(hDlg, IDC_BUTTON4, buf, sizeof(buf) / sizeof(buf[0]));
    if (_tcscmp(buf, TEXT("O")) == 0)
    {
        GetDlgItemText(hDlg, IDC_BUTTON4, buf, sizeof(buf) / sizeof(buf[0]));
        if (_tcscmp(buf, TEXT("O")) == 0)

            GetDlgItemText(hDlg, IDC_BUTTON4, buf, sizeof(buf) / sizeof(buf[0]));
        if (_tcscmp(buf, TEXT("O")) == 0)
        {
            MessageBox(hDlg, TEXT("Вы проиграли :("), TEXT("Игра закончена!"), MB_OK);
            ResetGame(hDlg, wParam, lParam);
        }

    }


    //Х по диагонали
    GetDlgItemText(hDlg, IDC_BUTTON1, buf, sizeof(buf) / sizeof(buf[0]));

    if (_tcscmp(buf, TEXT("X")) == 0)
    {
        GetDlgItemText(hDlg, IDC_BUTTON5, buf, sizeof(buf) / sizeof(buf[0]));
        if (_tcscmp(buf, TEXT("X")) == 0)
        {
            GetDlgItemText(hDlg, IDC_BUTTON9, buf, sizeof(buf) / sizeof(buf[0]));
            if (_tcscmp(buf, TEXT("X")) == 0)
            {
                MessageBox(hDlg, TEXT("Вы победили!"), TEXT("Поздравляем!"), MB_OK);
                ResetGame(hDlg, wParam, lParam);
            }
        }
    }

    GetDlgItemText(hDlg, IDC_BUTTON3, buf, sizeof(buf) / sizeof(buf[0]));

    if (_tcscmp(buf, TEXT("X")) == 0)
    {
        GetDlgItemText(hDlg, IDC_BUTTON5, buf, sizeof(buf) / sizeof(buf[0]));
        if (_tcscmp(buf, TEXT("X")) == 0)
        {
            GetDlgItemText(hDlg, IDC_BUTTON7, buf, sizeof(buf) / sizeof(buf[0]));
            if (_tcscmp(buf, TEXT("X")) == 0)
            {
                MessageBox(hDlg, TEXT("Вы победили!"), TEXT("Поздравляем!"), MB_OK);
                ResetGame(hDlg, wParam, lParam);
            }
        }
    }



    //О по диагонали

    GetDlgItemText(hDlg, IDC_BUTTON1, buf, sizeof(buf) / sizeof(buf[0]));
    if (_tcscmp(buf, TEXT("O")) == 0)
    {
        GetDlgItemText(hDlg, IDC_BUTTON5, buf, sizeof(buf) / sizeof(buf[0]));
        if (_tcscmp(buf, TEXT("O")) == 0)

            GetDlgItemText(hDlg, IDC_BUTTON9, buf, sizeof(buf) / sizeof(buf[0]));
        if (_tcscmp(buf, TEXT("O")) == 0)
        {
            MessageBox(hDlg, TEXT("Вы проиграли :("), TEXT("Игра закончена!"), MB_OK);
            ResetGame(hDlg, wParam, lParam);
        }

    }

    GetDlgItemText(hDlg, IDC_BUTTON3, buf, sizeof(buf) / sizeof(buf[0]));
    if (_tcscmp(buf, TEXT("O")) == 0)
    {
        GetDlgItemText(hDlg, IDC_BUTTON5, buf, sizeof(buf) / sizeof(buf[0]));
        if (_tcscmp(buf, TEXT("O")) == 0)

            GetDlgItemText(hDlg, IDC_BUTTON7, buf, sizeof(buf) / sizeof(buf[0]));
        if (_tcscmp(buf, TEXT("O")) == 0)
        {
            MessageBox(hDlg, TEXT("Вы проиграли :("), TEXT("Игра закончена!"), MB_OK);
            ResetGame(hDlg, wParam, lParam);
        }

    }

}


LRESULT CALLBACK DlgProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    int state = IsDlgButtonChecked(hDlg, IDC_CHECK1);

    switch (uMsg)
    {
    case WM_INITDIALOG:
        InitButton(hDlg, wParam, lParam);
        break;

    case WM_COMMAND:
        {
            if (LOWORD(wParam) == IDCANCEL)
            {
                EndDialog(hDlg, 0);
            } 

            else if (LOWORD(wParam) == IDOK)
            {
                InitButton(hDlg, wParam, lParam);

            }
            else if (LOWORD(wParam) >= IDC_BUTTON1 && LOWORD(wParam) <= IDC_BUTTON1 + BUTTON_COUNT - 1) {
                if (HIWORD(wParam) == BN_CLICKED) 
                {

                    if (state == BST_CHECKED)
                    {
                        for (int i = 0; i < Buttons.size(); i++) {
                            if (LOWORD(wParam) == GetDlgCtrlID(Buttons[i])) {
                                SetDlgItemText(hDlg, IDC_BUTTON1 + i, TEXT("X"));
                                EnableWindow(Buttons[i], FALSE);
                                chosen.push_back(i);
                            }
                        }

                        CheckForWinner(hDlg, wParam, lParam);
                        MakeComputerMove(hDlg);
                        CheckForWinner(hDlg, wParam, lParam);
                    }
                    else if (state == BST_UNCHECKED)
                    {
                        MakeComputerMove(hDlg);
                        CheckForWinner(hDlg, wParam, lParam);

                        for (int i = 0; i < Buttons.size(); i++) {
                            if (LOWORD(wParam) == GetDlgCtrlID(Buttons[i])) {
                                SetDlgItemText(hDlg, IDC_BUTTON1 + i, TEXT("X"));
                                EnableWindow(Buttons[i], FALSE);
                                chosen.push_back(i);
                            }
                        }
                        CheckForWinner(hDlg, wParam, lParam);
                    }


                    
                }
            }



        }
        break;
    
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
        
    }
    return 0;
}

int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpszCmdLine, int nCmdShow)
{
    return DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
}
