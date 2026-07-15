class Solution {
    public int smallestDivisor(int[] nums, int threshold) {
        int n=nums.length;
        int ans=0,sum=0;
        int l=1,h=nums[0];

        for(int num:nums){
            h=Math.max(h,num);
        }

        while(l<=h){
            int mid=l+(h-l)/2;
            sum=0;
            for(int num:nums){
                sum+=(long)(num+mid-1)/mid;
            }

            if(sum<=threshold){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
}