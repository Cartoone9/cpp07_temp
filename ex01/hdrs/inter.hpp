/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 21:38:00 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/17 23:49:55 by jramiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTER_HPP
#define INTER_HPP

template <typename T, std::size_t N>
void	iter(T (*array)[N], std::size_t array_len, void (*f)(T&))
{
	for (std::size_t i = 0; i < array_len; i++)
		f(array[i]);
}

template <typename T, std::size_t N>
void	iter(const T (*array)[N], std::size_t array_len, void (*f)(const T&))
{
	for (std::size_t i = 0; i < array_len; i++)
		f(array[i]);
}

#endif // #ifndef INTER_HPP
