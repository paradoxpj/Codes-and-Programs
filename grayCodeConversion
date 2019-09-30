/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Program for converting a decimal number to its gray code */

/* Gray Code: It is an encoding of numbers so that adjacent numbers have a single digit differing by 1.
 Gray Code of a number can be calculated as follows:
 Let decimal form of number n be B1B2B3B4:
 
 decimal form:  B1     B2      B3     B4
                |  
 Gray Code :    B1     G2      G3     G4
                     B1^B2    B2^B3  B3^B4
*/
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Scanner sc=new Scanner(System.in);
        
        int n=sc.nextInt();
        
         int x=(n>>1)^n;
         
         /*  >> : This is a right shift Operator
         if N=7, then its decimal form will be 0111
         if we do N=N>>1 then N=0011.
         Now, when we will take this N's Xor with the initial value of N, we will get the desired 
         value of our gray code.*/
         System.out.println(x);
        
    }
}

/* For more refer: https://www.elprocus.com/code-converter-binary-to-gray-code-and-gray-code-to-binary-conversion/  
*/
