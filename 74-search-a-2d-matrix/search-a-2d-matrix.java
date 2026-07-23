class Solution {
    public boolean searchMatrix(int[][] matrix, int target) 
    {
        int totalRow = matrix.length;
        int totalCol = matrix[0].length;

        int n = totalRow * totalCol;

        int s = 0;
        int e = n-1;

        while(s <= e)
        {
           int mid = s + (e-s)/2;

           int roWIndex = mid / totalCol;
           int colIndex = mid % totalCol;

           if(matrix[roWIndex][colIndex] == target){
            return true;
           } 
           if(matrix[roWIndex][colIndex] < target){
              s = mid + 1;
           }
           else {
            e = mid-1;
           }
        }
        return false;
    }
}