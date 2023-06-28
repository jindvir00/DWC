/*
A data structure needs to be implemented in such a way that we have the references i.e. the addresses of the values. None of the addresses are in a continuous memory block. Each time a new value needs to be stored, we need to allocate memory. Write a program to implement the following:

Addition of a new value at a given position
Print all the values in the list
Delete a given value from a a location
*/

#include <iostream>

struct Node {
    int value;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void add_value_at_position(int value, int position) {
        Node* new_node = new Node;
        new_node->value = value;
        new_node->next = nullptr;

        // If the list is empty, set the new node as the head
        if (head == nullptr) {
            head = new_node;
        } else {
            // Traverse to the desired position
            Node* current = head;
            Node* prev = nullptr;
            int count = 0;

            while (current != nullptr && count < position) {
                prev = current;
                current = current->next;
                count++;
            }

            // Insert the new node at the desired position
            if (prev == nullptr) {
                new_node->next = head;
                head = new_node;
            } else {
                prev->next = new_node;
                new_node->next = current;
            }
        }
    }

    void print_values() {
        Node* current = head;

        std::cout << "Values in the list: ";
        while (current != nullptr) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void delete_value_at_position(int position) {
        if (head == nullptr)
            return;

        Node* current = head;
        Node* prev = nullptr;
        int count = 0;

        // Traverse to the desired position
        while (current != nullptr && count < position) {
            prev = current;
            current = current->next;
            count++;
        }

        // Delete the node at the desired position
        if (current == nullptr)
            return;

        if (prev == nullptr) {
            head = current->next;
        } else {
            prev->next = current->next;
        }

        delete current;
    }
};

int main() {
    LinkedList linkedList;

    linkedList.add_value_at_position(10, 0);
    linkedList.add_value_at_position(20, 0);
    linkedList.add_value_at_position(30, 1);

    linkedList.print_values();  // Output: Values in the list: 20 30 10

    linkedList.delete_value_at_position(1);

    linkedList.print_values();  // Output: Values in the list: 20 10

    return 0;
}
