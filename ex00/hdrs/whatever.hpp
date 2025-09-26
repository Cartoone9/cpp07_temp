/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:44:48 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/26 20:01:00 by jramiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void		swap(T& var_1, T& var_2)
{
	T	temp;

	temp = var_1;
	var_1 = var_2;
	var_2 = temp;
}

template <typename T>
T&			min(T& var_1, T& var_2)
{
	return (var_1 < var_2 ? var_1 : var_2);
}

template <typename T>
const T&	min(const T& var_1, const T& var_2)
{
	return (var_1 < var_2 ? var_1 : var_2);
}

template <typename T>
T&			max(T& var_1, T& var_2)
{
	return (var_1 > var_2 ? var_1 : var_2);
}

template <typename T>
const T&	max(const T& var_1, const T& var_2)
{
	return (var_1 > var_2 ? var_1 : var_2);
}

#endif // #ifndef WHATEVER_HPP
