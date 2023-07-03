public class problem5 {
    public static int main(int[] nums) {
        
     if (nums == null || nums.length == 0) {
            return 0;
        }
        
        int n = nums.length;
        int[] dp = new int[n];
        
        dp[0] = 1;
        int maxLength = 1;
        
        for (int i = 1; i < n; i++) {
            dp[i] = 1;
            
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
            
            if (dp[i] > maxLength) {
                maxLength = dp[i];
            }
        }
        
        return maxLength;
    }
    
    public static void main(String[] args) {
        int[] nums = { 10, 22, 9, 33, 21, 50, 41, 60 };
        int maxLength = main(nums);
        
        System.out.println("Length of the longest increasing subsequence: " + maxLength);
    }
}
