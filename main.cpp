#include <iostream>
#include "myVector.h"
#include "CErrors.h"

using namespace std;


int main() {
    Vector <double> v1(3);
   Vector <double> v2(3);
   Vector <double> v3;
   v1.Input(3);
   v2.Input(3);
   Vector <double> v4(v1); ///копіювання v1 у v4
   v1.Display("v1");
   v2.Display("v2");
   double scalar = Scalar (v1, v2);
   cout << "Scalar of v1 and v2: " << scalar << endl;
   v3 = v1 + v2;
   v3.Display("v3");
   v1.SetOneElement();
   v1.Display("v1");
   v1.DisplayOneElement("v1");
   v4.ConstMultiplication();
   v4.Display("v4");
   return 0;
}