class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills[0] != 5) return false;
        int n = bills.size();
        int total[2] = {0, 0};
        for(int i = 0; i < n; i++) {
            if(bills[i] == 5) {
                total[0]++;
            }
            else {
                if(bills[i] == 10) {
                    if(total[0] > 0) {
                        total[0]--;
                        total[1]++;
                    }
                    else return false;
                }
                else if(bills[i] == 20) {
                    if(total[1]  && total[0]) {
                        total[0]--;
                        total[1]--;
                    }   
                    else if(total[0] >= 3) {
                        total[0] -= 3;
                    }
                    else return false;
                }
            }
        }
        return true;
    }
};