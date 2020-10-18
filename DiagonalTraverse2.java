class Solution {
    public int[] findDiagonalOrder(List<List<Integer>> nums) {
        TreeMap<Integer, List<Integer>> map = new TreeMap<>();
        int i = 0;
        for (List<Integer> list : nums) {
            int j = 0;
            for (Integer asd : list) {
                List<Integer> temp = map.getOrDefault(i+j, new ArrayList<>());
                temp.add(asd);
                map.put(i+j, temp);
                j++;
            }
            i++;
        }

        List<Integer> res = new ArrayList<>();
        for (Map.Entry<Integer, List<Integer>> entry : map.entrySet()) {
            List<Integer> list = entry.getValue();
            Collections.reverse(list);
            res.addAll(list);
        }
        int[] ans = new int[res.size()];
        for (int k = 0; k < ans.length; k++) {
            ans[k] = res.get(k);
        }
        return ans;
    }
}
