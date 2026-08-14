class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int ans1=0;
        int ans2=0;
        vector<int> v;
        int i=0,j=0;
        while(i<n1 && j<n2){
            if(nums1[i]==nums2[j]){
                ans1++;
                i++;
                // j++;
            }
            else if(nums1[i]<nums2[j]) i++;
            else{
                j++;
            }
        }
        i=0,j=0;
        while(i<n1 && j<n2){
            if(nums1[i]==nums2[j]){
                ans2++;
                // i++;
                j++;
            }
            else if(nums1[i]<nums2[j]) i++;
            else{
                j++;
            }
        }
        v.push_back(ans1);
        v.push_back(ans2);
        return v;
    }
};