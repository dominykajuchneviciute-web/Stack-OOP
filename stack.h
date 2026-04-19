#ifndef STACK_H
#define STACK_H //gali prie failo parasyti random skaicius, uztikrinant, kad bus tik vienintelis toks failas

#include <stdexcept>

#define string std::string

namespace MySpace
{
    /**
     * @brief Exception class for stack operations.
     *
     * Extends std::logic_error to represent errors specific to stack operations.
     */
    class StackException : public std::logic_error {
    public:
         /**
         * @brief Constructs a StackException with a message.
         *
         * @param msg The error message.
         */
        StackException(const string& msg) : logic_error(msg) {}
    };
    /**
     * @brief Dynamic integer stack.
     *
     * Supports adding, deleting, editing, and viewing elements with overloaded operators.
     */
    class Stack
    {
    private:
        /**
         * @brief Internal implementation (PIMPL pattern) hiding the underlying data structure.
         */
        class Inner;
        Inner *impl;
    public:
        /**
         * @brief Constructor. Creates an empty stack.
         */
        Stack();
         /**
         * @brief Copy constructor.
         * @param other another Stack object to copy from.
         */
        Stack(const Stack &other);
        /**
         * @brief Copy assignment operator.
         * @param other another Stack object to copy from.
         * @return const Stack& Reference to this object after assignment.
         */
        const Stack& operator=(const Stack &other);
        /**
         * @brief Destructor. Cleans up all stack resources.
         */
        ~Stack();
        /**
         * @brief Returns a string representation of the stack.
         * @return string Stack contents as a string.
         */
        string toString();
        /**
         * @brief Returns the current number of elements in the stack.
         * @return int The number of elements in the stack. Returns 0 if the stack is empty.
         */
        int getSizes() const;
        /**
         * @brief Adds a new element to the top of the stack.
         * @param value the integer value to add.
         */
        void add(const int &value);
        /**
         * @brief Operator += adds an element to the top of the stack.
         * @param value the integer value to add.
         */
        void operator+=(const int &value);
        /**
         * @brief Views the top element of the stack without removing it.
         * @return int the top element.
         * @throw StackException If the stack is empty.
         */
        int view()const;
        /**
         * @brief Edits an element in the stack.
         * @param oldValue The existing value to be replaced.
         * @param newValue The new value.
         * @throw StackException If oldValue is not found.
         */
        void edit(const int &oldValue,const int &newValue);
        /**
         * @brief Operator *= modifies an element (e.g., multiplies or changes value depending on implementation).
         * @param value used for modification.
         */
        void operator*=(int value);
        /**
         * @brief Removes the top element from the stack.
         * @return int the removed element.
         * @throw StackException if the stack is empty.
         */
        int del();
        /**
         * @brief Operator -= removes an element from the stack by value.
         * @param value the value to remove.
         */
        void operator-=(const int &value);
        /**
         * @brief Index operator. Accesses an element by position.
         * @param value the index.
         * @return int the element at the given index.
         * @throw StackException if the index is invalid.
         */
        int operator[](const int &value) const;
        /**
         * @brief Operator ! clears the entire stack.
         */
        void operator!();
        /**
         * @brief Comparison operators between two stacks.
         */
        bool operator<(const Stack &other)const;
        bool operator<=(const Stack &other)const;
        bool operator>(const Stack &other)const;
        bool operator>=(const Stack &other)const;
        bool operator==(const Stack &other)const;
        bool operator!=(const Stack &other)const;

    };
}
#undef string
#endif
