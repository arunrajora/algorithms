
// Stack

#include<iostream>
using namespace std;

struct node{
	int data;
	node* next;
	node* prev;
};

class stack{
	public:
		node* root;
		int count;
		
		stack(){
			root=NULL;
			count=0;
		}
		
		//true for empty
		bool isempty(){
			return root==NULL;
		}
		
		int size(){
			return count;
		}
		
		void push(int val){
			node *x=new node();
			if(x==NULL){
				throw "memory limit exceeded";
			}
			x->data=val;
			x->prev=NULL;
			x->next=root;
			root=x;
			count++;
		}
		
		int pop(){
			if(root==NULL){
				throw "underflow";
			}
			int val=root->data;
			node* x=root;
			if(x->next==NULL){
				root=NULL;
			}
			else{
				x->next->prev=NULL;
				root=x->next;
			}
			delete x;
			count--;
			return val;
		}
		
};
int main(){
	stack x;
	x.push(1);
	x.push(2);
	x.push(3);
	cout<<x.size()<<endl;
	cout<<x.pop()<<endl;
	cout<<x.pop()<<endl;
	cout<<x.pop()<<endl;
	x.push(100);
	cout<<x.pop()<<endl;
	
}
