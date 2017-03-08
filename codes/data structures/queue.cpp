
// Queue

#include<iostream>
using namespace std;

struct node{
	int data;
	node* next;
	node* prev;
};

class queue{
	public:
		node* root;
		node* tail;
		int count;
		
		queue(){
			root=NULL;
			tail=NULL;
			count=0;
		}
		
		//true for empty
		bool isempty(){
			return root==NULL;
		}
		
		int size(){
			return count;
		}
		
		void enqueue(int val){
			node *x=new node();
			if(x==NULL){
				throw "memory limit exceeded";
			}
			x->data=val;
			x->prev=tail;
			x->next=NULL;
			if(tail!=NULL){
				tail->next=x;
			}
			if(root==NULL){
				root=x;
			}
			tail=x;
			count++;
		}
		
		int dequeue(){
			if(root==NULL){
				throw "underflow";
			}
			int val=root->data;
			node* x=root;
			if(x->next==NULL){
				root=NULL;
				tail=NULL;
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
	queue x;
	x.enqueue(1);
	x.enqueue(2);
	x.enqueue(3);
	cout<<"size"<<x.size()<<endl;
	cout<<x.dequeue()<<endl;
	cout<<x.dequeue()<<endl;
	cout<<x.dequeue()<<endl;
	x.enqueue(100);
	cout<<x.dequeue()<<endl;
	
}
