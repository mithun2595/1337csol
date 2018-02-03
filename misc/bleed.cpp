#include <iostream>
#include <vector>
using namespace std;

int main() {

    int r,c,num;
	cin>>r>>c;
	vector<vector<int> > paper(r, vector<int>(c,0));
	cin>>num;
	for(int i=0;i<num;i++) {
	    int ridx, cidx, darkness;
	    cin>>ridx>>cidx>>darkness;
	    for(int p = 0;p<r;p++) {
	        for(int q = 0;q<c;q++) {
	            paper[p][q] = max(darkness-abs(ridx - p)-abs(cidx-q), paper[p][q]);
	        }
	    }
	}
	long sum =0;
	for(int i=0;i<r;i++)
	    for(int j=0;j<c;j++) c
	        sum += paper[i][j];
	cout<<sum<<"\n";
	return 0;
}

