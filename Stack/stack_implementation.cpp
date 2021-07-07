#include <iostream>
using namespace std;

template<typename T> // for generic node 

class node{
public:
	T data;
	node<T>* next;
	node(T x){ // constructor
		data = x;
		next = NULL;
	}
};

template<typename T> // for generic stack
class Stack{
public:
	node<T>* head;

	int count;
	Stack(){ // constructor
		head = NULL;
		count = 0;
	}
    
	void push(T x){
		count++;
		node<T>* n = new node<T>(x);
        if(head == NULL){
        	head = n;
        }
        else{
        	n->next = head;
        	head = n;
        }
	}

	void pop(){
	   if(count>0){
          count--;
          node<T>* temp = head;
          head = head->next;
          delete temp;

        }
	}

	int size(){
         return count;
	}

	bool empty(){
         return head == NULL; // or count == 0
	}

	T top(){ //top element of stack
          return head->data;
	}

};

int main()
{
	Stack<int> s;
    int n; // number of elements
    cin >> n;
    int element;
	for(int i=1;i<=n;i++){
        cin >> element;
		s.push(element);
	}
	
    
    while(!s.empty()){  // print all elements
    	cout << s.top()<<" ";
    	s.pop();
    }
 return 0;
}
