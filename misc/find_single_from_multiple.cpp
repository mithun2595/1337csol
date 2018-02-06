#include <iostream>
#include <vector>
#include <limits.h>
#include <map>
#include <string>

using namespace std;

int find_single(vector<int> nums) {
    int ones = 0, twos = 0;
    int cbm=0;
    for (auto n:nums) {
        twos |= (ones & n);
        ones = ones^n;
        cbm = ~(ones & twos);
        ones &= cbm;
        twos &= cbm;
        cout<<"ones = "<<ones<<" twos = "<<twos<<"\n";
    }
    return ones;
}

int main() {
	// your code goes here
	int n;
	cin >> n;
	vector<int> a(n,0);
	for(int i=0;i<n;i++) {
	    cin>> a[i];
	}
	cout<<find_single(a);
}
