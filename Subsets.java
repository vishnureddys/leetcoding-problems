class Solution {
    List<List<Integer>> output = new ArrayList();
    
    public List<List<Integer>> subsets(int[] nums) {
        List<Integer> subset = new ArrayList<>();
        helper(nums, subset, 0);
        return output;
    }
    
    public void helper(int[] nums, List<Integer> curr, int i) {
        if (i == nums.length)
            output.add(curr);
        else {
            helper(nums, new ArrayList(curr), i+1);
            curr.add(nums[i]);
            helper(nums, curr, i+1);
            
        }
        
    }
}
