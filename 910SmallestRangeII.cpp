 int smallestRangeII(vector<int>& nums, int k) {
    int n=nums.size();
    sort(nums.begin(),nums.end());
    int maxE=nums[n-1];
    int minE=nums[0];
    int ans=maxE-minE;
    for(int i=0;i<n-1;i++){
        int currMax=max(maxE-k,nums[i]+k);
        int currMin=min(minE+k,nums[i+1]-k);
        ans=min(currMax-currMin,ans);
          
    }
    return ans;
      
  }