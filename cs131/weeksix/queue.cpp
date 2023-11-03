#include <iostream>
#include <string>
using namespace std;


class Queue {
private:
	struct Node {
		string data;
		Node* next_node;
        Node(const string& value) : data(value), next_node(nullptr) {}	
	};

    Node* front;
    Node* back;

public:
    Queue() : front(nullptr), back(nullptr) {}//constructor

    ~Queue() //destructor 
	{
        while (!isEmpty()) {
        	remove();
		}
    }
	
	bool isEmpty() 
	{
		return front == nullptr;
	}


    void add(const string& data) //add node to back of list
	{
		Node* newNode = new Node(data);
		if (isEmpty()) {
            front = newNode;
            back = newNode;
        } else {
            back->next_node = newNode;
            back = newNode;
        }
	}
    void remove()  //delete head node
	{
		if(!isEmpty()) {
       		Node* temp = front;
        	front = front->next_node;
        	delete temp;
		}
    }

	string peek()
	{
		if(!isEmpty()) {
			return front->data;
		}
		return " ";
	}
	
	friend ostream& operator<<(ostream& output, const Queue& q) {
		Node* current = q.front;
		while (current != nullptr) {
			output << current->data << " ";
			current = current->next_node;
		}
		return output;
	}
};

int main() {
    Queue q;
	
	q.add("thing1");
	q.add("thing2");
	q.add("thing3");
	q.add("thing4");
	cout << "queue: " << q << endl;

	q.remove();
	cout << "after removing one item: " << q << endl;	

	string front_peek = q.peek();
	cout << "Item in front of queue " << front_peek << endl;
    
	return 0;
}

