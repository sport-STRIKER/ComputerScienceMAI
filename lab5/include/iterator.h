#pragma once

template<class T>
class Node 
{
    public:
        Node();
        Node(const T& value);
        ~Node() noexcept;

    public:
        T data;
        Node* next;
};

template<class T>
class ConstIterator 
{
    public:
        ConstIterator();
        ConstIterator(Node<T>* node);
        ConstIterator(const ConstIterator<T> &other);
        ConstIterator(ConstIterator<T> &&other) noexcept;

        T getValue() const;

        ConstIterator<T>& operator++();
        ConstIterator<T> operator++(int n);

        const T operator*() const;
        const T* operator->() const;

        ConstIterator<T>& operator=(const ConstIterator<T> &other);
        ConstIterator<T>& operator=(ConstIterator<T> &&other) noexcept;

        bool operator==(const ConstIterator<T>& other) const;
        bool operator!=(const ConstIterator<T>& other) const;

    private:
        Node<T>* current;
};

template<class T>
class Iterator 
{
    public:
        Iterator();
        Iterator(Node<T>* node);
        Iterator(const Iterator<T> &other);
        Iterator(Iterator<T> &&other) noexcept;

        T getValue() const;
        void setValue(Node<T>* node);

        Iterator<T>& operator++();
        Iterator<T> operator++(int);

        T operator*() const;
        T* operator->() const;

        Iterator<T>& operator=(const Iterator<T> &other);
        Iterator<T>& operator=(Iterator<T> &&other) noexcept;

        bool operator==(const Iterator<T>& other) const;
        bool operator!=(const Iterator<T>& other) const;

    private:
        Node<T>* current;
};

template<class T>
Node<T>::Node() : data{0}, next{nullptr} {}

template<class T>
Node<T>::Node(const T& value) : data{value}, next{nullptr} {}

template<class T>
Node<T>::~Node() noexcept
{
    if (next != nullptr) next = nullptr;
    data = 0;
}

template<class T>
ConstIterator<T>::ConstIterator() : current{nullptr} {}

template<class T>
ConstIterator<T>::ConstIterator(Node<T>* node) : current{node} {}

template<class T>
ConstIterator<T>::ConstIterator(const ConstIterator<T> &other) : current{other.current} {}

template<class T>
ConstIterator<T>::ConstIterator(ConstIterator<T> &&other) noexcept
{
    current = std::move(other.current);
}

template<class T>
T ConstIterator<T>::getValue() const
{
    return current->data();
}

template<class T>
ConstIterator<T>& ConstIterator<T>::operator++()
{
    current = current->next;
    return *this;
}

template<class T>
ConstIterator<T> ConstIterator<T>::operator++(int)
{
    ConstIterator<T> now(*this);
    current = current->next;
    return now;
}

template<class T>
const T ConstIterator<T>::operator*() const
{
    return current->data;
}

template<class T>
const T* ConstIterator<T>::operator->() const
{
    return &(current->data);
}

template<class T>
ConstIterator<T>& ConstIterator<T>::operator=(const ConstIterator<T> &other)
{
    current = other.current;
    return *this;
}

template<class T>
ConstIterator<T>& ConstIterator<T>::operator=(ConstIterator<T> &&other) noexcept
{
    current = std::move(other.current);
    return *this;
}

template<class T>
bool ConstIterator<T>::operator==(const ConstIterator<T>& other) const
{
    return current == other.current;
}

template<class T>
bool ConstIterator<T>::operator!=(const ConstIterator<T>& other) const
{
    return !(*this == other);
}

template<class T>
Iterator<T>::Iterator() : current{nullptr} {}

template<class T>
Iterator<T>::Iterator(Node<T>* node) : current{node} {}

template<class T>
Iterator<T>::Iterator(const Iterator<T> &other) : current{other.current} {}

template<class T>
Iterator<T>::Iterator(Iterator<T> &&other) noexcept
{
    current = std::move(other.current);
}

template<class T>
T Iterator<T>::getValue() const
{
    return current->data;
}

template<class T>
void Iterator<T>::setValue(Node<T>* node)
{
    current = node;
}

template<class T>
Iterator<T>& Iterator<T>::operator++()
{
    current = current->next;
    return *this;
}

template<class T>
Iterator<T> Iterator<T>::operator++(int)
{
    Iterator<T> now(*this);
    current = current->next;
    return now;
}

template<class T>
T Iterator<T>::operator*() const
{
    return current->data;
}

template<class T>
T* Iterator<T>::operator->() const
{
    return &(current->data);
}

template<class T>
Iterator<T>& Iterator<T>::operator=(const Iterator<T> &other)
{
    current = other.current;
    return *this;
}

template<class T>
Iterator<T>& Iterator<T>::operator=(Iterator<T> &&other) noexcept
{
    current = std::move(other.current);
    return *this;
}

template<class T>
bool Iterator<T>::operator==(const Iterator<T>& other) const
{
    return current == other.current;
}

template<class T>
bool Iterator<T>::operator!=(const Iterator<T>& other) const
{
    return !(*this == other);
}
