#include <iostream>
using namespace std;


class LinkedList {

struct Node {
    int data;
    Node* next_node;
};

private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}//constructor

    void pushBack(int value) //add node to back of list
	{
        Node* new_node = new Node;
        new_node->data = value;
        new_node->next_node = nullptr;

        if (!head) {//if list is empty
            head = tail = new_node;
        } else {
            tail->next_node = new_node;
            tail = new_node;
        }
    }

    void deleteFront()  //delete head node
	{
        if (!head) { //if list is empty
            cout << "list is empty" << endl;
            return;
        }

        Node* temp = head;
        head = head->next_node;
        delete temp;
    }

    void deleteBack() //delete tail node
	{
        if (!head) {
            cout << "list empty" << endl;
            return;
        }

        if (head == tail) {//if list only has one element
            delete head;
            head = tail = nullptr;
            return;
        }

        Node* second_last = head;
        while (second_last->next_node != tail) {
            second_last = second_last->next_node;
        }

        delete tail;
        tail = second_last;
        tail->next_node = nullptr;
    }
	
	int getCount()
	{
    	int count = 0; 
   	 	Node* current = head; 
		while (current != NULL) {
        	count++;
        	current = current->next_node;
    	}
	    return count;
	}

    void displayList() 
	{
        Node* current = head;
		cout << endl << "Current list " << endl;
        while (current) {
            cout << current->data << " ";
            current = current->next_node;
        }
        cout << endl;
    }

    // destructor
    ~LinkedList() 
	{
        while (head) {
            Node* temp = head;
            head = head->next_node;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;

    while (true) {
		cout << endl;
        cout << "Choose an option:" << endl;
        cout << "add data to the back: 1" << endl;
        cout << "delete data from the back: 2" << endl;
        cout << "delete data from the front: 3" << endl;
        cout << "display the current list: 4" << endl;
		cout << "display current count of nodes: 5" << endl;
        cout << "quit: 6   Enter here: ";

		
        int usr_choice;
        cin >> usr_choice;
        switch (usr_choice) {
            case 1:
                int add_value;
                cout << "Enter an int you want added to list: ";
                cin >> add_value;
                list.pushBack(add_value);
                break;
            case 2:
                list.deleteFront();
                break;
            case 3:
                list.deleteBack();
                break;
            case 4:
                list.displayList();
                break;
            case 5:
				cout << "Number of nodes in list " << list.getCount() << endl;
				break;
			case 6:
                return 0;
            default:
                cout << "invalid choice." << endl;
        }
    }

    return 0;
}

