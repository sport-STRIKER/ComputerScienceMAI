#include <iostream>

#include "allocator.h"
#include "iterator.h"

template <typename T, class Allocator>
class List 
{
    public:
        List();
        List(const std::initializer_list<T> & list);
        ~List() noexcept;

        Iterator<T> begin() const;
        Iterator<T> end() const;
        ConstIterator<T> cbegin() const;
        ConstIterator<T> cend() const;

        size_t size();
        void push_front(const T& value);
        void push_back(const T& value); 
        void pop_back();
        void pop_front();
        T& front();
        T& back();
        bool empty() const;
        void clear();

    private:
        size_t _size;
        Node<T>* head;
        Node<T>* tail;
        Allocator allocator;
};

template<class T, class Allocator>
List<T, Allocator>::List() : _size{0}, head{nullptr}, tail{nullptr}, allocator() {}

template<class T, class Allocator>
List<T, Allocator>::List(const std::initializer_list<T> & list)
{
    _size = list.size();
    head = allocator.allocate(1);
    allocator.construct(head, *list.begin());
    Node<T> *cur = head;
    for (auto elem = list.begin() + 1; elem != list.end(); ++elem) {
        cur->next = allocator.allocate(1);
        allocator.construct(cur->next, *elem);
        cur = cur->next;
    }
    tail = cur;
    tail->next = nullptr;
}

template<class T, class Allocator>
List<T, Allocator>::~List() noexcept
{
    clear();
}

template<class T, class Allocator>
Iterator<T> List<T, Allocator>::begin() const
{
    Iterator<T> it(head);
    return it;
}

template<class T, class Allocator>
Iterator<T> List<T, Allocator>::end() const
{

    Iterator<T> it(tail->next);
    return it;
}

template<class T, class Allocator>
ConstIterator<T> List<T, Allocator>::cbegin() const
{
    ConstIterator<T> it(head);
    return it;
}

template<class T, class Allocator>
ConstIterator<T> List<T, Allocator>::cend() const
{
    ConstIterator<T> it(tail->next);
    return it;
}

template<class T, class Allocator>
size_t List<T, Allocator>::size()
{
    return _size;
}

template<class T, class Allocator>
void List<T, Allocator>::push_front(const T& value)
{
    Node<T>* tmp = allocator.allocate(1);
    tmp->next = nullptr;
    allocator.construct(tmp, value);
    if (empty()) {
        head = tail = tmp;
    } else {
        tmp->next = head;
        head = tmp;
    }
    ++_size;
}

template<class T, class Allocator>
void List<T, Allocator>::push_back(const T& value)
{
    Node<T>* tmp = allocator.allocate(1);
    tmp->next = nullptr;
    allocator.construct(tmp, value);
    if (empty()) {
        head = tail = tmp;
    } else {
        tail->next = tmp;
        tail = tmp;
    }
    ++_size;
}

template<class T, class Allocator>
void List<T, Allocator>::pop_back()
{
    if (empty()) {
        throw std::range_error("List is empty\n");
    }
    if (head == tail) {
        allocator.destroy(head);
        allocator.deallocate(head, 1);
        head = tail = nullptr;
    } else {
        Node<T>* tmp;

        for (auto elem = head->next; elem != nullptr; elem = elem->next)
            if (elem->next == tail) {
                tmp = elem;
                break;
            }
        
        allocator.destroy(tail);
        allocator.deallocate(tail, 1);

        tail = tmp;
    }
    --_size;
}

template<class T, class Allocator>
void List<T, Allocator>::pop_front()
{
    if (empty()) {
        throw std::range_error("List is empty\n");
    }
    if (head == tail) {
        allocator.destroy(head);
        allocator.deallocate(head, 1);
        head = tail = nullptr;
    } else {
        Node<T>* tmp = head;
        head = head->next;
        allocator.destroy(tmp);
        allocator.deallocate(tmp, 1);
    }
    --_size;
}

template<class T, class Allocator>
T& List<T, Allocator>::front()
{
    if (empty()) {
        throw std::range_error("List is empty\n");
    }
    return head->data;
}

template<class T, class Allocator>
T& List<T, Allocator>::back()
{
    if (empty()) {
        throw std::range_error("List is empty\n");
    }
    return tail->data;
}

template<class T, class Allocator>
bool List<T, Allocator>::empty() const
{
    return _size == 0;
}

template<class T, class Allocator>
void List<T, Allocator>::clear()
{
    _size = 0;
    while (head != nullptr) {
        Node<T>* tmp = head;
        head = head->next;
        allocator.destroy(tmp);
        allocator.deallocate(tmp, 1);
    }
    tail = nullptr;
}
