class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int fd = 0;
        int td = 0;
        for(int i = 0; i < n; i++) {
            if(bills[i] == 5) {
                fd++;
            }
            else {
                if(bills[i] == 10) {
                    if(fd > 0) {
                        fd--;
                        td++;
                    }
                    else return false;
                }
                else if(bills[i] == 20) {
                    if(td  && fd) {
                        fd--;
                        td--;
                    }   
                    else if(fd >= 3) {
                        fd -= 3;
                    }
                    else return false;
                }
            }
        }
        return true;
    }
};