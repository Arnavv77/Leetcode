class Solution {
    public int[] singleNumber(int[] nums) {
        int xorAll = 0;
        for (int num : nums) {
            xorAll ^= num;
        }

        int setBit = xorAll & -xorAll;
        int groupa = 0, groupb = 0;
        
        for (int num : nums) {
            if ((num & setBit) != 0) {
                groupa ^= num;
            } else {
                groupb ^= num;
            }
        }

        return new int[]{groupa, groupb};
    }
}