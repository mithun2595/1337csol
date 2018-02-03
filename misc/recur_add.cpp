#include <iostream>
#include <vector>
using namespace std;


void update_arr(int loc, int sum, vector<int>& a) {
    if(loc >= a.size()) {
        return;
    }
    a[loc] += sum;
    update_arr(loc+1, a[loc], a);
}

vector<int> mod_array(vector<int>& a) {
    if(a.size() <= 1) {
        return a;
    }
    update_arr(0, 0, a);
    return a;
}

int main() {
	// your code goes here
	vector<int> a = {1,2,3,4,5,6};
	vector<int> b = mod_array(a);
    for(auto i : b) {
        cout<<i;
        cout<<"\t";
    }
	return 0;
}
