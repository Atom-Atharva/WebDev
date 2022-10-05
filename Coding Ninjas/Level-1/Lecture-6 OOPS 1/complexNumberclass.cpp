class complexNumbers
{
private:
    int real;
    int imaginary;

public:
    complexNumbers(int real, int imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    }
    void plus(complexNumbers const &c2)
    {
        real = real + c2.real;
        imaginary = imaginary + c2.imaginary;
        return;
    }
    void multiply(complexNumbers const &c2)
    {
        int r = (real * c2.real) - (imaginary * c2.imaginary);
        int i = (real * c2.imaginary) + (imaginary * c2.real);
        real = r;
        imaginary = i;
        return;
    }

    void print()
    {
        cout << real << " + " << imaginary << " i " << endl;
        return;
    }
};