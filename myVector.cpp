//
// Created by Helen Stepaniuk on 2019-04-07.
//
#include <iostream>
#include "myVector.h"
#include "CErrors.h"
#include <string.h>

using namespace std;

template <typename T> Vector <T> :: Vector(){ ///конструктор за замовченням
    coord = nullptr;
    Size = 0;
}

template <typename T> Vector <T> :: Vector(ULLI NewSize){ /// конструктор з параметрами
    coord = new T[NewSize];
    Size = NewSize;
}

template <typename T> Vector <T> :: Vector(const Vector <T> &v){ /// конструктор копіювання
    coord = nullptr;
    *this = v;
}

template <typename T> Vector <T> :: Vector(Vector <T> &&v){ /// конструктор переміщення
    coord = v.coord;
    v.coord = nullptr;
    Size = v.Size;
    Size = 0;
}

template <typename T> Vector <T> :: ~Vector(){ ///деструктор
    delete [] coord;
    Size = 0;
}

template <typename T> void Vector <T> :: Input(ULLI Size){
    for(int i = 0; i < Size; i++){
        cout << "Enter the value " << i << " :";
        cin >> coord[i];
    }
    try{
        if(Size == 0)
            throw CError("The Size of vector is equal to zero!!!", 1, "main");
    }
    catch(CError &e){
        cout << e.SpellError();
    }
}
template <typename T> void Vector <T> :: Display(string fname){
    cout << "\t\t\t\t\t" << fname << endl;
    for(int i = 0; i < Size; i++){
        cout << "Element " << i << " is: " << coord[i] << endl;
    }
}

template <typename T> void Vector <T> :: SetOneElement(){
    int index = 0;
    T el;
    do{
        cout << "Enter the index you want to change: ";
        cin >> index;
    }
    while(index >= Size || index < 0);

    cout << "Enter the value to pass to previously entered index: ";
    cin >> el;
    coord[index] = el;
}

template <typename T> void Vector <T> :: DisplayOneElement(string fname){
    int index = 0;
    do{
        cout << "Enter the index you want to display: ";
        cin >> index;
    }
    while(index >= Size || index < 0);
    cout << "The element of " << fname << " in the index " << index << " is : " << coord[index] << endl;
}

template <typename T> void Vector <T> :: ConstMultiplication(){
    T constanta;
    cout << "Enter the constant for multiplication: ";
    cin >> constanta;
    for(int i = 0; i < Size; i++){
        coord[i]*=constanta;
    }
}

template <typename T> void Vector <T> :: operator =(const Vector <T> &v){
    try{
        if(this == &v)
            throw CError("this already is equal to v!", 1, "main");
    }
    catch(CError &e){
        cout << e.SpellError();
    }
    delete [] coord;
    if(v.coord == nullptr){
        coord = nullptr;
        Size = 0;
        return;
    }
    this->Size = v.Size;
    this->coord = new T[v.Size]; /// виділяємо нову ділянку пам'яті
    for(int i = 0; i < v.Size; i++){
        this->coord[i] = v.coord[i]; /// копіюємо всі дані v у поточний об'єкт
    }
}

template <typename T>
Vector <T> operator +(const Vector <T> &vec1, const Vector <T> &vec2){
    Vector <T> v3(vec1.Size);
    for(int i = 0; i < vec1.Size; i++){
        v3.coord[i] = vec1.coord[i] + vec2.coord[i];
    }
    return v3;
}

template <typename T>
T Scalar(const Vector <T> &vec1, const Vector <T> &vec2){
    T scal ;
    for(int i = 0; i < vec1.Size; i++){
        scal += vec1.coord[i]*vec2.coord[i];
    }
    return scal;
}

template <typename T>
const Vector <T> operator *(const Vector <T> &vec1, T constanta){
    Vector <T> v3(vec1.Size);
    for(int i = 0; i < vec1.Size; i++){
        v3.coord[i] = vec1.coord[i]*constanta;
    }
    return v3;
}