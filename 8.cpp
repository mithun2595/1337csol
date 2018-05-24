class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        bool is_positive = true;
        while(str[i] == ' ') i++;
        if(str[i] == '-') {
            is_positive = false;
            i++;
        }
        else if(str[i] == '+') {
            is_positive = true;
            i++;
        }
        if(str[i] <= '0' && str[i] >= '9') return 0;
        long long int sol = 0;
        long long int place = 1;
        while(str[i] >='0' && str[i] <= '9') i++;
        i--;
        while(str[i] >='0' && str[i] <= '9') {
            sol = sol + place * (str[i] - '0');
            if(place > INT_MAX and sol < INT_MAX) {
                while(i>=0 && (str[i]=='0' || str[i]==' ')) i--;
                if(i>=0 && str[i] != '-' && str[i] != '+') {
                    if(str[i] >= '0' && str[i] <= '9') {
                            if(is_positive) return INT_MAX;
                            else return INT_MIN;
                    }
                    else return 0;
                }
                else break;
            }
            if(sol >= INT_MAX) {
                if(is_positive) return INT_MAX;
                else if (sol==INT_MAX) return -1*INT_MAX;
                else return INT_MIN;
            }
            place = place * 10;
            i--;
        }
        return is_positive? sol: -1*sol;
    }
};