/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:10:16 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/03 16:28:23 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
	std::cout << BLUE << "--- Test random generation ---" << WHITE << std::endl;
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;

	std::cout << std::endl << BLUE << "--- Test each type ---" << WHITE << std::endl;

	Base *a = new A();
	Base *b = new B();
	Base *c = new C();

	std::cout << "Should be A: \n";
	identify(a);
	identify(*a);

	std::cout << "Should be B: \n";
	identify(b);
	identify(*b);

	std::cout << "Should be C: \n";
	identify(c);
	identify(*c);

	delete a;
	delete b;
	delete c;
	return 0;
}
