#pragma once
#include <iostream>

template<typename T>
struct Node {

    Node* nextNode = nullptr;
    Node* previousNode = nullptr;

	T value{};

};

template<typename T>
class LinkedList {

private:

    Node<T>* _firstNode;

    size_t _size;

public:

    LinkedList() : _firstNode(nullptr), _size(0) {}

    ~LinkedList();

    void Add(const T& element);
    void Remove(size_t index);

	T& operator[](size_t index);
    const T& operator[](size_t index) const;

	template<typename T>  
    friend std::ostream& operator<<(std::ostream& out, const LinkedList<T>& list);

};

template <typename T>
LinkedList<T>::~LinkedList()
{
    auto node = _firstNode;

    while(node != nullptr)
    {
        auto nextNode = node->nextNode;
        delete node;
        node = nextNode;
    }
}

template<typename T>
void LinkedList<T>::Add(const T& element) {

    _size++;

    if (_firstNode == nullptr) {
        _firstNode = new Node<T>;
        _firstNode->value = element;
        return;
    }

    auto lastNode = _firstNode->previousNode;

    if (lastNode == nullptr) {
        lastNode = new Node<T>;
        lastNode->value = element;

        lastNode->nextNode = _firstNode;
        lastNode->previousNode = _firstNode;

        _firstNode->nextNode = lastNode;
        _firstNode->previousNode = lastNode;

        return;
    }

    auto currentNode = new Node<T>;

    currentNode->value = element;

    currentNode->nextNode = _firstNode;
    currentNode->previousNode = lastNode;

    _firstNode->previousNode = currentNode;

    lastNode->nextNode = currentNode;

}

template<typename T>
void LinkedList<T>::Remove(size_t index) {

    if (index >= _size)
        throw std::logic_error("Index out of bounds exception");

    if (_size == 1) {
        delete _firstNode;
        _firstNode = nullptr;

        _size--;

        return;
    }

    auto node = _firstNode;

    while (index-- != 0) {
        node = node->nextNode;
    }

    auto previousNode = node->previousNode;
    auto nextNode = node->nextNode;

    previousNode->nextNode = nextNode;
    nextNode->previousNode = previousNode;

    if (node == _firstNode)
        _firstNode = nextNode;

    delete node;

    if (_size == 2) {
        _firstNode->nextNode = nullptr;
        _firstNode->previousNode = nullptr;
    }

    _size--;
}



template <typename T>
T& LinkedList<T>::operator[](size_t index)
{

    if (index >= _size)
        throw std::logic_error("Index out of bounds exception");

    auto node = _firstNode;

    while (index-- != 0) {
        node = node->nextNode;
    }

    return node->value;

}

template<typename T>
const T& LinkedList<T>::operator[](size_t index) const
{
    return const_cast<LinkedList*>(this)->operator[](index);
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const LinkedList<T>& list)
{
	out << "[";
	size_t index = list._size - 1;

	auto node = list._firstNode;

	if (node != nullptr)
		do
		{
			out << node->value;

			if (index != 0)
				out << ", ";

			node = node->nextNode;
		}
		while (index-- != 0);

	out << "]";

	return out;
}
