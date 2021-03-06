class Solution {
public:
    int reverse(int x) {
       long int result=0;
        while(x)
        {
            result = result*10 + x%10;
            x/=10;
        }
        if(result> INT_MAX || result < INT_MIN)
            return 0;
        return result;
    }
};