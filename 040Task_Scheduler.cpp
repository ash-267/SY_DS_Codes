/*TITLE: Simple Task Scheduler*/
/*PROBLEM STATEMENT:
 Simple Task Scheduler:
 Write a program that implements a simple task scheduler using a singly linked list. Each
 node in the linked list represents a task with its priority and execution time. Tasks are 
 scheduled based on their priority, with higher priority tasks being executed first.
*/

#include <iostream>
#include <string>

using namespace std;


class Node {
public:
    string task_name;
    int priority;
    int exe_time;
    Node* next;

    Node(string tn, int p, int e) {
        task_name = tn;
        priority = p;
        exe_time = e;
        next = NULL;
    }
};

class TaskScheduler {
private:
    Node* head;
public:
    TaskScheduler() {
        head = NULL;
    }

    
    void create() {
        char ch;
        do {
            Node* newnode = getnode(); 
            insert_node(newnode); 
            cout << "\nDo you want to add more tasks? (y/n): ";
            cin >> ch;
        } while (ch == 'y' || ch == 'Y');
    }


    Node* getnode() {
        string tn;
        int p, e;
        cout << "\nEnter task name: ";
        cin >> tn;
        cout << "Enter priority: ";
        cin >> p;
        cout << "Enter execution time: ";
        cin >> e;
        Node* newnode = new Node(tn, p, e);
        return newnode;
    }

    void insert_node(Node* newnode) {
        if (head == NULL || newnode->priority > head->priority) {
            newnode->next = head;
            head = newnode;
        } else {
            Node* temp = head;
            while (temp->next != NULL && temp->next->priority >= newnode->priority) {
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }

    void display() {
        if (head == NULL) {
            cout << "\nNo tasks scheduled!\n";
        }
        cout << "\nScheduled Tasks:\n";
        Node* temp = head;
        while (temp != NULL) {
            cout << "\nTask: " << temp->task_name << " | \tPriority: " << temp->priority << " | \tExecution Time: " << temp->exe_time << "s\n" << endl;;
            temp = temp->next;
        }
    }

    void delete_node() {
        if (head == NULL) {
        cout << "No tasks to execute!" << endl;
        }
        cout << "\nExecuting Tasks:" << endl;
        while (head != NULL) {
            cout << "Executing '" << head->task_name << "' (Time: " << head->exe_time << "s)\n";
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        cout << "All tasks executed!\n";
    }
};

int main() {
    TaskScheduler scheduler;
    int choice;
    
    do {
        cout << "\n===== Simple Task Scheduler =====" << endl;
        cout << "1. Add Tasks\n2. Display Tasks\n3. Execute All Tasks\n4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                scheduler.create();
                break;
            case 2:
                scheduler.display();
                break;
            case 3:
                scheduler.delete_node();
                break;
            case 4:
                cout << "Thankyou for using task scheduler\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);
return 0;
}
