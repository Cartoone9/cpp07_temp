/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.class.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:05:29 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/22 16:43:19 by jramiro          ###   ########.fr       */
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
		T&	operator[](unsigned int index);

		// methods

		// getters - setters
		unsigned int	size() const;

		// exceptions
		class OutOfBoundException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
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

// methods --------------------------------
// ----------------------------------------


// ----------------------------------------
// getters / setters ----------------------

template <typename T>
unsigned int	Array<T>::size() const
{
	return (_size);
}
	
// getters / setters ----------------------
// ----------------------------------------


// ----------------------------------------
// operators overload ---------------------

template <typename T>
T&	Array<T>::operator[](unsigned int index)
{
	if (index >= this->_size)
		throw (Array<T>::OutOfBoundException());
	else
		return (this->_array[index]);
}

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
