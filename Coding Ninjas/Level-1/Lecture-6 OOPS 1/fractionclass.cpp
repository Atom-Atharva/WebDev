class fraction
{
private:
    int numerator;
    int denominator;

public:
    fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    void print()
    {
        cout << numerator << " / " << denominator << endl;
        return;
    }

    void simplify()
    {
        int gcd = 1;
        int k = min(numerator, denominator);
        for (int i = 1; i < k; i++)
        {
            if (numerator % i == 0 && denominator % i == 0)
            {
                gcd = i;
            }
        }
        numerator = numerator / gcd;
        denominator = denominator / gcd;
        return;
    }

    void add(fraction const &f2)
    {
        int lcm = denominator * f2.denominator;
        int num = ((lcm / denominator) * numerator) + (lcm / (f2.denominator) * f2.numerator);

        numerator = num;
        denominator = lcm;

        simplify();
        return;
    }

    void multiply(fraction const &f2){
        numerator=numerator*f2.numerator;
        denominator=denominator*f2.denominator;

        simplify();
        return;
    }
};