class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();
        int[] arr = new int[n];
        List<Integer> last = triangle.get(n-1);
        for (int i = 0; i < last.size(); i++) {
            arr[i] = last.get(i);
        }
        for (int i = n-2; i >= 0; i--) {
            List<Integer> list = triangle.get(i);
            for (int j = 0; j < list.size(); j++) {
                arr[j] = Math.min(arr[j], arr[j+1]) + list.get(j);
            }
        }
        return arr[0];
    }
}
