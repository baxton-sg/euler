
#include <cstdlib>
#include <iostream>
#include <string>


using namespace std;


typedef unsigned long long ULONG;


ULONG atoull(const char* line) {
    ULONG result = 0;

    const char* p = line;

    while (*p) {
        result = result * 10 + (ULONG)(*p - 0x30);
        ++p;
    }

    return result;
}



ULONG solve(ULONG& n) {
    ULONG p1 = 1,
          p2 = 1;
    ULONG f = 2;
    ULONG sum = 0;

    while (f < n) {
        if (0 == (f & (ULONG)0x01))
            sum += f;

        p1 = p2;
        p2 = f;
        f = p1 + p2;
    }

    return sum;
}


int main(int argc, const char* argv[]) {
 
    string line;

    std::getline(cin, line);
    int T = atoi(line.c_str());

    while (T && std::getline(cin, line)) {
        ULONG N = atoull(line.c_str());

        cout << solve(N) << endl;

    
        --T;
    }

    return 0;
}

