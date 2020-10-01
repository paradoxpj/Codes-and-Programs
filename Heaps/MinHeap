import java.lang.*;
import java.io.*;
import java.util.*;

class Heap{
	private int size;
	private int maxsize;
	private int arr[];


	/* It includes functions :
	1. parent 
	2. leftChild
	3. rightChild
	4. isLeaf
	5. swap
	6. minHeapify
	7. minHeap
	8. remove 
	**/

	//constructor 
	public Heap(int maxsize){
		this.maxsize=maxsize;
		arr=new int[maxsize];
		size=-1;
		//Heap[0] = Integer.MIN_VALUE; //dont forget to do this
	}

	public int parent(int i){
	    if(i==0)
	        return 0;
	    else if(i%2==0)
	        return (i>>1)-1;
		return i>>1;
	}

	public int leftChild(int i) {
		return (i<<1)+1;
	}

	public int rightChild(int i){
		return (i<<1 ) +2;
	}

	public boolean isLeaf(int i ){
		boolean flag = false ;
		int l= leftChild(i) ;
		int r= rightChild(i) ;
		if( l > size && r > size )
			flag=true;
		return flag;
	}

	public void swap(int pos, int largest){
	    
		int temp=arr[pos];
		arr[pos]=arr[largest];
		arr[largest]=temp;
	}

	public void minHeapify( int i){
	    
		int smallest=i;
		int left = leftChild(i);
		int right = rightChild(i);
		boolean flag = true;
		//print();
		//System.out.println( "Parent = "+i+" leftChild = "+left+ " rightChild = "+right);
		if(!isLeaf(i)){
		    
			if(left <= size && arr[left] < arr[i]){
				flag=false;
			}
			else if(right <= size && arr[right] < arr[i]){
				flag=false;
			}
			if(!flag){
			    if(arr[right]<arr[left])
			        smallest=right;
			    else smallest=left;
			}
			
			if(smallest!=i){
				swap( i , smallest );
				minHeapify(smallest);
			}
		}
	}

	public void minHeap(){
		for(int i = 0 ; i <= (size/2) ; i++ ) {
			minHeapify(i);
		}
	}

	public void print(){
	for(int i=0;i<=size;i++){
		System.out.print(arr[i]+" ");
	}
	System.out.println();
	}

	public void insert(int x){
		if(size+2 >= maxsize){
			System.out.println("Overflowing");
			return;
		}
		
		size++;
		arr[size]=x;
		int curr=size;
		//heapifyUp
		while(arr[curr]<arr[parent(curr)]){
		    swap(curr,parent(curr));
		    curr=parent(curr);
		    
		}
		

	}

	public int min(){
		return arr[0];
	}

	public int remove(){
		int x=arr[0];
		swap(0,size);
		size--;
		minHeapify(0);
		return x;
	}
}


class test {
    
	public static void main(String args[]){
	    
		Scanner sc= new Scanner(System.in);
		
		System.out.println("Enter size of Heap");
		int n=sc.nextInt();
		
		Heap m=new Heap(n);
		
		System.out.println("enter number of elements to be inserted");
		int x=sc.nextInt();
		
		for(int i =0;i<x;i++){
			m.insert(sc.nextInt());
		}
		System.out.print("heap = ");
		m.print();
		
		m.remove();
		m.print();
		m.remove();
		m.print();

	}
}