import java.util.*;
import java.lang.*;
import java.io.*;

/* Log Function:
-> The logarithm is the inverse function to exponentiation. 
-> That means the logarithm of a given number x is the exponent to which another
   fixed number, the base b, must be raised, to produce that number x. 
-> In the simplest case, the logarithm counts the number of occurrences of the
   same factor in repeated multiplication.
   
   Eg. since 1000 = 10x10x10 = 103, the "logarithm to base 10" of 1000 is 3.
   
*/


class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		
		int result;
		
		if(n==0)
		result=1;
		else
		result=(int)Math.floor(Math.log10(n))+1;
		
		System.out.println(result);
	}
}
