#include <iostream>
#include <vector>
#include <limits.h>
#include <map>
#include <string>

using namespace std;

int find_odd(vector<int> &arr) {
    int n = arr.size();
    int res = 0;
    for (int i=0;i<n;i++) {
        res = res^arr[i];
    }
    return res;
}

int main()
{
  vector<int> a = {-2,-2,-2,3,3,1,1,1,1,0,0,0,0,2,2};
  printf("%d",find_odd(a));
  return 0;
}