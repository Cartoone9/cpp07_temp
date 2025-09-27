/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:43:14 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/27 16:54:47 by jramiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Array.class.tpp"
#include "colors.hpp"

template <typename T>
void	setTryTest(Array<T>& array, std::size_t index, int value)
{
	try
	{
		array.setValue(index, value);
	}
	catch (const std::exception& e)
	{
		std::cout << RED "Error: " RESET;
		std::cout << e.what() << std::endl;
	}
}

int	main(void)
{
	Array<>		arr_1;
	std::string arr_1_name = TEAL "Array 1" RESET;

	Array<>		arr_2(10);
	std::string arr_2_name = YELLOW "Array 2" RESET;

	Array<int>	arr_3(10);
	std::string arr_3_name = RED "Array 3" RESET;

	Array<char>	arr_4(10);
	std::string arr_4_name = PURPLE "Array 4" RESET;

	Array<char>	arr_5(arr_4);
	std::string arr_5_name = GREEN "Array 5" RESET;

	std::cout << std::endl;


	// -------------------------------------------------------------
	std::cout << REVERSED "--- ARRAYS INFO ---\n" RESET << std::endl;

	arr_1.printArray(arr_1_name);
	arr_2.printArray(arr_2_name);
	arr_3.printArray(arr_3_name);
	arr_4.printArray(arr_4_name);
	arr_5.printArray(arr_5_name);

	std::cout << std::endl;


	// -------------------------------------------------------------
	std::cout << REVERSED "--- FILL ARRAYS ---\n" RESET << std::endl;
	setTryTest(arr_1, 0, 'a'); // out of bound
	setTryTest(arr_2, 0, 'a');
	setTryTest(arr_3, 0, 'a');
	setTryTest(arr_4, 0, 'a');
	setTryTest(arr_5, 0, 'a');

	std::cout << std::endl;


	// -------------------------------------------------------------
	std::cout << REVERSED "--- ARRAYS INFO ---\n" RESET << std::endl;

	arr_1.printArray(arr_1_name);
	arr_2.printArray(arr_2_name);
	arr_3.printArray(arr_3_name);
	arr_4.printArray(arr_4_name);
	arr_5.printArray(arr_5_name);

	std::cout << std::endl;


	// -------------------------------------------------------------
	std::cout << REVERSED "--- FILL ARRAY 5 ---\n" RESET << std::endl;

	setTryTest(arr_5, 1, 'b');
	setTryTest(arr_5, 2, 'c');
	setTryTest(arr_5, 3, 'd');
	setTryTest(arr_5, 4, 'e');
	setTryTest(arr_5, 5, 'f');

	arr_5.printArray(arr_5_name);

	std::cout << std::endl;


	// -------------------------------------------------------------
	std::cout << REVERSED "--- OVERFILL ARRAY 5 ---\n" RESET << std::endl;

	setTryTest(arr_5, 6, 'g');
	setTryTest(arr_5, 7, 'h');
	setTryTest(arr_5, 8, 'i');
	setTryTest(arr_5, 9, 'j');
	setTryTest(arr_5, 10, 'k'); // out of bound

	std::cout << std::endl;

	arr_5.printArray(arr_5_name);

	std::cout << std::endl;


	// -------------------------------------------------------------
	std::cout << REVERSED "--- COPY ARRAY 5 TO 6 ---\n" RESET << std::endl;

	Array<char>	arr_6;
	std::string arr_6_name = ORANGE "Array 6" RESET;
	arr_6 = arr_5;
	
	std::cout << std::endl;

	arr_6.printArray(arr_6_name);

	std::cout << std::endl;

	return (0);
}
