#include <iostream>
#include <vector>
#include <limits.h>
#include <map>
#include <string>

using namespace std;

int find_single_from_twice(vector<int> nums) {
    int exor = 0;
    for (auto n:nums) {
        exor = exor ^ n;
    }
    return exor;
}

int main() {
	// your code goes here
	int n;
	cin >> n;
	vector<int> a(n,0);
	for(int i=0;i<n;i++) {
	    cin>> a[i];
	}
	cout<<find_single_from_twice(a);
}
