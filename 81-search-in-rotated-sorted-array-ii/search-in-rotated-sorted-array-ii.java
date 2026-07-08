class Solution {
    public boolean search(int[] nums, int target) {
        HashSet<Integer> m=new HashSet<>();    // using HashSet
        for(int i=0;i<nums.length;i++){
            m.add(nums[i]);             // Built-in Java function to add the numbers directly into Set
        }
        return m.contains(target);      // Same built-in function to search if element is there
    }
}