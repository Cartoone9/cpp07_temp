/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:43:14 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/26 20:55:17 by jramiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "colors.hpp"
#include "iter.hpp"

template <typename T>
void	printArray(T *array, std::size_t arr_size)
{
	for (std::size_t i = 0; i < arr_size; i++)
		std::cout << array[i] << std::endl;
}

template <typename T>
void	addOne(T& var)
{
	var++;
}

int	main(void)
{
	// -------------------------------------------------------------
	std::cout << REVERSED "--- INT ARRAY ---\n" RESET << std::endl;

	// array
	int			array_int[] = {1, 2, 3, 4, 5};
	std::size_t	arr_size = sizeof(array_int) / sizeof(array_int[0]);

	// before
	std::cout << UNDERLINE ORANGE "Before:" RESET << std::endl;
	printArray(array_int, arr_size);

	iter(&array_int, arr_size, addOne);

	std::cout << std::endl;

	// after
	std::cout << UNDERLINE TEAL "After:" RESET << std::endl;
	printArray(array_int, arr_size);


	// -------------------------------------------------------------
	std::cout << REVERSED "\n--- CHAR ARRAY ---\n" RESET << std::endl;

	// array
	char	array_char[] = {'a', 'b', 'c', 'd', 'e'};
	arr_size = sizeof(array_char) / sizeof(array_char[0]);

	// before
	std::cout << UNDERLINE ORANGE "Before:" RESET << std::endl;
	printArray(array_char, arr_size);

	iter(&array_char, arr_size, addOne);

	std::cout << std::endl;

	// after
	std::cout << UNDERLINE TEAL "After:" RESET << std::endl;
	printArray(array_char, arr_size);

	return (0);
}
