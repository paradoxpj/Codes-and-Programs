/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */

/* 
->In this we create a max Heap of first K elements of the array.

-> Now, we traverse the remaining elements from kth index to n-1  and we keep on adding the number to max heap if the number is 
greater that the root of max heap .

-> Now, we remove K-1 elements from the heap and now what is left is the Kth largest element if the array.
*/

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int k=sc.nextInt();
		
		int arr[]=new int[n];
		
		for(int i=0;i<n;i++)
		arr[i]=sc.nextInt();
		
		Queue<Integer> heap= new PriorityQueue<>(Collections.reverseOrder());
		
        for(int i=0;i<n;i++)
        {
            heap.add(arr[i]);
        }
        
        int x=0;
        
        for(int i=0;i<k;i++){
            x=heap.poll();
	   }
	   System.out.println(x);
	   
    }
}
