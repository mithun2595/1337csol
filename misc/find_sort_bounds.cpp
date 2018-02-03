#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

pair<int, int> find_min_max(int l, int r, vector<int>& a) {
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for(int i =l;i<=r;i++) {
        if(a[i]<=mini) mini = a[i];
        if(a[i]>=maxi) maxi = a[i];
    }
    return make_pair(mini,maxi);
}

pair<int,int> find_sort_bounds(vector<int> &a) {
    if(a.size() <= 1) return make_pair(-1,-1);
    int l = 0,r = a.size()-1;
    int left_idx = l, right_idx = r;
    while(l<a.size()-1) {
        if(a[l]>a[l+1]) {left_idx=l;break;}
        l++;
    }
    while(r>1) {
        if(a[r]<a[r-1]) {right_idx=r;break;}
        r--;
    }
    if(l>=r) return make_pair(-1,-1);
    pair<int, int> limits = find_min_max(left_idx,right_idx,a);
    for(int i = 0;i<l;i++) {
        if(a[i]>limits.first) {left_idx = i;break;}
    }
    for(int i = a.size()-1;i>=r;i--) {
        if(a[i]<limits.second) {right_idx = i;break;}
    }
    return make_pair(left_idx,right_idx);
}

int main() {
	// your code goes here
	int n,k;
	cin >> n;
	vector<int> a(n,0);
	for(int i =0;i<n;i++) {
	    cin >> k;
	    a[i] = k;
	}
	pair<int,int> res = find_sort_bounds(a);
	cout<<res.first<<"\t"<<res.second;
	return 0;
}
