#include <iostream>
using namespace std;
#define max 100
class  dequeue{
	int ar[max];
	int front;
	int rear;
	int size;
	public:
		dequeue(int size){
			front=-1;
			rear=-1;
			
		}
		
//	operation on dequeue
	void insertfront(int i);
	void insertrear(int i);
	void deletefront();
	void deleterear();
	int getFront();
	int getRear();
	
	bool isfull(){
		return (front==0 && rear==size-1);
	}
	
	bool isempty(){
		return (front==-1);
	}
};
//	insert a element at front
	void dequeue::insertfront(int i){
		if(isfull()){
			cout<<"Queue Overflow"<<endl;
		}
		else if(front==-1){
			front=0;
			rear=0;
		}
		else if (front==0){
			front=size-1;
		}
		else 
			front=front-1;
		
		ar[front]=i;		
	}
//	insert a element at rear
	void dequeue ::insertrear(int i){
		if(isfull()){
			cout<<"Queue Overflow"<<endl;
		}
		else if(front==-1){
			front=0;
			rear=0;
		}
		else if(rear==size-1)
			rear=0;
		else{
			rear++;
		}
		ar[rear]=i;
	}
//	Delete a element from front
	void dequeue ::deletefront(){
		if(isempty()){
			cout<<"Queue underflow"<<endl;
		}
		else if(front==rear){
			front=-1;
			rear=-1;
		}
		else if(front==size-1){
			front=0;
		}
		else
			front++;
	}
//	Delete a element from end
	void dequeue::deleterear(){
	
		if(isempty()){
			cout<<"Queue underflow"<<endl;
		}
		else if(front==rear){
			front=-1;
			rear=-1;
		}
		else if(rear==0){
			rear=size-1;
		}
		else{
			rear--;
		}
	}
	int dequeue::getFront(){
		if(isempty()){
			cout<<"Queue underflow"<<endl;
		}
		return ar[front];
	}
	int dequeue::getRear(){
		if(isfull()){
			cout<<"Queue underflow"<<endl;
		}
		return ar[rear];
	}
int main() {
	dequeue d(5);
	cout<<"Insert element 1 at rear "<<endl;
	d.insertrear(1);
	cout<<"Insert element 65 at rear "<<endl;
	d.insertrear(65);
	cout<<"Rear element of dequeue is "<<d.getRear()<<endl;
	cout<<"Delete the front element"<<endl;
	d.deletefront();
	cout<<"New front element is : "<<d.getFront()<<endl;
	return 0;
}
