

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




int main(int argc, const char* argv[]) {

    string line;

    vector<ULONG> numbers = {0ull,
                             1ull,
                             2ull,
                             6ull,
                             12ull,
                             60ull,
                             60ull,
                             420ull,
                             840ull,
                             2520ull,
                             2520ull,
                             27720ull,
                             27720ull,
                             360360ull,
                             360360ull,
                             360360ull,
                             720720ull,
                             12252240ull,
                             12252240ull,
                             232792560ull,
                             232792560ull,
                             232792560ull,
                             232792560ull,
                             5354228880ull,
                             5354228880ull,
                             26771144400ull,
                             26771144400ull,
                             80313433200ull,
                             80313433200ull,
                             2329089562800ull,
                             2329089562800ull,
                             72201776446800ull,
                             144403552893600ull,
                             144403552893600ull,
                             144403552893600ull,
                             144403552893600ull,
                             144403552893600ull,
                             5342931457063200ull,
                             5342931457063200ull,
                             5342931457063200ull,
                             5342931457063200ull,
                           };


    std::getline(cin, line);
    int T = a2num(line.c_str());

    while (T && std::getline(cin, line)) {

        int N = a2num(line.c_str());

        cout << numbers[N] << endl;

        --T;
    }


    return 0;
}
