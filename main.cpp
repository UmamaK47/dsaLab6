#include<iostream>
typedef double itemType;
using namespace std;

struct Node {
	itemType data;
	Node* next;
};

class List {
private:
	Node* head = nullptr;
	Node* tail = nullptr;
public:
	void insertAtStart(itemType element);
	itemType deleteAtStart();
	void insertAtEnd(itemType element);
	itemType deleteAtEnd();
	void insertAfter(int position, itemType newElement);
	itemType deleteAfter(int position);
	void display();
	bool isEmpty();
};
void List::insertAtStart(itemType element) {
	Node *newNode = new Node();
	newNode->data = element;
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	}
	else {
		newNode->next = head;
		head = newNode;
	}
	if (newNode->next == nullptr) {
		tail = newNode;
	}
	cout << "Inserted Successfully\n";
}
itemType List::deleteAtStart() {
	if (isEmpty()) {
		cout << "LIST IS EMPTY\n";
		return NULL;
	}
	itemType data = head->data;
	Node* temp = head;
	head = head->next;
	delete temp;
	cout << "\nRemoved Successfully";
	return data;
}
void List::insertAtEnd(itemType element) {
	Node* newNode = new Node();
	newNode->data = element;
	newNode->next = nullptr;
	if (tail == nullptr) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
	cout << "Inserted Successfully\n";
}
itemType List::deleteAtEnd() {
	if (isEmpty()) {
		cout << "LIST IS EMPTY\n";
		return NULL;
	}
	itemType data = tail->data;
	if (head == tail) {
		delete head;
	}
	else {
		Node* temp = head;
		while (temp->next != tail) {
			temp = temp->next;
		}
		delete tail;
		tail = temp;
		tail->next = nullptr;
		return data;
	}
	cout << "Removed Successfully\n";
}
void List::insertAfter(int position, itemType newElement) {
	Node* newNode = new Node();
	newNode->data = newElement;
	Node* current = head;
	for (int i = 0; i < position&& current != nullptr; i++) {
		current = current->next;
	}
	
	if (current == nullptr) { 
		cout << "Position not found\n";
		return;
	}
	newNode->next = current->next;
	current->next = newNode;
	cout << "Inserted Successfully\n";
	if (newNode->next == nullptr) {
		tail = newNode;
	}
}
itemType List::deleteAfter(int position) {
	itemType data;
	Node* current = head;
	if (isEmpty()) {
		cout << "List is empty\n";
		return NULL;
	}
	for (int i = 0; i < position && current != nullptr; i++) {
		current = current->next;
	}
	
	//if the previous element is not found
	if (current == nullptr) {
		cout << "Position not found\n";
		return NULL;
	}
	//if next element dosent exist
	if (current->next == nullptr) {
		cout << "No element exists after this position\n";
		return NULL;
	}
	else {
		Node* temp = current->next;
		data = temp->data;
		current->next = temp->next;
		delete temp;
		return data;
	}
	cout << "Removed Successfully\n";
}
void List::display(){
	if (isEmpty()) {
		cout << "LIST IS EMPTY.\n";
		return;
	}

	Node* current = head;
	while (current != nullptr) {
		cout << "Data: " << current->data << "\n";
		current = current->next;
	}
}
bool List::isEmpty() {
	return head == nullptr;
}

int main() {
	List list;
	itemType data;
	string choice;
	int pos;
	char con = 'y';

	do {
		cout << "Select one of the following:\n";
		cout << "1. INSERT at START of List\n2. INSERT at END of List\n3. INSERT AFTER a Specific element of List\n4. DELETE from START of List \n5. DELETE from END of List\n6. DELETE AFTER a specific element in List\n7. Display List";
		cout << "\nEnter your choice: ";
		cin >> choice;
		
		if (choice == "1") {
			cout << "\nEnter Number you wish to insert: ";
			
			while (!(cin >> data)) {
				cout << "Invalid input. Please enter an integer: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			list.insertAtStart(data);
		}
		else if (choice == "2") {
			cout << "\nEnter Number you wish to insert: ";
			
			while (!(cin >> data)) {
				cout << "Invalid input. Please enter an integer: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			list.insertAtEnd(data);

		}
		else if (choice == "3") {
			
			cout << "\nEnter Number you wish to insert: ";
			
			while (!(cin >> data)) {
				cout << "Invalid input. Please enter an integer: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "\nEnter position: ";
			
			while (!(cin >> pos)) {
				cout << "Invalid input. Please enter an integer: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			list.insertAfter(pos, data);
		}
		else if (choice == "4") {
			double num = list.deleteAtStart();
			if (num!=NULL) {
				cout << "\nDeleted Number: " << num;
			}
		}
		else if (choice == "5") {
			double num=list.deleteAtEnd();
			if (num!=NULL) {
				cout << "\nDeleted Number: " << num;
			}
		}
		else if (choice == "6") {
			cout << "\nEnter position: ";
			cin>>pos;
			double num = list.deleteAfter(pos);
			if (num != NULL) { 
				cout << "\nDeleted Number: " << num;
			}
			else {}
		}
		else if (choice == "7") {
			list.display();
		}
		else {
			cout << "Invalid choice";
		}
		do {
			cout << "\nWould you like to continue? (Y/N): ";
			cin >> con;
			if (con != 'y' && con != 'Y' && con != 'n' && con != 'N') {
				cout << "Invalid input: please enter Y or N." << endl;
			}

		} while (con != 'y' && con != 'Y' && con != 'n' && con != 'N');
	} while (con == 'y' || con == 'Y');
	cout << "Exiting Program..." << endl;
	return 0;
}
