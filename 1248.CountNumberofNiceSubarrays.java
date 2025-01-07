class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        int n = nums.length;
        int[] cnt = new int[n + 1];
        cnt[0] = 1;
        int ans = 0, t = 0;
        for (int v : nums) {
            t += v & 1;
            if (t - k >= 0) {
                ans += cnt[t - k];
            }
            cnt[t]++;
        }
        return ans;
    }
}

public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test case 1
        int[] nums1 = {1, 1, 2, 1, 1};
        int k1 = 3;
        int result1 = solution.numberOfSubarrays(nums1, k1);
        System.out.println("Result for test case 1: " + result1);  // Expected output: 2

        // Test case 2
        int[] nums2 = {2, 4, 6};
        int k2 = 1;
        int result2 = solution.numberOfSubarrays(nums2, k2);
        System.out.println("Result for test case 2: " + result2);  // Expected output: 0

        // Test case 3
        int[] nums3 = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
        int k3 = 2;
        int result3 = solution.numberOfSubarrays(nums3, k3);
        System.out.println("Result for test case 3: " + result3);  // Expected output: 16

        // Additional test cases
        int[] nums4 = {1, 2, 3, 4, 5};
        int k4 = 2;
        int result4 = solution.numberOfSubarrays(nums4, k4);
        System.out.println("Result for test case 4: " + result4);  // Additional test case output

        int[] nums5 = {1, 1, 1, 1, 1};
        int k5 = 1;
        int result5 = solution.numberOfSubarrays(nums5, k5);
        System.out.println("Result for test case 5: " + result5);  // Additional test case output
    }
}
