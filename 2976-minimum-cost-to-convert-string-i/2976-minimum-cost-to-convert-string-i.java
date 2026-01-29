class Solution {
  void fill(int[][] dist) {
        int V = dist.length; // Number of vertices

        // Floyd-Warshall algorithm
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    // Check if the path through k is shorter
                    if (dist[i][k] != Integer.MAX_VALUE && dist[k][j] != Integer.MAX_VALUE) {
                        dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    }
    public long minimumCost(String source, String target, char[] original, char[] changed, int[] cost) {
        int[][] arr=new int[27][27];
        for(int i=0;i<27;i++) Arrays.fill(arr[i],Integer.MAX_VALUE);
        for(int i=0;i<original.length;i++){
          int f=(int)original[i]-97;
          int t=(int)changed[i]-97;
          int c=cost[i];
          arr[f][t]=Math.min(c,arr[f][t]);
        }
        fill(arr);
        long ans=0;
        for(int i=0;i<source.length();i++){
          if(source.charAt(i)!=target.charAt(i)) {
            int f=(int)source.charAt(i)-97;
            int t=(int)target.charAt(i)-97;
            int s=arr[f][t];
            if(s==Integer.MAX_VALUE) return -1;
            ans+=s;
          }
        }
        return ans;
         
      }
}