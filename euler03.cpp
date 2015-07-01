
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;





typedef unsigned long long ULONG;



void print(const char* comment, const vector<int>& arr) {
    cout << "    // " << comment << endl;
    cout << "    vector<int> " << comment << " = {";
    for (int i = 0; i < arr.size(); ++i) 
        cout << arr[i] << ",";
    cout << "};" << endl;
}


ULONG atoull(const char* line) {
    ULONG result = 0;

    const char* p = line;

    while (*p) {
        result = result * 10 + (ULONG)(*p - 0x30);
        ++p;
    }

    return result;
}


template<class T, class V>
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


template<class T, class V>
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


ULONG solve(ULONG n, const vector<int>& primes) {

    if (is_prime(n, primes))
        return n;


    for (size_t i = 0; i < primes.size(); ++i) {
        int p = primes[i];
        if (0 == (n % p)) {
            ULONG res = n / p;
            return solve(res, primes);
        }
    }

    //
    // I must not be here - error
    //

    return n;
}











int main(int argc, const char* argv[]) {

    string line;

    vector<int> primes = {2,3,5,7,11,13,17,19,23,};

    fill_primes(1000000, primes);  // sqrt(10^12)

    std::getline(cin, line);
    int T = atoi(line.c_str());

    while (T && std::getline(cin, line)) {

        ULONG N = atoull(line.c_str());

        cout << solve(N, primes) << endl;

        --T;
    }

//    print("primes", primes);

    return 0;
}
