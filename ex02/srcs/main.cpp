/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:43:14 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/19 14:17:42 by jramiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.class.tpp"

int	main(void)
{
	Array<int> arr(5);

	// Fill array
	for (unsigned int i = 0; i < arr.size(); ++i)
		arr[i] = i * 10;

	// Print array
	for (unsigned int i = 0; i < arr.size(); ++i)
		std::cout << "arr[" << i << "] = " << arr[i] << std::endl;

	// Test out-of-bounds exception
	try {
		arr[10] = 100;
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return (0);
}
