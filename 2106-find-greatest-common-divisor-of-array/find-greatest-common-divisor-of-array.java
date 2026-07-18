class Solution {
    public int findGCD(int[] nums) {
        int smallest = Integer.MAX_VALUE;
        int largest = Integer.MIN_VALUE;
        for(int value : nums) {
            if(value > largest) largest = value ;
            if(value < smallest) smallest = value;
        }
        return gcd(smallest , largest);
    }
    public static int gcd(int a , int b){
        if(b==0) return a;
        return gcd( b , a%b );
    }
}