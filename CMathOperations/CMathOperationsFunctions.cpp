#include "pch.h"
#include <afxwin.h> 
#include "CMathOperationsFunctions.h"


int CMathOperationsFunctions::Addition(CString currentStringValue)
{
    // finding position of '+' in currentStringValue
    separator = currentStringValue.Find(_T('+'));

    // spliting currentStringValue to left and right strings
    leftString = currentStringValue.Left(separator);
    rightString = currentStringValue.Mid(separator + 1);

    leftOperand = _ttoi(leftString);
    rightOperand = _ttoi(rightString);

    result = leftOperand + rightOperand;

    return result;

}

int CMathOperationsFunctions::Subtraction(CString currentStringValue)
{
    separator = currentStringValue.Find(_T('-'));

    leftString = currentStringValue.Left(separator);
    rightString = currentStringValue.Mid(separator + 1);

    leftOperand = _ttoi(leftString);
    rightOperand = _ttoi(rightString);

    result = leftOperand - rightOperand;

    return result;

}

int CMathOperationsFunctions::Multiplication(CString currentStringValue)
{
    separator = currentStringValue.Find(_T('*'));

    leftString = currentStringValue.Left(separator);
    rightString = currentStringValue.Mid(separator + 1);

    leftOperand = _ttoi(leftString);
    rightOperand = _ttoi(rightString);

    result = leftOperand * rightOperand;

    return result;

}

int CMathOperationsFunctions::Division(CString currentStringValue)
{

    separator = currentStringValue.Find(_T('/'));

    leftString = currentStringValue.Left(separator);
    rightString = currentStringValue.Mid(separator + 1);

    leftOperand = _ttoi(leftString);
    rightOperand = _ttoi(rightString);

    if (rightOperand != 0)
    {
        result = leftOperand / rightOperand;
        return result;
    } 

    else 
    {
         AfxMessageBox(_T("Error: Division by zero is not allowed."));
         return 0;    
    }

    
}