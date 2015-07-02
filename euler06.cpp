

#include <iostream>
#include <string>

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
T solve(T n) {
    T result = 0;
    T accum = 0;

    for (T i = n; i > 1; --i) {
        accum += i;
        result += (i - 1) * accum;
    }

    return result << 1;
}



int main(int argc, const char* argv[]) {

    string line;


    std::getline(cin, line);
    int T = a2num(line.c_str());

    while (T && std::getline(cin, line)) {

        ULONG N = a2num(line.c_str());

        cout << solve(N) << endl;

        --T;
    }


    return 0;
}
