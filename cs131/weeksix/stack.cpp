#include <iostream>
#include <string>
using namespace std;


class Stack {
private:
	struct Node {
		string data;
		Node* next_node;
        Node(const string& value) : data(value), next_node(nullptr) {}	
	};

    Node* front;
    Node* back;

public:
    Stack() : front(nullptr), back(nullptr) {}//constructor

    ~Stack() { //destructor
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
    void remove()  //delete tail node
	{
		if(!isEmpty()) {
			if(front == back) {
				delete front;
				front = nullptr;
				back = nullptr;
			} else {
        		Node* second_last = front;
				while(second_last->next_node != back) {
					second_last = second_last->next_node;
				}
			
			delete back;
			back = second_last;
			back->next_node = nullptr;
    		}
		}
	}

	string peek()
	{
		if(!isEmpty()) {
			return front->data;
		}
		return " ";
	}
	
	friend ostream& operator<<(ostream& output, const Stack& s) {
		Node* current = s.front;
		while (current != nullptr) {
			output << current->data << " ";
			current = current->next_node;
		}
		return output;
	}
};

int main() {
    Stack s;
	
	s.add("thing1");
	cout << "queue: " << s << endl;
	s.add("thing2");
	cout << "queue: " << s << endl;
	s.add("thing3");
	cout << "queue: " << s << endl;
	s.add("thing4");
	cout << "queue: " << s << endl;

	s.remove();
	cout << "after removing one item: " << s << endl;	

	string front_peek = s.peek();
	cout << "Item in front of queue " << front_peek << endl;
    
	return 0;
}

