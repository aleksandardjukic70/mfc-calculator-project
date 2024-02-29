#include "pch.h"
#include <afxwin.h> 
#include "CMathOperationsFunctions.h"


int CMathOperationsFunctions::MathOperation(CString currentStringValue, CString m_operator)
{
    CString leftNumberString;
    CString rightNumberString;
    bool operatorFound = false;

    for (int i = 0; i < currentStringValue.GetLength(); i++)  // a+b  
    {
        TCHAR currentCharacter = currentStringValue.GetAt(i);

        if (currentCharacter == m_operator)
        {
            operatorFound = true;
        }

        else if (!operatorFound)
        {
            leftNumberString += currentCharacter;
        }

        else
        {
            rightNumberString += currentCharacter;
        }
    }

    leftNumber = _ttoi(leftNumberString);
    rightNumber = _ttoi(rightNumberString);

    if (m_operator == _T('+'))
    {
        operation = leftNumber + rightNumber;
        return operation;
    }

    else if (m_operator == _T('-'))
    {
        operation = leftNumber - rightNumber;
        return operation;
    }

    else if (m_operator == _T('*'))
    {
        operation = leftNumber * rightNumber;
        return operation;
    }

    else if (m_operator == _T('/'))
    {
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
}
