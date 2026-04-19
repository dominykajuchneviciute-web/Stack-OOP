#include "stack.h"
#include <sstream>
#include <vector>
//#define TEST

using namespace std;


namespace MySpace{

    class Stack::Inner
    {
        struct Node
        {
            int data;
            Node* next;
            Node(int v, Node* n = nullptr) : data(v), next(n) {}
        };
        Node *top;
        int sizes;
    public:
        Inner():top(nullptr),sizes(0){}
        Inner(const Inner &other) : top(nullptr), sizes(0)
        {
            std::vector<int> temp;
            Node* current = other.top;
            while(current)
            {
                temp.push_back(current->data);
                current = current->next;
            }
            for(int i = temp.size()-1; i>=0; --i)
            {
                add(temp[i]);
            }
        }
        const Inner& operator=(const Inner &other)
        {
            if(this != &other)
            {
                while(top)
                    del();
                Node* current = other.top;
                while(current)
                {
                    add(current->data);
                    current = current->next;
                }
            }
            return *this;
        }
        ~Inner()
        {
            while(top)
                del();
        }
        std::string toString()
        {
            std::stringstream ss;
            Node* current = top;
            while(current)
            {
                ss << current->data << " ";
                current = current->next;
            }
            return ss.str();
        }
        int getSizes() const
        {
            return sizes;
        }
        void add(const int &value)
        {
            top = new Node(value,top);
            sizes++;
        }
        void operator+=(const int &value)
        {
            add(value);
        }
        int view()const
        {
            if(!top)
                throw std::out_of_range("Stack is empty.");
            return top->data-1;
        }
        void edit(const int &oldValue,const int &newValue)
        {
            Node *current = top;
            while(current)
            {
                if(current->data == oldValue)
                {
                    current->data = newValue;
                    return;
                }
                current = current->next;
            }
            throw StackException("Value not found");
        }
        void operator*=(int value)
        {
            Node* current = top;
            while(current)
            {
                current->data *= value;
                current = current->next;
            }
        }
        int del()
        {
            if(!top)
                throw StackException("Stack is empty");
            Node* temp = top;
            int value = temp->data;
            top = top->next;
            delete temp;
            sizes--;
            return value;
        }
        void operator-=(const int &value)
        {
            Node* current = top;
            Node* prev = nullptr;
            while(current)
            {
                if(current->data == value)
                {
                    if(prev)
                        prev->next = current->next;
                    else
                        top = current->next;
                    delete current;
                    sizes--;
                    return;
                }
                prev = current;
                current = current->next;
            }

            throw StackException("Value not found");
        }

        int operator[](const int &value) const
        {
            Node* current = top;
            int index = 0;
            while(current)
            {
                if(current->data == value)
                    return index;
                current = current->next;
                index++;
            }
            return -1;
        }
        void operator!()
        {
            while(top)
                del();
        }
        bool operator<(const Inner &other)const
        {
            Node* a = top;
            Node* b = other.top;
            while (a != nullptr && b != nullptr)
            {
                if (a->data < b->data)
                    return true;
                if (a->data > b->data)
                    return false;
                a = a->next;
                b = b->next;
            }
            return (a == nullptr && b != nullptr);
        }
        bool operator<=(const Inner &other)const
        {
            return !(*this > other);
        }
        bool operator>(const Inner &other)const
        {
            return other < *this;
        }
        bool operator>=(const Inner &other)const
        {
            return !(*this < other);
        }
        bool operator==(const Inner &other)const
        {
            if(sizes != other.sizes)
                return false;
            Node* a = top;
            Node* b = other.top;
            while(a && b)
            {
                if(a->data != b->data)
                    return false;
                a = a->next;
                b = b->next;
            }
            return true;
        }
        bool operator!=(const Inner &other)const
        {
            return !(*this == other);
        }


    };

    //Stack  implementation delegates it
    // to the Stack::Inner class

    Stack::Stack()
    {
        impl = new Stack::Inner();
    }
    Stack::Stack (const Stack &other)
    {
        impl = new Stack::Inner(*(other.impl));
    }
    const Stack& Stack::operator=(const Stack &other)
    {
        if(&other != this)
        {
            delete impl;
            impl = new Stack::Inner(*(other.impl));
        }
        return *this;
    }
    Stack::~Stack()
    {
        delete impl;
    }
    string Stack::toString()
    {
        return impl->toString();
    }
    int Stack::getSizes() const
    {
        return impl->getSizes();
    }
    void Stack::add(const int &value)
    {
        impl->add(value);
    }
    void Stack::operator+=(const int &value)
    {
        add(value);
    }
    int Stack::view()const
    {
        return impl->view();
    }
    void Stack::edit(const int &oldValue,const int &newValue)
    {
        impl->edit(oldValue, newValue);
    }
    void Stack::operator*=(int value)
    {
        (*impl)*=value;
    }
    int Stack::del()
    {
        return impl->del();
    }
    void Stack::operator-=(const int &value)
    {
        (*impl)-=value;
    }

    int Stack::operator[](const int &value) const
    {
        return (*impl)[value];
    }

    void Stack::operator!()
    {
        (*impl).operator!();
    }

    bool Stack::operator<(const Stack &other)const
    {
        return *(this->impl) < *(other.impl);
    }
    bool Stack::operator<=(const Stack &other)const
    {
        return *(this->impl) <= *(other.impl);
    }
    bool Stack::operator>(const Stack &other)const
    {
        return *(this->impl) > *(other.impl);
    }
    bool Stack::operator>=(const Stack &other)const
    {
        return *(this->impl) >= *(other.impl);
    }
    bool Stack::operator==(const Stack &other)const
    {
        return *(this->impl) == *(other.impl);
    }
    bool Stack::operator!=(const Stack &other)const
    {
        return *(this->impl) != *(other.impl);
    }

}
#ifdef TEST

#endif // TEST
