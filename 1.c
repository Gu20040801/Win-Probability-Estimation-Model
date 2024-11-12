#include "1.h"

unsigned __int128 factorial1(int n){
    unsigned __int128 r = 1;
    for(int i = 1; i <= n; i++){
        r *= i;
    }
    return r;
}


unsigned long long n_choose_r(int n, int r){
    assert((n > 0)&&(r > 0)&&(r <= n));
    return(unsigned long long)(factorial1(n)/(factorial1(r)*factorial1(n-r)));
}

long double tennis_game(float f){
    f = f/100;
    assert(0 <= f && f <= 1);
    return 100 * pow(f, 4) * (1 + 4 * (1 - f) + (10 * pow((1 - f), 2)) / (1 - 2 * f * (1 - f)));
}

long double tennis_set(float f){
    assert(0 <= f && f <= 100);
    long double p = tennis_game(f) / 100;
    long double result = 0.0;
    for(int i = 0; i <= 4; i++){
        result += n_choose_r((5 + i), 5) * pow((1 - p), i) * pow(p, 6);
    }
    result += n_choose_r(10, 5) * pow(p, 7) * pow((1 - p), 5);
    result += 2 * n_choose_r(10, 5) * pow(p, 7) * pow((1 - p), 6);
    return 100 * result;
}

long double tennis_match(float f){
    assert(0 <= f && f <= 100);
    long double p = tennis_set(f) / 100;
    long double result = 0.0;
    for(int i = 0; i <= 2; i++){
        result += n_choose_r((2 + i), 2) * pow(p, 3) * pow((1 - p), i);
    }
    return 100 * result;
}
