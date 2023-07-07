// P7. Write a class to implement the Polynomial using link list. As discussed in lectures.
// Write function for addition, subtraction and multiplication of polynomial.

#include <iostream>
using namespace std;

class Polynomial
{
public:
    int coeff;
    int power;
    Polynomial *next;

    Polynomial(int coeff, int power)
    {
        next = NULL;
        this->coeff = coeff;
        this->power = power;
    }
};

Polynomial *addition(Polynomial *p1, Polynomial *p2)
{
    if (p1 == NULL && p2 == NULL)
    {
        return NULL;
    }
    if (p2 == NULL)
    {
        return p1;
    }
    if (p1 == NULL)
    {
        return p2;
    }

    // Assumming the Polynomials are arranged in decreasing order of the power.
    Polynomial *temp1 = p1;
    Polynomial *temp2 = p2;

    Polynomial *newh = NULL;
    Polynomial *newt = NULL;

    while (temp1 != NULL || temp2 != NULL)
    {
        if (temp1->power == temp2->power)
        {
            Polynomial *temp = new Polynomial(temp1->coeff + temp2->coeff, temp1->power);
            if (newh == NULL)
            {
                newh = temp;
                newt = temp;
            }
            else
            {
                newt->next = temp;
                newt = temp;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->power > temp2->power)
        {
            Polynomial *temp = new Polynomial(temp1->coeff, temp1->power);
            if (newh == NULL)
            {
                newh = temp;
                newt = temp;
            }
            else
            {
                newt->next = temp;
                newt = temp;
            }
            temp1 = temp1->next;
        }
        else
        {
            Polynomial *temp = new Polynomial(temp2->coeff, temp2->power);
            if (newh == NULL)
            {
                newh = temp;
                newt = temp;
            }
            else
            {
                newt->next = temp;
                newt = temp;
            }
            temp2 = temp2->next;
        }
    }
    if (temp1 != NULL)
    {
        while (temp1 != NULL)
        {
            Polynomial *temp = new Polynomial(temp1->coeff, temp1->power);
            newt->next = temp;
            newt = temp;
        }
    }
    if (temp2 != NULL)
    {
        while (temp2 != NULL)
        {
            Polynomial *temp = new Polynomial(temp2->coeff, temp2->power);
            newt->next = temp;
            newt = temp;
        }
    }
    return newh;
}