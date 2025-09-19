/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.class.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:05:29 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/19 14:24:31 by jramiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_CLASS_TPP
#define ARRAY_CLASS_TPP

#include <exception>
#include <iostream>

template <typename Type = int>
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
		Type&	operator[](unsigned int index);

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
		Type*			_array;
		
};

// ----------------------------------------
// constructors / destructors -------------

template <typename Type>
Array<Type>::Array()
	: _size(0)
	, _array(NULL)
{
	std::cout << "Array default constructor called" << std::endl;
}

template <typename Type>
Array<Type>::Array(unsigned int n)
	: _size(n)
	, _array(n ? new Type[n] : NULL)
{
	std::cout << "Array size constructor called" << std::endl;
}

template <typename Type>
Array<Type>::Array(const Array& old_obj)
	: _size(old_obj._size)
	, _array(old_obj._size ? new Type[old_obj._size] : NULL)
{
	std::cout << "Array copy constructor called" << std::endl;

	for (unsigned int i = 0; i < _size; i++)
		this->_array[i] = old_obj._array[i];
}

template <typename Type>
Array<Type>&	Array<Type>::operator=(const Array& old_obj)
{
	std::cout << "Array assignement operator called" << std::endl;

	if (this != &old_obj)
	{
		this->_size = old_obj._size;
			
		if (this->_array)
			delete[] this->_array;

		this->_array = _size ? new Type[_size] : NULL;

		for (unsigned int i = 0; i < _size; i++)
			this->_array[i] = old_obj._array[i];
	}
	return (*this);
}

template <typename Type>
Array<Type>::~Array()
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

template <typename Type>
unsigned int	Array<Type>::size() const
{
	return (_size);
}
	
// getters / setters ----------------------
// ----------------------------------------


// ----------------------------------------
// operators overload ---------------------

template <typename Type>
Type&	Array<Type>::operator[](unsigned int index)
{
	if (index >= this->_size)
		throw (Array<Type>::OutOfBoundException());
	else
		return (this->_array[index]);
}

// operators overload ---------------------
// ----------------------------------------


// ----------------------------------------
// exception ------------------------------

template <typename Type>
const char*	Array<Type>::OutOfBoundException::what() const throw()
{
	return ("Element is out of bounds.");
}

// exception ------------------------------
// ----------------------------------------

#endif // ARRAY_CLASS_TPP
