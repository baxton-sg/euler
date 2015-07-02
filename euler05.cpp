

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef unsigned long long ULONG;

template<typename T=int>
T a2num(const char* line) {
    T result = 0;

    const char* p = line;

    while (*p) {
        result = result * 10 + (T)(*p - 0x30);
        ++p;
    }

    return result;
}



template<typename T=int, typename V=int>
bool is_prime(T n, const vector<V>& primes) {
    if (n <= 1)
        return false;

    if (2 == n)
        return true;

    if (0 == (n & (T)1))
        return false;

    V top = (V)sqrt(n);
    size_t size = primes.size();

    for (size_t i = 0; i < size; ++i) {
        if (primes[i] <= top) {
            if (0 == (n % primes[i]))
                return false;
        }
        else
            break;
    }

    return true;
}


template<typename T=int, typename V=int>
void fill_primes(T n, vector<V>& primes) {

    size_t size = primes.size();
    V start = 3;

    if (!size)
        primes.push_back(2);
    else
        start = primes[size-1] + 2;   
 
    for (T i = start; i <= n; i += 2) {
        if (is_prime(i, primes))
            primes.push_back(i);
    }
}


template<typename T=int, typename V=int>
void get_factors(T n, vector<V>& factors, const vector<V>& primes) {
    if (is_prime(n, primes)) {
        factors.push_back(n);
        return;
    }

    for (size_t i = 0; i < primes.size(); ++i) {
        V p = primes[i];

        if (0 == (n % p)) {
            factors.push_back(p);
            get_factors(n / p, factors, primes);
            break;
        }
    }    
}


template<typename V>
void merge_factors(vector<V>& factors, const vector<V>& to_add) {
    vector<V> tmp;

    typename vector<V>::const_iterator p1 = factors.begin();
    typename vector<V>::const_iterator p2 = to_add.begin();

    while(p1 != factors.end() && p2 != to_add.end()) {
        if (*p1 == *p2) {
            tmp.push_back(*p1);
            ++p1;
            ++p2;
        }
        else {
            if (*p1 < *p2) {
                tmp.push_back(*p1);
                ++p1;
            }
            else {
                tmp.push_back(*p2);
                ++p2;
            }
        }
    }


    while(p1 != factors.end()) {
        tmp.push_back(*p1);
        ++p1;
    }

    while(p2 != to_add.end()) {
        tmp.push_back(*p2);
        ++p2;
    }

    factors.swap(tmp);
}
    


template<typename T=int, typename V=int>
T solve(T n, const vector<V>& primes) {

    vector<V> factors;
    vector<V> tmp;

    for (int number = 2; number <= n; ++number) {
        get_factors(number, tmp, primes);
        merge_factors(factors, tmp);
        tmp.clear();
    }

    T result = (T)1;

    for (size_t i = 0; i < factors.size(); ++i) {
        result *= factors[i];
        //cout << factors[i] << endl;
    }

    return result;
}







int main(int argc, const char* argv[]) {

    string line;

    vector<int> primes = {2,3,5,7,11,13,17,19,23,};
    //fill_primes(7, primes);  // sqrt 40 enough to find prime factors

    std::getline(cin, line);
    int T = a2num(line.c_str());

    while (T && std::getline(cin, line)) {

        ULONG N = a2num(line.c_str());

        cout << solve(N, primes) << endl;

        --T;
    }


    return 0;
}
