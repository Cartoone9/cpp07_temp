/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.class.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:05:29 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/27 16:43:03 by jramiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_CLASS_TPP
#define ARRAY_CLASS_TPP

#include <exception>
#include <iostream>

template <typename T = int>
class Array
{
	public:
		// constructors - destructors
		Array();
		Array(unsigned int n);
		Array(const Array& old_obj);
		Array& operator=(const Array& old_obj);
		~Array();

		// operators overload
		T&			operator[](unsigned int index) const;

		// methods
		void		printArray() const;
		void		printArray(std::string name) const;

		// getters - setters
		unsigned int	size() const;
		void			setValue(unsigned int index, int value);

		// exceptions
		class OutOfBoundException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		bool	noPrintableChar() const;

		unsigned int	_size;
		T*				_array;
		
};

// ----------------------------------------
// constructors / destructors -------------

template <typename T>
Array<T>::Array()
	: _size(0)
	, _array(NULL)
{
	std::cout << "Array default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n)
	: _size(n)
	, _array(n ? new T[n]() : NULL)
{
	std::cout << "Array size constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array<T>& old_obj)
	: _size(old_obj._size)
	, _array(old_obj._size ? new T[old_obj._size] : NULL)
{
	std::cout << "Array copy constructor called" << std::endl;

	for (unsigned int i = 0; i < _size; i++)
		this->_array[i] = old_obj._array[i];
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array<T>& old_obj)
{
	std::cout << "Array assignement operator called" << std::endl;

	if (this != &old_obj)
	{
		this->_size = old_obj._size;
			
		if (this->_array)
			delete[] this->_array;

		this->_array = _size ? new T[_size] : NULL;

		for (unsigned int i = 0; i < _size; i++)
			this->_array[i] = old_obj._array[i];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "Array destructor called" << std::endl;

	delete[] _array;
}

// constructors / destructors -------------
// ----------------------------------------


// ----------------------------------------
// methods --------------------------------

template <typename T>
bool	Array<T>::noPrintableChar() const
{
	for (std::size_t i = 0; i < _size; i++)
	{
		if (isprint(static_cast<unsigned char>(_array[i])))
			return (false);
	}
	return (true);
}
template <typename T>
void		Array<T>::printArray() const
{
	if (_size == 0 || this->noPrintableChar())
	{
		std::cout << "Array is empty." << std::endl;
		return;
	}

	std::cout << "Array values:" << std::endl;

	for (std::size_t i = 0; i < _size; i++)
	{
		if (isprint(static_cast<unsigned char>(_array[i])))
			std::cout << _array[i] << std::endl;
	}
}

template <typename T>
void		Array<T>::printArray(std::string name) const
{
	if (_size == 0 || this->noPrintableChar())
	{
		std::cout << name << " is empty." << std::endl;
		return;
	}

	std::cout << name << " values:" << std::endl;

	for (std::size_t i = 0; i < _size; i++)
	{
		if (isprint(static_cast<unsigned char>(_array[i])))
			std::cout << _array[i] << std::endl;
	}
}

// methods --------------------------------
// ----------------------------------------


// ----------------------------------------
// getters / setters ----------------------

template <typename T>
unsigned int	Array<T>::size() const
{
	return (_size);
}

template <typename T>
void			Array<T>::setValue(unsigned int index, int value)
{
	if (index >= this->_size)
		throw (Array<T>::OutOfBoundException());
	else
		_array[index] = value;
}

// getters / setters ----------------------
// ----------------------------------------


// ----------------------------------------
// operators overload ---------------------

template <typename T>
T&	Array<T>::operator[](unsigned int index) const
{
	if (index >= this->_size)
		throw (Array<T>::OutOfBoundException());
	else
		return (this->_array[index]);
}

// template <typename T>
// const T&	Array<T>::operator[](unsigned int index) const
// {
// 	if (index >= this->_size)
// 		throw (Array<T>::OutOfBoundException());
// 	else
// 		return (this->_array[index]);
// }

// operators overload ---------------------
// ----------------------------------------


// ----------------------------------------
// exception ------------------------------

template <typename T>
const char*	Array<T>::OutOfBoundException::what() const throw()
{
	return ("Element is out of bounds.");
}

// exception ------------------------------
// ----------------------------------------

#endif // ARRAY_CLASS_TPP
