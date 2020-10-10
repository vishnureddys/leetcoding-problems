class Solution {
    public int[] maxSlidingWindow(int[] arr, int k) {
        int [] ngr=new int[arr.length];
        Stack<Integer> st=new Stack<>();
        st.push(arr.length-1);
        ngr[arr.length-1]=arr.length;
        for(int i=arr.length-2;i>=0;i--){
            while(st.size()!=0 && arr[i]>=arr[st.peek()]){
                st.pop();
            }
            if(st.size()==0)
                ngr[i]=arr.length;
            else
                ngr[i]=st.peek();
            st.push(i);
        }
        int j=0;
         int l=0;
        int[] maxwindow = new int[arr.length-k+1];
        for(int i=0;i<=arr.length-k;i++){
            if(j<i)
                j=i;
            while(ngr[j]<i+k){
                j=ngr[j];
            }
           
        if(l<maxwindow.length){
            maxwindow[l]=arr[j];
            l++;
        }
        }
       
    return maxwindow;
    }
}
