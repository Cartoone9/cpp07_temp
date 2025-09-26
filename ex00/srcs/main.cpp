/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:43:14 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/26 20:09:54 by jramiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "colors.hpp"
#include "whatever.hpp"

void	printAll(int a, int b, int c, float d, float e, float f)
{
	std::cout << "int " << BOLD TEAL "a" RESET << " value: " << a << std::endl;
	std::cout << "int " << BOLD YELLOW "b" RESET << " value: " << b << std::endl;
	std::cout << "int " << BOLD RED "c" RESET << " value: " << c << std::endl;

	std::cout << std::endl;

	std::cout << "float " << BOLD GREEN "d" RESET << " value: " << d << std::endl;
	std::cout << "float " << BOLD PURPLE "e" RESET << " value: " << e << std::endl;
	std::cout << "float " << BOLD ORANGE "f" RESET << " value: " << f << std::endl;
}

template <typename T>
void	minmaxTest(T& value_1, T& value_2, const std::string names[], bool which)
{
	const char*	label = which ? "Max" : "Min";
	const T&	ret = which ? max(value_1, value_2) : min(value_1, value_2);
	
	std::cout << UNDERLINE << label << RESET
		<< " test between "
		<< names[0]
		<< " (" << value_1 << ")"
		<< " and "
		<< names[1]
		<< " (" << value_2 << ")"
		<< ":"
		<< std::endl;

	std::cout << (ret == value_1 ? names[0] + std::string(" ("): names[1] + std::string(" ("))
		<< ret << ")" << std::endl;
}

template <typename T>
void	testPrep(T& value_1, T& value_2, const std::string& name_1, const std::string& name_2, bool which)
{
	const std::string names[] = {name_1, name_2};
	minmaxTest(value_1, value_2, names, which);
}

int main(void)
{
	int	a = 42;
	std::string name_a = BOLD TEAL "a" RESET;
	int	b = 123;
	std::string name_b = BOLD YELLOW "b" RESET;
	int	c = 999;
	std::string name_c = BOLD RED "c" RESET;

	float d = 3.14;
	std::string name_d = BOLD GREEN "d" RESET;
	float e = 0.01;
	std::string name_e = BOLD MAGENTA "e" RESET;
	float f = 42.42;
	std::string name_f = BOLD ORANGE "f" RESET;


	// -----------------------------------------------------------------
	std::cout << REVERSED "--- VARS INFO ---\n" RESET << std::endl;

	printAll(a, b, c, d, e, f);


	// -----------------------------------------------------------------
	std::cout << REVERSED GREEN "\n--- SWAP TESTS ---\n" RESET << std::endl;

	std::cout << "swapping " << name_a << " and " << name_b << std::endl;
	swap(a, b);
	std::cout << "swapping " << name_d << " and " << name_e << std::endl;
	swap(d, e);
	std::cout << std::endl;

	printAll(a, b, c, d, e, f);


	// -----------------------------------------------------------------
	std::cout << REVERSED TEAL "\n--- MIN TESTS ---\n" RESET << std::endl;

	// int
	std::cout << REVERSED "int:\n" RESET << std::endl;
	testPrep(a, b, name_a, name_b, false);
	testPrep(a, c, name_a, name_c, false);
	testPrep(b, c, name_b, name_c, false);

	// float
	std::cout << REVERSED "\nfloat:\n" RESET << std::endl;
	testPrep(d, e, name_d, name_e, false);
	testPrep(d, f, name_d, name_f, false);
	testPrep(e, f, name_e, name_f, false);


	// -----------------------------------------------------------------
	std::cout << REVERSED RED "\n--- MAX TESTS ---\n" RESET << std::endl;

	// int
	std::cout << REVERSED "int:\n" RESET << std::endl;
	testPrep(a, b, name_a, name_b, true);
	testPrep(a, c, name_a, name_c, true);
	testPrep(b, c, name_b, name_c, true);

	// float
	std::cout << REVERSED "\nfloat:\n" RESET << std::endl;
	testPrep(d, e, name_d, name_e, true);
	testPrep(d, f, name_d, name_f, true);
	testPrep(e, f, name_e, name_f, true);

	return (0);
}
