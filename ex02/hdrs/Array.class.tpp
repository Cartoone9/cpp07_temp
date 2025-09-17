/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.class.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:05:29 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/17 15:06:19 by jramiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_CLASS_TPP
#define ARRAY_CLASS_TPP

#include <iostream>

class Array
{
	public:
		// constructors - destructors
		Array();
		Array(const Array& old_obj);
		Array& operator=(const Array& old_obj);
		~Array();

		// methods

		// getters - setters

	private:
		
};

// operators overload
std::ostream& operator<<(std::ostream& out, const Array& obj);

#endif // ARRAY_CLASS_TPP
