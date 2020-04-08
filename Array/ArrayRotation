import java.lang.*;
import java.io.*;
import java.util.*;

class ArrayRotation{

	// using Juggling algorithm array 

	public int gcd(int a, int b){
		if(b==0)
			return a;
		else 
			return gcd( b , a%b );
	}

	public static void main(String args[]){

		Scanner sc=new Scanner(System.in);

		System.out.println("Enter Length of Array = ");
		int n=sc.nextInt();

		System.out.println("Enter values of array");
		int arr[]=new int[n];
		for(int i=0;i<n;i++){
			arr[i]=sc.nextInt();
		}

		System.out.print("Enter number of single rotations");
		int d=sc.nextInt();

		int x = gcd( n , d ) ;

		for(int i=0; i< x ; i++){

			int temp=arr[i];
			int j=i;

			while(true){
				int k= j+d;

				if( k > n )
					k=k-n;
				if(k==i)
					break;
				arr[j]=arr[k];
				j=k;
			}
		}

		for(int i=0;i<n;i++){
			System.out.println(arr[i]);
		}

	}
}


// Space Complexity = O(1)
// Time Complexity = O(n)