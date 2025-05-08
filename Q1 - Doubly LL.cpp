#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    int ID;
    string Name;
    float Marks;

    Student(int id = 0, string name = "", float marks = 0.0) {
        ID = id;
        Name = name;
        Marks = marks;
    }
};

class Node {
public:
    Student student;
    Node* next;
    Node* prev;

    Node(Student s) : student(s), next(nullptr), prev(nullptr) {}
};

class DoublyLL {
private:
    Node* head;

public:
    DoublyLL() : head(nullptr) {}

    void display();
    void insertAtFront(Student student);
    void insertMiddle(Student student, int position);
    void deleteLast();
    void calculateAverageAndCount();
    void findNode(int);
};

void DoublyLL::display() {
    // Start from the head
    Node* current = head;

    // Check if the list is empty
    if (current == nullptr) {
        cout << "The list is empty." << endl;
        return ;
    }

    // Traverse and display each node's data
    cout << "List of Students:" << endl;
    while (current != nullptr) {
        cout << "ID: " << current->student.ID
             << ", Name: " << current->student.Name
             << ", Marks: " << current->student.Marks << endl;
        current = current->next;
    }
    cout << endl;
}

void DoublyLL::insertAtFront(Student student) {
    // Task 2: Complete this function to insert a student at the front.
    Node* newNode = new Node(student);
    if(head == nullptr){
    	head = newNode;
	}
	else{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
}

void DoublyLL::insertMiddle(Student student, int position) {
    // Task 3: Complete this function to insert a student at a specific position.
    if (position <= 0) {
        cout << "Invalid position." << endl;
    }

    Node* newNode = new Node(student);
    Node* temp = head;
    int count = 1;

    // Insert at position 1 (front)
    if (position == 1) {
        insertAtFront(student);
    }

    // Traverse to the node just before the insertion point
    while (temp != nullptr && count < position - 1) {
        temp = temp->next;
        count++;
    }

    // If the position is valid (i.e., not beyond the list size)
    if (temp != nullptr) {
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    } else {
        cout << "Position out of bounds." << endl;
    }
}

void DoublyLL::findNode(int id) {
    Node* temp = head;

    while (temp != nullptr) {
        if (temp->student.ID == id) {
            cout << "Student found: ID: " << temp->student.ID
                 << ", Name: " << temp->student.Name
                 << ", Marks: " << temp->student.Marks << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Student with ID " << id << " not found." << endl;
}


void DoublyLL::deleteLast() {
    // Task 4: Complete this function to delete the last student.
    if (head == nullptr) {
        cout << "No nodes to delete." << endl;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // If there is only one node in the list
    if (temp->prev == nullptr) {
        head = nullptr;
    } else {
        temp->prev->next = nullptr;
    }

    cout << "Deleted student with ID: " << temp->student.ID << endl;
    delete temp;
}

void DoublyLL::calculateAverageAndCount() {
    // Task 5: Complete this function to calculate the average marks and count of students.
    Node* temp = head;
    int count = 0;
    double avg = 0.0;
    while(temp != nullptr){
    	avg += temp->student.Marks;
    	count++;
    	temp = temp->next;
	}
	avg = avg/count;
	cout << avg << " and " << count;
}

int main() {
    DoublyLL list;

    // Initializing 3 students
    Student s1(1, "Samad", 85.5);
    Student s2(2, "Baba", 90.0);
    Student s3(3, "Harlina", 78.0);

    // Inserting students into the list
    list.insertAtFront(s3);
    list.insertAtFront(s2);
    list.insertAtFront(s1);

    // Tasks to be implemented
    cout << "Initial list of students:" << endl;
    list.display();
    cout << "\nFinding a student with ID 2:" << endl;
    list.findNode(2); // Search for student with ID 2

    cout << "\nInserting a student in the middle:" << endl;
    Student s4(4, "Diana", 88.0);
    list.insertMiddle(s4, 2); // Insert at position 2
    list.display();

    cout << "\nDeleting the last student:" << endl;
    list.deleteLast();
    list.display();

    cout << "\nCalculating average marks and total number of students:" ;
    list.calculateAverageAndCount();

    return 0;
}

