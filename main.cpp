//
//  main.cpp
//  Complex
//
//  Created by Сурков Дмитрий Валерьевич on 19.02.2018.
//  Copyright © 2018 Сурков Дмитрий Валерьевич. All rights reserved.
//
#include <iostream>
#include <sstream>

using namespace std;

struct complex_t
{
    float real;
    float imag;
    
    complex_t()
    {
        real = 0.0f;
        imag = 0.0f;
    }
    
    complex_t add( complex_t other ) const
    {
        complex_t result;
        result.real = real + other.real;
        result.imag = imag + other.imag;
        return result;
    }
    
    complex_t sub( complex_t other ) const
    {
        complex_t result;
        result.real = real - other.real;
        result.imag = imag - other.imag;
        return result;
    }
    
    complex_t mult( complex_t other ) const
    {
        complex_t result;
        result.real = real * other.real - imag * other.imag;
        result.imag = real * other.imag - imag * other.real;
        return result;
    }
    
    complex_t div( complex_t other ) const
    {
        complex_t result;
        result.real = (real * other.real + imag * other.imag)/(other.real * other.real - other.imag * other.imag);
        result.imag = (imag * other.real - real * other.imag)/(other.real * other.real - other.imag * other.imag);
        return result;
    }
    
    istream & read(istream & stream)
    {
        char op;
        return stream >> op >> real >> op >> imag >> op;
    }
    
    ostream & write(ostream & stream ) const
    {
        return stream << "(" << real << "," << imag << ")";
    }
};

int main()
{
    complex_t x, y;
    char op;
    
    // std::cin (1, 2) + (3, 4)\n
    // stream
    
    std::string line;
    std::getline( std::cin, line );
    // std::cin
    // line "(1, 2) + (3, 4)"
    // stream
    std::istringstream stream( line );
    // std::cin
    // line "(1, 2) + (3, 4)"
    // stream (1, 2) + (3, 4)
    
    if (x.read(stream) && (stream >> op) && y.read(stream)) 
    {
        complex_t result;
        switch (op)
        {
            case '+':
            {
                result = x.add(y);
                result.write(cout);
                break;
            }
            case '-':
            {
                result = x.sub(y);
                result.write(cout);
                break;
            }
            case '*':
            {
                result = x.mult(y);
                result.write(cout);
                break;
            }
            case '/':
            {
                result = x.div(y);
                result.write(cout);
                break;
            }
            default: 
            {
                cout << "An error has occured while reading input data" << endl;
                break;
            }
        }
    }

    std::cin.get();
}
