/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:07:20 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/16 19:14:22 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PMERGEME_HPP__
# define __PMERGEME_HPP__

#include <iostream>
#include <string> 
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <time.h>
#include <list>
#include <iomanip>

#define WHITE "\e[0;97m"
#define RED "\e[31m"

void				print_vector(std::vector<int> vector);
void				print_list(std::list<int> list);
bool				is_sorted(std::vector<int> vector);
int					binary_search( std::vector<int> main, int x );
int					binary_search( std::list<int> main, int x );
int					jacobsthal(int n);
bool				is_sorted(std::list<int> list);
void				print_vector(std::vector<int> vector);
void				print_pairs_list(std::list<std::list<int> > list);

template <typename T>
T	create_container(char *argv[], int argc)
{
	T		unsorted;
	int		i = 1;
	int		n;

	while (i < argc)
	{
		n = std::atoi(argv[i]);
		if (n <= 0)
			throw (std::runtime_error("Please enter only positive numbers"));
		unsorted.push_back(n);
		i++;
	}
	return (unsorted);
}

class PmergeMe
{
	private:
		PmergeMe(void);
		std::vector<int>	unsorted_vector;
		std::vector<int>	sorted_vector;
		std::list<int>		unsorted_list;
		std::list<int>		sorted_list;
		int					length;
		double				time_vector;
		double				time_list;
		
	public:
		// Constructors
		PmergeMe(char *argv[], int argc, std::string container);

		// Copy constructor
		PmergeMe(const PmergeMe& copy);
		
		// Assignment operator
		PmergeMe&	operator=(PmergeMe const& rhs);

		// Destructor
		~PmergeMe(void);

		// Getters
		std::vector<int>	get_sorted_vector();
		std::list<int>		get_sorted_list();
		
		// Member functions
		void							print_result(void);
		void							sort_vector(void);
		std::vector<std::vector<int> >	pair_up(std::vector<int> nums, bool even);
		void							insert_elem(std::vector<std::vector<int> > &pairs, std::vector<int> elem, int n);
		void							insertion_sort_pairs(std::vector<std::vector<int> > &pairs, int n);
		void							create_pend_main(std::vector<std::vector<int> >	pairs, std::vector<int> &main, std::vector<int> &pend);
		void							sort_pairs(std::vector<std::vector<int> > &pairs);
		std::vector<int>				create_insertion_order(std::vector<int> pend);
		std::vector<int>				create_index_sequence(std::vector<int> &pend);
		void							insert_at_index(std::vector<int> &main, int num);
		void							insert_to_main(std::vector<int> &main, std::vector<int> sequence, std::vector<int> &pend);


		void							sort_list(void);
		std::list<std::list<int> >		pair_up(std::list<int> nums, bool even);
		void							sort_pairs(std::list<std::list<int> > &pairs);
		void							insertion_sort_pairs(std::list<std::list<int> > &pairs, int n);
		void							insert_elem(std::list<std::list<int> > &pairs, std::list<int> elem, int n);
		void							create_pend_main(std::list<std::list<int> >	&pairs, std::list<int> &main, std::list<int> &pend);
		std::list<int>					create_insertion_order(std::list<int> pend);
		std::list<int>					create_index_sequence(std::list<int> &pend);
		void							insert_to_main(std::list<int> &main, std::list<int> sequence, std::list<int> &pend);
		void							insert_at_index(std::list<int> &main, int num);

};

#endif