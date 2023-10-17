#include "node.hpp"
#include <memory>
#include <iostream>

template <typename T>
class SLL
{
public:
    // Constructor
    SLL() : current_(nullptr) {}

    // ⭐TODO: Analyze the function below and talk with your team to decide what efficiency class works for this
    // ✅ANSWER: O(n)
    void push_back(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        // This checks if the current head is nullptr, it if is then make the new node the actual head
        if (!current_)
        {
            current_ = newNode;
        }
        else
        {
            Node<T> *current = current_;
            // This checks if the next node is not nullptr, if it is then we break out of the loop
            while (current->next_)
            {
                current = current->next_;
            }
            current->next_ = newNode;
        }
    }
    // ⭐TODO: Analyze the function below and talk with your team to decide what efficiency class works for this
    // ✅ANSWER: O(n)
    void display()
    {
        Node<T> *current = current_;

        while (current != nullptr)
        {
            std::cout << current->value_ << '\n';
            current = current->next_;
        }
        std::cout << std::endl;
    }

    // ⭐TODO: Analyze the function below and talk with your team to decide what efficiency class works for this
    // ✅ANSWER: O(1)
    void push_front(Node<T> *newHead)
    {
        newHead->next_ = current_;
        current_ = newHead;
    }

    // ⭐TODO: Analyze the function below and talk with your team to decide what efficiency class works for this
    // ✅ANSWER: O(n)
    bool insert(T value, T target)
    {
        Node<T> *newNode = new Node<T>(value);

        if (!current_)
        {
            // If the list is empty, insert at the front
            current_ = newNode;
            return true;
        }
        else if (current_->data == target)
        {
            // If the target is the first node's data, insert at the front
            newNode->next = current_;
            current_ = newNode;
            return true;
        }
        else
        {
            Node<T> *current = current_;
            while (current->next)
            {
                if (current->next->data == target)
                {
                    newNode->next = current->next;
                    current->next = newNode;
                    return true;
                }
                current = current->next;
            }
        }

        return false; // Target not found in the list
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    // RECURSION TIME :>
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    // ⭐TODO: Practice recursion by turning the iterative loop in push_back() into a recursive function
    // 💡HINT: sometimes its good to separate logic by creating a new helper function to do the recursion for you :>

    void recursive_push_back_starter(T value)
    {
    }

    void recursive_display_starter()
    {
    }

    // ⭐TODO: Practice recursion by turning the iterative loop in insert() into a recursive function
    // 💡HINT: sometimes its good to separate logic by creating a new helper function to do the recursion for you :>
    bool recursive_insert_starter(T value, T target)
    {
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    // CHALLENGE
    // do these todo's if you finished practicing recursion above
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    // ⭐TODO: Finish the following function to delete an element from the beginning of the SLL using the Target
    void pop_front(T target)
    {
    }
    // ⭐TODO: Finish the following function to delete an element from the SLL using the Target
    void remove(T target)
    {
    }

private:
    Node<T> *current_;
};