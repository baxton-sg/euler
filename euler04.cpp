

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;



bool is_palindromic(int n) {
    vector<int> buffer;

    while (n) {
        int d = n % 10;
        n /= 10;

        buffer.push_back(d);
    }

    size_t size = buffer.size();
    int* beg = &buffer[0];
    int* end = &buffer[size-1];

    while (beg < end) {
        if (*beg != *end)
            return false;

        ++beg;
        --end;
    }

    return true;
}

void fill_numbers(vector<int>& numbers) {
    for (int i = 100; i < 1000; ++i) 
        for (int j = 100; j < 1000; ++j) {
            int product = i * j;
            if (is_palindromic(product))
                numbers.push_back(product);
        }

    sort(numbers.begin(), numbers.end());
}


int solve(int n, const vector<int>& numbers) {

    vector<int>::const_iterator it = std::lower_bound(numbers.begin(), numbers.end(), n);

    if (numbers.end() == it)
        return numbers[numbers.size() - 1];
    else {
        while (*it > n) --it;
        return *it;
    }

    return -1;
}



int main(int argc, const char* argv[]) {

    vector<int> numbers;
    fill_numbers(numbers);

    string line;

    std::getline(cin, line);
    int T = atoi(line.c_str());

    while (T && std::getline(cin, line)) {

        int N = atoi(line.c_str());


        cout << solve(N, numbers) << endl;
   
        --T;
    }

    return 0;
}
