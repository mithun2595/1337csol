class Solution {
public:
    int findMinDist(vector<int> &dp, int row, int pos) {
        int ring_size = dp.size();
        int minDist = INT_MAX;
        for(int i=0; i<dp.size();i++) {
            if(dp[i] != -1) {
                int inner_dist = abs(i-pos);
                int outer_dist = 0;
                if(inner_dist > ring_size/2) {
                    int start = i > pos ? i : pos;
                    int end = i > pos ? pos : i;
                    while((start+outer_dist)%ring_size != end) outer_dist++;
                    outer_dist += dp[i];

                } else {
                    outer_dist = INT_MAX;
                }
                inner_dist += dp[i];
                int curr_min = outer_dist < inner_dist ? outer_dist : inner_dist;
                minDist = minDist < curr_min ? minDist : curr_min;
            }
        }
        return minDist;
    }

    int findRotateSteps(string ring, string key) {
        if (ring.size() == 0 || key.size() == 0) return 0;
        int K = key.size();
        int R = ring.size();
        vector<int> dp(R,-1);
        dp[0] = 0;
        for(int i=0;i<K;i++) {
            vector<int> dp_update(R,-1);
            for(int j=0;j<R;j++) {
                if(key[i] == ring[j]) dp_update[j] = findMinDist(dp, i, j) + 1;
            }
            dp = dp_update;
        }

        int res = INT_MAX;
        for(auto &it : dp) if(it != -1 && it < res) res = it;
        return res;

    }
};