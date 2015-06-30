
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


typedef unsigned long long ULONG;


ULONG get_sum(int n, int mul, int m_beg) {

  int m_prev = m_beg - mul;
  ULONG beg = m_prev / mul;
  ULONG end = n / mul - (0 == (n % mul) ? 1 : 0);
  ULONG res = mul * (end*(end+1)/2 - beg*(beg+1)/2);

  return res;
}

void solve(int n, ULONG& sum) {

  ULONG sum3 = get_sum(n, 3, 3);
  ULONG sum5 = get_sum(n, 5, 5);
  ULONG sum15 = get_sum(n, 15, 15);

  sum = sum3 + sum5 - sum15;
}

int main(int argc, const char* argv[]) {

  string line;

  std::getline(cin, line);
  int T = atoi(line.c_str());

  while (T && std::getline(cin, line)) {
      int N = atoi(line.c_str());

      ULONG sum = 0;
      solve(N, sum);
      cout << sum << endl;
      --T;
  }
  return 0;
}
