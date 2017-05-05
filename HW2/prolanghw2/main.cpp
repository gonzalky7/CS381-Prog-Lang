//
//  main.cpp
//  prolanghw2
//
//  Created by Kyleen Gonzalez on 4/12/17.
//  Copyright © 2017 Kyleen Gonzalez. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    float base;
    int exponent;
    long double result = 1.0;
    int initialExp;
    
    
    char Character;
    
    Character=66;
    
    cout << Character;
    
    cout.precision(100);
    
   cout <<"Enter base: ";
   cin >> base;
   cout <<"Enter exponent:";
   cin >> exponent;
    
    initialExp = exponent;
    
    
    if (exponent == 0) {
        cout << base << " raised to "<<exponent << " is: " << "1\n";
        return 0;
    }
    
    while (exponent > 0) {
        result *= base;
            --exponent;
    }
    
    while (exponent < 0) {
        result *= 1.0/base;
        ++exponent;
    }
    
    cout <<"Decimal Answer: " << fixed <<  result <<"\n";
    
    
    cout <<"Scientific Answer: " << scientific << result <<"\n";
    
       return 0;
}
