//
// Created by Helen Stepaniuk on 2019-04-07.
//

#ifndef MYVECTORS_MYVECTOR_H
#define MYVECTORS_MYVECTOR_H

#include <string.h>
using namespace std;
typedef  unsigned long long int ULLI;

template <class T> class Vector{
private:
    T *coord;
    ULLI Size;
public:
    Vector ();
    Vector (ULLI NewSize);
    Vector(const Vector <T> &v);
    Vector(Vector <T> &&v);
    ~Vector ();
    void Input(ULLI Size);
    void Display(string fname);
    void SetOneElement();
    void DisplayOneElement(string fname);
    void ConstMultiplication();
    void operator =(const Vector <T> &v);
    friend Vector <T> operator +(const Vector <T> &vec1, const Vector <T> &vec2);
    friend T Scalar(const Vector <T> &vec1, const Vector <T> &vec2);
    friend const Vector operator *(const Vector <T> &vec1, T constanta);
};
#endif //MYVECTORS_MYVECTOR_H
