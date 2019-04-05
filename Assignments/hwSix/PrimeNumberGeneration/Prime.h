//
// Prime.h
//

#ifndef PRIMENUMBERGENERATOR_PRIME_H
#define PRIMENUMBERGENERATOR_PRIME_H

#include <iostream>

class Prime{

public:
    void operator()(int num){
        bool isPrime = true;
        for(int i=2;i<=(num/2);++i){
            if((num % i) == 0){
                isPrime = false;
                break;
            }
        }
        if(isPrime){
            std::cout << num << " ";
        }
    }
};

#endif //PRIMENUMBERGENERATOR_PRIME_H
