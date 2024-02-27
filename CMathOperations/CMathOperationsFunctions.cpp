#include "pch.h"
#include <afxwin.h> 
#include "CMathOperationsFunctions.h"

int CMathOperationsFunctions::Addition(CString currentStringValue)
{
    CString number1;
    CString number2;
    bool operatorFound = false;

    // Iterate through each character in the CString
    for (int i = 0; i < currentStringValue.GetLength(); ++i) 
    {
        TCHAR c = currentStringValue.GetAt(i); // Get character at position i

        if (c == '+') 
        {
            operatorFound = true; // Mark that '+' has been found
            continue; // Skip adding '+' to any number
        }

        else if (!operatorFound) 
        {
            // Append character to number1 if '+' not yet found
            number1 += c;
        }
        else 
        {
            // Append character to number2 if '+' has been found
            number2 += c;
        }
    }

    leftNumber = _ttoi(number1);
    rightNumber = _ttoi(number2);

    operation = leftNumber + rightNumber;
    return operation;
}

int CMathOperationsFunctions::Subtraction(CString currentStringValue)
{
    CString number1;
    CString number2;
    bool operatorFound = false;

    for (int i = 0; i < currentStringValue.GetLength(); ++i) 
    {
        TCHAR c = currentStringValue.GetAt(i);

        if (c == '-') 
        {
            operatorFound = true; 
            continue; 
        }

        else if (!operatorFound) 
        {
            number1 += c;
        }
        else 
        {
            number2 += c;
        }
    }

    leftNumber = _ttoi(number1);
    rightNumber = _ttoi(number2);

    operation = leftNumber - rightNumber;
    return operation;
}

int CMathOperationsFunctions::Multiplication(CString currentStringValue)
{
    CString number1;
    CString number2;
    bool operatorFound = false;

    for (int i = 0; i < currentStringValue.GetLength(); ++i) 
    {
        TCHAR c = currentStringValue.GetAt(i);

        if (c == '*') 
        {
            operatorFound = true;
            continue;
        }

        else if (!operatorFound)
        {
            number1 += c;
        }
        else 
        {
            number2 += c;
        }
    }

    leftNumber = _ttoi(number1);
    rightNumber = _ttoi(number2);

    operation = leftNumber * rightNumber;
    return operation;
}

int CMathOperationsFunctions::Division(CString currentStringValue)
{
    CString number1;
    CString number2;
    bool operatorFound = false;

    for (int i = 0; i < currentStringValue.GetLength(); ++i) 
    {
        TCHAR c = currentStringValue.GetAt(i);

        if (c == '/')
        {
            operatorFound = true;
            continue;
        }

        else if (!operatorFound) 
        {
            number1 += c;
        }
        else 
        {
            number2 += c;
        }
    }

    leftNumber = _ttoi(number1);
    rightNumber = _ttoi(number2);

    if (rightNumber != 0)
    {
        operation = leftNumber / rightNumber;
        return operation;
    } 

    else 
    {
         AfxMessageBox(_T("Error: Division by zero is not allowed."));
         return 0;    
    }

    
}