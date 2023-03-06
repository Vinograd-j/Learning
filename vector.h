#pragma once
#include <iostream>
#include <ostream>

template<typename T>
class Vector
{

private:
	T* _data;
	size_t _size;
	size_t _countOfElements;


public:

	explicit Vector(const size_t size) : _data(new T[size]), _size(size), _countOfElements(0) {}

	Vector(std::initializer_list<T> list) : _data(new T[list.size()]), _size(list.size()), _countOfElements(list.size())
	{
		std::copy(list.begin(), list.end(), _data);
	}


	Vector(const Vector& vector);

	Vector& operator=(const Vector& vector);

	~Vector() { delete[]  _data; }

	void PushBack(const T& value);
	Vector& operator+=(const T& value);

	
	T& operator[](size_t index);
	const T& operator[](size_t index) const;

	size_t Size() const { return _countOfElements; }

	template<typename T>
	friend std::ostream& operator<<(std::ostream& out, const Vector<T>& vector);
};

template <typename T>
Vector<T>::Vector(const Vector& vector) : _data(new T[vector._size]), _size(vector._size), _countOfElements(vector._countOfElements)
{
	std::copy(vector._data, vector._data + _size, _data);
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& vector)
{

	if (this != &vector) {
		this->_size = vector._size;
		this->_data = new T[_size];
		std::copy(vector._data, vector._data + _size, _data);
		this->_countOfElements = vector._countOfElements;
	}

	return *this;
}

template <typename T>
void Vector<T>::PushBack(const T& value)
{
	_countOfElements++;


	if (_countOfElements > _size)
	{
		size_t newSize = _size + 1;

		auto tmp = new T[newSize];

		std::copy(_data, _data + _size, tmp);

		delete[] _data;

		_data = tmp;

		_size = newSize;
	}

	_data[_countOfElements - 1] = value;

}

template <typename T>
Vector<T>& Vector<T>::operator+=(const T& value)
{

	PushBack(value);

	return *this;
}


template <typename T>
T& Vector<T>::operator[](size_t index)
{

	if (index >= _countOfElements)
		throw std::logic_error("Index out of bounds");

	return _data[index];

}

template <typename T>
const T& Vector<T>::operator[](size_t index) const
{
	return const_cast<Vector*>(this)->operator[](index);
}


template<typename T>
std::ostream& operator<<(std::ostream& out, const Vector<T>& vector)
{

	out << "[";

	for (int i = 0; i < vector.Size(); ++i) {
		out << vector._data[i];

		if (i < vector.Size() - 1) {
			out << ", ";
		}
	}

	out << "]";

	return out;
}
