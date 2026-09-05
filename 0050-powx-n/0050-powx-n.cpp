class Solution {
public:
    double myPow(double a, long long b) {
        if(b<0){
            a=1/a;
            b=-b;
        }
        if(b==0) return 1;
        double temp=myPow(a,b/2);
        if(b%2==0) return temp*temp;
        else return temp*temp*a;
        
    }
};