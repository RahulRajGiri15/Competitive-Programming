// User function Template for C#

class Solution {
    // Function to rotate an array by d elements in counter-clockwise direction.
    public void RotateArr(int[] arr, int d) {
        // Code Here
        //List <int> temp = new List<int>();
        int n = arr.Length;
         d = d% n;
          int[] temp = new int[d];
        for(int i=0;i<d;i++){
            //temp.Add(arr[i]);
            temp[i] = arr[i];
        }
        for(int i=d;i<n;i++){
            arr[i-d] = arr[i];
            
        }
        for(int i =0;i<d;i++){
            arr[n-d+i] = temp[i];
        }
        //Console.WriteLine(string.Join(" ", arr));
    }
}