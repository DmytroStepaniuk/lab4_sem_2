//
// Created by Helen Stepaniuk on 2019-04-07.
//

#ifndef CERRORS_H
#define CERRORS_H

#include<string>
#include<iostream>
using namespace std;

class CError
{
protected:
    int ErrorCode;
    string ErrorDescription;
    string ErrorInitObject;
    string ErrorInitMethod;
public:
    CError()
    {
        ErrorCode=0;
    };

    CError(string Description, int Code=0,string Method="Undefined", string ErrObject="Undefined")
    {
        ErrorDescription=Description;
        ErrorCode=Code;
        ErrorInitMethod=Method;
        ErrorInitObject=ErrObject;
    };
    string SpellError()
    {
        return "\nError ocured!\n"+ErrorInitMethod+" generate error in"+ErrorInitObject+" object"+"\nErrorDescription: "+ErrorDescription;
    };
};
#endif

