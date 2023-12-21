/*
* compilar: gcc -o calculadora calculadora.c -Wall -pedantic -Wextra -Werror -lm
*/

#include <windows.h>
#include <math.h>

#define ID_TEXTBOX 1000
#define ID_BTN_SIN 1001
#define ID_BTN_COS 1002
#define ID_BTN_TAN 1003
#define ID_BTN_SQRT 1004
#define ID_BTN_EXP 1005
#define ID_BTN_LOG 1006
#define ID_BTN_CLEAR 1007
#define ID_BTN_EQUALS 1008
#define ID_BTN_ADD 1009
#define ID_BTN_SUBTRACT 1010
#define ID_BTN_MULTIPLY 1011
#define ID_BTN_DIVIDE 1012
#define ID_BTN_DECIMAL 1013

HWND hwndTextBox;
double currentValue = 0;
double storedValue = 0;
char currentOperation = ' ';
bool isDecimalPressed = false;

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) 
{
    switch (message) 
    {
        case WM_CREATE:
            hwndTextBox = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_RIGHT,10, 10, 300, 30, hwnd, (HMENU)ID_TEXTBOX, NULL, NULL);

            CreateWindow("BUTTON", "Sin", WS_VISIBLE | WS_CHILD,10, 50, 60, 30, hwnd, (HMENU)ID_BTN_SIN, NULL, NULL);
            CreateWindow("BUTTON", "Cos", WS_VISIBLE | WS_CHILD,80, 50, 60, 30, hwnd, (HMENU)ID_BTN_COS, NULL, NULL);
            CreateWindow("BUTTON", "Tan", WS_VISIBLE | WS_CHILD,150, 50, 60, 30, hwnd, (HMENU)ID_BTN_TAN, NULL, NULL);
            CreateWindow("BUTTON", "Sqrt", WS_VISIBLE | WS_CHILD,220, 50, 60, 30, hwnd, (HMENU)ID_BTN_SQRT, NULL, NULL);
            CreateWindow("BUTTON", "Exp", WS_VISIBLE | WS_CHILD,290, 50, 60, 30, hwnd, (HMENU)ID_BTN_EXP, NULL, NULL);
            CreateWindow("BUTTON", "Log", WS_VISIBLE | WS_CHILD,10, 90, 60, 30, hwnd, (HMENU)ID_BTN_LOG, NULL, NULL);
            CreateWindow("BUTTON", "C", WS_VISIBLE | WS_CHILD,80, 90, 60, 30, hwnd, (HMENU)ID_BTN_CLEAR, NULL, NULL);
            CreateWindow("BUTTON", "=", WS_VISIBLE | WS_CHILD,150, 90, 60, 30, hwnd, (HMENU)ID_BTN_EQUALS, NULL, NULL);
            CreateWindow("BUTTON", "+", WS_VISIBLE | WS_CHILD,220, 90, 60, 30, hwnd, (HMENU)ID_BTN_ADD, NULL, NULL);
            CreateWindow("BUTTON", "-", WS_VISIBLE | WS_CHILD,290, 90, 60, 30, hwnd, (HMENU)ID_BTN_SUBTRACT, NULL, NULL);
            CreateWindow("BUTTON", "*", WS_VISIBLE | WS_CHILD,10, 130, 60, 30, hwnd, (HMENU)ID_BTN_MULTIPLY, NULL, NULL);
            CreateWindow("BUTTON", "/", WS_VISIBLE | WS_CHILD,80, 130, 60, 30, hwnd, (HMENU)ID_BTN_DIVIDE, NULL, NULL);
            CreateWindow("BUTTON", ".", WS_VISIBLE | WS_CHILD,150, 130, 60, 30, hwnd, (HMENU)ID_BTN_DECIMAL, NULL, NULL);

            // Add number buttons (0-9)
            for (int i = 0; i <= 9; i++) 
            {
                CreateWindow("BUTTON", std::to_string(i).c_str(), WS_VISIBLE | WS_CHILD,220 + (i % 3) * 40, 130 + (i / 3) * 40, 30, 30, hwnd, (HMENU)(ID_BTN_0 + i), NULL, NULL);
            }

            break;
        case WM_COMMAND:
            switch (LOWORD(wParam)) {
                case ID_BTN_SIN:
                    currentValue = sin(currentValue);
                    break;
                case ID_BTN_COS:
                    currentValue = cos(currentValue);
                    break;
                case ID_BTN_TAN:
                    currentValue = tan(currentValue);
                    break;
                case ID_BTN_SQRT:
                    currentValue = sqrt(currentValue);
                    break;
                case ID_BTN_EXP:
                    currentValue = exp(currentValue);
                    break;
                case ID_BTN_LOG:
                    currentValue = log(currentValue);
                    break;
                case ID_BTN_CLEAR:
                    currentValue = 0;
                    storedValue = 0;
                    currentOperation = ' ';
                    isDecimalPressed = false;
                    break;
                case ID_BTN_EQUALS:
                    switch (currentOperation) 
                    {
                        case '+':
                            currentValue = storedValue + currentValue;
                            break;
                        case '-':
                            currentValue = storedValue - currentValue;
                            break;
                        case '*':
                            currentValue = storedValue * currentValue;
                            break;
                        case '/':

                            if (currentValue != 0) 
                            {
                                currentValue = storedValue / currentValue;
                            } 

                            else 
                            {
                                // Handle division by zero
                                MessageBox(hwnd, "Error: Division by zero", "Error", MB_OK | MB_ICONERROR);
                                currentValue = 0;
                            }
                            break;
                    }
                    storedValue = 0;
                    currentOperation = ' ';
                    isDecimalPressed = false;
                    break;
                case ID_BTN_ADD:
                case ID_BTN_SUBTRACT:
                case ID_BTN_MULTIPLY:
                case ID_BTN_DIVIDE:
                    storedValue = currentValue;
                    currentValue = 0;
                    currentOperation = (char)(LOWORD(wParam));
                    isDecimalPressed = false;
                    break;
                case ID_BTN_DECIMAL:

                    if (!isDecimalPressed) 
                    {
                        isDecimalPressed = true;
                        currentValue += 0.0;
                    }
                    break;
                case ID_BTN_0:
                case ID_BTN_1:
                case ID_BTN_2:
                case ID_BTN_3:
                case ID_BTN_4:
                case ID_BTN_5:
                case ID_BTN_6:
                case ID_BTN_7:
                case ID_BTN_8:
                case ID_BTN_9:
                    char buttonText[2];
                    GetWindowText((HWND)lParam, buttonText, 2);
                    currentValue = currentValue * 10 + atof(buttonText);
                    if (isDecimalPressed) 
                    {
                        currentValue /= 10.0;
                    }
                    break;
            }

            // Update the text box with the current value
            SetWindowText(hwndTextBox, std::to_string(currentValue).c_str());

            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, message, wParam, lParam);
    }
    return 0;
}

int main() 
{
    HINSTANCE hInstance = GetModuleHandle(NULL);
    MSG msg;
    WNDCLASS wc = {};

    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "ScientificCalculatorClass";

    RegisterClass(&wc);

    HWND hwnd = CreateWindow("ScientificCalculatorClass","Scientific Calculator",WS_OVERLAPPEDWINDOW,CW_USEDEFAULT, CW_USEDEFAULT, 400, 300,NULL, NULL, hInstance, NULL);

    ShowWindow(hwnd, SW_SHOWNORMAL);
    UpdateWindow(hwnd);

    while (GetMessage(&msg, NULL, 0, 0)) 
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}