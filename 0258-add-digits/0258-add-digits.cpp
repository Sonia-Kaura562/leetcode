class Solution {
public:
    int digit(int num) {
        if(num <= 0 ) return 0;
        return num%10 + digit(num/10);
    }
    int addDigits(int num) {
        if(num <= 9) return num;
        return addDigits(digit(num));  
    }
};