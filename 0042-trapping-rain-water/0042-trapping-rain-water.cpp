class Solution {
public:
    int trap(vector<int>& height){
        //previous greatest element in array
        int n=height.size();
        vector<int> v(n);
        int max=height[0];
        v[0]=-1;
        for(int i=1;i<n;i++){
            v[i]=max;
            if(max<height[i]){
                max=height[i];
            }
        }
        //next greatest element in array
        // int next[n];
        vector<int> v1(n);
        v1[n-1]=-1;
        max=height[n-1];
        for(int i=n-2;i>=0;i--){
            v1[i]=max;
            if(max<height[i]){
                max=height[i];
            }
        }
        for(int i=0;i<n;i++){
            v[i]=min(v[i],v1[i]);
        }
        // calculating water
        int water=0;
        for(int i=0;i<n;i++){
            if(height[i]<v[i]){
                water+=v[i]-height[i];
            }
        }
        return water;
    }
};