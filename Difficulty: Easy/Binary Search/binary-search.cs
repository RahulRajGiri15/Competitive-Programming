class Solution {
    public int binarysearch(int[] arr, int target) {
        // code here
        int n = arr.Length;
        int l = 0, h = n-1;
	    ///bool isfound = false;
	    int result = -1;
		while(l <= h){
		    int mid = l+(h-l)/2;
		    if(arr[mid] == target){
		        //isfound = true;
		      //  isfound = mid;
		      //  break;
		      //return mid;
		      //if(arr[mid-1] == arr[mid]){
		      //    result = arr[mid];
		      //    h = mid-1;
		      //}
		      result = mid;
		      h = mid -1;
		    }
		    else if(arr[mid] > target){
		        h = mid-1;
		    }
		    else if(arr[mid] < target){
		        l = mid+1;
		    }
		}
// 		if(isfound == true){
// 		    Console.WriteLine("Found");
// 		}
// 	    else{
// 	        Console.WriteLine("Not Found");
// 	    }
    return result;
    }
}
