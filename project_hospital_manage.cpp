#include <iostream>
#include <string>

using namespace std;

// Structure for disease details
struct Disease {
    string name;

    Disease(const string& n) : name(n) {}
};

// Structure for patient details
struct Patient {
    int id;
    string name;
    int priority; 
    Disease* disease; 
    Patient* next;

    Patient(int id_, const string& name_, int priority_, Disease* d = NULL) 
        : id(id_), name(name_), priority(priority_), disease(d), next(NULL) {}
};

// Queue class using linked list
class Queue {
private:
    Patient* front;
    Patient* rear;

public:
    Queue() : front(NULL), rear(NULL) {}

    // Enqueue patient
    void enqueue(int id, const string& name, int priority, Disease* disease) {
        Patient* newPatient = new Patient(id, name, priority, disease);
        if (rear == NULL) {
            front = rear = newPatient;
        } else {
            rear->next = newPatient;
            rear = newPatient;
        }
    }

    // Dequeue patient
    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty!\n";
            return;
        }
        Patient* temp = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
    }

    // Check if queue is empty
    bool isEmpty() const {
        return front == NULL;
    }

    // Display the queue
    void display() const {
        if (front == NULL) {
            cout << "Queue is empty!\n";
            return;
        }
        Patient* temp = front;
        while (temp != NULL) {
            cout << "Patient ID: " << temp->id << ", Name: " << temp->name 
                 << ", Priority: " << temp->priority;
            if (temp->disease) {
                cout << ", Disease: " << temp->disease->name;
            }
            cout << "\n";
            temp = temp->next;
        }
    }

    // Get front patient
    Patient* getFront() {
        return front;
    }
};

// Priority Queue class using linked list
class PriorityQueue {
private:
    Patient* head;

public:
    PriorityQueue() : head(NULL) {}

    // Enqueue patient based on priority
    void enqueue(int id, const string& name, int priority, Disease* disease) {
        Patient* newPatient = new Patient(id, name, priority, disease);
        if (head == NULL || head->priority < priority) {
            newPatient->next = head;
            head = newPatient;
        } else {
            Patient* temp = head;
            while (temp->next != NULL && temp->next->priority >= priority) {
                temp = temp->next;
            }
            newPatient->next = temp->next;
            temp->next = newPatient;
        }
    }

    // Dequeue highest priority patient
    void dequeue() {
        if (head == NULL) {
            cout << "Priority queue is empty!\n";
            return;
        }
        Patient* temp = head;
        head = head->next;
        delete temp;
    }

    // Check if priority queue is empty
    bool isEmpty() const {
        return head == NULL;
    }

    // Display the priority queue
    void display() const {
        if (head == NULL) {
            cout << "Priority queue is empty!\n";
            return;
        }
        Patient* temp = head;
        while (temp != NULL) {
            cout << "Patient ID: " << temp->id << ", Name: " << temp->name 
                 << ", Priority: " << temp->priority;
            if (temp->disease) {
                cout << ", Disease: " << temp->disease->name;
            }
            cout << "\n";
            temp = temp->next;
        }
    }

    // Treat patient with the highest priority
    void treatPatient() {
        if (head == NULL) {
            cout << "Priority queue is empty!\n";
            return;
        }

        // Check if the highest priority has duplicates
        int highestPriority = head->priority;
        Patient* temp = head;
        int count = 0;

        while (temp != NULL && temp->priority == highestPriority) {
            count++;
            temp = temp->next;
        }

        if (count > 1) {
            // Multiple patients with the same priority
            cout << "Multiple patients with the same highest priority. Please choose one:\n";
            temp = head;
            for (int i = 1; i <= count; i++) {
                cout << i << ". Patient ID: " << temp->id << ", Name: " << temp->name << "\n";
                temp = temp->next;
            }
            int choice;
            cout << "Enter your choice (1-" << count << "): ";
            cin >> choice;

            // Locate the chosen patient
            Patient* selected = head;
            Patient* prev = NULL;
            for (int i = 1; i < choice; i++) {
                prev = selected;
                selected = selected->next;
            }

            // Remove the selected patient from the queue
            if (prev == NULL) { 
                head = head->next;
            } else {
                prev->next = selected->next;
            }

            delete selected;
            cout << "Treating patient: " << head->name << "\n";
        } else {
            // Only one patient with the highest priority
            cout << "Treating patient: " << head->name << "\n";
            dequeue();
        }
    }

    // Get front patient in priority queue
    Patient* getFront() {
        return head;
    }
};

// Hospital Management System class
class HospitalManagementSystem {
private:
    Queue regularQueue;
    PriorityQueue priorityQueue;
    int patientID;

public:
    HospitalManagementSystem() : patientID(1) {}

    // Register a patient
    void registerPatient(const string& name, int priority, const string& diseaseName) {
        if (name.empty() || priority < 1 || priority > 10) {
            cout << "Invalid input data.\n";
            return;
        }

        Disease* disease = new Disease(diseaseName);
        if (priority > 5) {
            priorityQueue.enqueue(patientID, name, priority, disease);
            cout << "Patient " << name << " registered in priority queue with priority " << priority << ".\n";
        } else {
            regularQueue.enqueue(patientID, name, priority, disease);
            cout << "Patient " << name << " registered in regular queue.\n";
        }
        patientID++;
    }

    // Treat a patient
    void treatPatient() {
        if (!priorityQueue.isEmpty()) {
            priorityQueue.treatPatient();
        } else if (!regularQueue.isEmpty()) {
            cout << "Treating regular patient: " << regularQueue.getFront()->name << "\n";
            regularQueue.dequeue();
        } else {
            cout << "No patients to treat.\n";
        }
    }

    // Display all patients
    void displayPatients() {
        cout << "\nPriority Queue Patients:\n";
        priorityQueue.display();
        cout << "\nRegular Queue Patients:\n";
        regularQueue.display();
    }
};

// Main function
int main() {
    HospitalManagementSystem hospital;

    int choice;
    string name;
    int priority;
    string diseaseName;

    do {
        cout << "\nHospital Management System\n";
        cout << "1. Register Patient\n";
        cout << "2. Treat Patient\n";
        cout << "3. Display Patients\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter patient name: ";
                cin.ignore();  
                getline(cin, name);  
                cout << "Enter patient priority (1-10): ";
                cin >> priority;
                cout << "Enter disease name: ";
                cin.ignore(); 
                getline(cin, diseaseName);  
                hospital.registerPatient(name, priority, diseaseName);
                break;
            case 2:
                hospital.treatPatient();
                break;
            case 3:
                hospital.displayPatients();
                break;
            case 4:
                cout << "Exiting the system.\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}


