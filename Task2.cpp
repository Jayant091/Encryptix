#include <iostream>
using namespace std;
int main()
{
    cout<< ".......................................................CALCULATOR......................................................."<<endl<<endl<<endl;
   int a,b,cal;
   float div;
   cout<<"Enter 1st number: ";
   cin>>a;
   cout<<"Enter 2nd number: ";
   cin>>b;
   cout<<" Press \n 1 for Addition \n 2 for Subtraction \n 3 for Multiplication \n 4 for Division \n ";
   cin>>cal;
   switch (cal){
case 1:

       cout<<a<<"+" <<b<<"="<<(a+b);
       break;
       case 2:

       cout<<a <<"-"<< b<< "="<<(a-b);
       break;
       case 3:

       cout<<a <<"*" <<b<< "="<<(a*b);
       break;
        case 4:
         if (b != 0) {
                div = static_cast<float>(a) / b;
                cout << a << " / " << b << " = " << div;
            } else {
                cout << "Error: Division by zero is not allowed.";
            }
            break;
       default:
        cout<<"Please enter a valid choice";
   }
    return 0;
}
