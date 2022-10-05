#include<iostream>
using namespace std;
#include "complexNumberclass.cpp"

int main()
{
    int real1,imaginary1,real2,imaginary2;
    cin>>real1>>imaginary1;
    cin>>real2>>imaginary2;

    complexNumbers c1(real1,imaginary1);
    complexNumbers c2(real2,imaginary2);

    int choice;
    cin>>choice;

    if(choice==1){
        c1.plus(c2);
        c1.print();
    }

    else if(choice==2){
        c1.multiply(c2);
        c1.print();
    }

    else{
        cout<<"choice doesnt EXIST!"<<endl;
    }

    return 0;
}