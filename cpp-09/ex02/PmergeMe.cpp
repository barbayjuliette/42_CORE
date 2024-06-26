/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:07:29 by jbarbay           #+#    #+#             */
/*   Updated: 2024/07/01 16:53:04 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Constructors
PmergeMe::PmergeMe(void)
{

}

PmergeMe::PmergeMe(char *argv[], int argc, std::string container)
{
	this->length = argc - 1;
	if (container == "vector")
	{
		type = "vector";
		clock_t	start = clock();
		unsorted_vector = create_container<std::vector<int> >(argv, argc);
		this->sort_vector();
		clock_t	end = clock();
		time = (double(end - start) / CLOCKS_PER_SEC) * 1000000;
	}
	else if (container == "list")
	{
		type = "list";
		clock_t	start = clock();
		unsorted_list = create_container<std::list<int> >(argv, argc);
		this->sort_list();
		clock_t	end = clock();
		time = (double(end - start) / CLOCKS_PER_SEC) * 1000000;
	}
}

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe& copy) : 
unsorted_vector(copy.unsorted_vector),
sorted_vector(copy.sorted_vector),
unsorted_list(copy.unsorted_list),
sorted_list(copy.sorted_list),
length(copy.length),
time(copy.time)
{
	std::cout << "Copy constructor called\n";
}

// Assignment operator
PmergeMe&	PmergeMe::operator=(PmergeMe const& rhs)
{
	if (this != &rhs)
	{
		unsorted_vector = rhs.unsorted_vector;
		sorted_vector = rhs.sorted_vector;
		unsorted_list = rhs.unsorted_list;
		sorted_list = rhs.sorted_list;
		length = rhs.length;
		time = rhs.time;
	}
	return (*this);
}

// Destructor
PmergeMe::~PmergeMe(void)
{

}

// Member functions
void	PmergeMe::print_result()
{
	std::cout << "Before: ";
	print_vector(unsorted_vector);
	std::cout << std::endl;

	std::cout << "After: ";
	print_vector(sorted_vector);
	std::cout << std::endl;
}

void	PmergeMe::print_time()
{
	if (type == "vector")
	{
		std::cout << "Time to process a range of " << length << " elements with std::[vector]: ";
		std::cout << time << " us" << std::endl;
	}
	else if (type == "list")
	{
		std::cout << "Time to process a range of " << length << " elements with std::[list]: ";
		std::cout << time << " us" << std::endl;
	}
}

// GETTERS

std::vector<int>	PmergeMe::get_sorted_vector()
{
	return (this->sorted_vector);
}

std::list<int>		PmergeMe::get_sorted_list()
{
	return (this->sorted_list);
}

/*---------------------------------------- VECTOR ----------------------------------------*/

std::vector<std::vector<int> >	PmergeMe::pair_up(std::vector<int> nums, bool even)
{
	std::vector<std::vector<int> >	pairs;
	std::vector<int>				couple;

	if (!even)
		nums.pop_back();
	std::vector<int>::const_iterator	it;
	std::vector<int>::const_iterator	it2;
	for (it = nums.begin(); it != nums.end(); it++)
	{
		it2 = it + 1;
		if (*it > *it2)
		{
			couple.push_back(*it);
			couple.push_back(*it2);
		}
		else
		{
			couple.push_back(*it2);
			couple.push_back(*it);
		}
		pairs.push_back(couple);
		couple.clear();
		it = it2;
	}
	return (pairs);
}

void	PmergeMe::insert_elem(std::vector<std::vector<int> > &pairs, std::vector<int> elem, int n)
{
	if (n < 0)
		pairs[0] = elem;
	else if (elem[0] >= pairs[n][0])
	{
		int	len = pairs.size();
		if (n == len - 1)
			pairs.push_back(elem);
		else
			pairs[n + 1] = elem;
	}
	else
	{
		int	len = pairs.size();
		if (n == len - 1)
			pairs.push_back(pairs[n]);
		else
		{
			pairs[n + 1] = pairs[n];
			insert_elem(pairs, elem, n - 1);
		}
	}
}

void	PmergeMe::create_pend_main(std::vector<std::vector<int> >	pairs, std::vector<int> &main, std::vector<int> &pend)
{
	std::vector<std::vector<int> >::const_iterator	it;

	it = pairs.begin();
	main.push_back((*it)[1]);
	main.push_back((*it)[0]);
	it++;
	for (; it != pairs.end(); it++)
	{
		main.push_back((*it)[0]);
		pend.push_back((*it)[1]);
	}
	pairs.clear();
}

void	PmergeMe::insertion_sort_pairs(std::vector<std::vector<int> > &pairs, int n)
{
	if ( n == 0)
		return ;
	else
	{
		insertion_sort_pairs(pairs, n - 1);
		insert_elem(pairs, pairs[n], n - 1);
	}
}

void	PmergeMe::sort_pairs(std::vector<std::vector<int> > &pairs)
{
	int	len = pairs.size();
	insertion_sort_pairs(pairs, len - 1);
}

std::vector<int>	PmergeMe::create_insertion_order(std::vector<int> pend)
{
	int	len = pend.size();
	int	jacob_index = 3;
	std::vector<int>	insertion_sequence;

	int num = jacobsthal(jacob_index);
	while (num < len - 1)
	{
		insertion_sequence.push_back(num);
		jacob_index++;
		num = jacobsthal(jacob_index);
	}
	return (insertion_sequence);
}

std::vector<int>	PmergeMe::create_index_sequence(std::vector<int> &pend)
{
	std::vector<int>	jacobsthal = create_insertion_order(pend);
	std::vector<int>	sequence;
	bool				last = false;
	int					i = 1;

	sequence.push_back(1);
	std::vector<int>::const_iterator	it;
	for (it = pend.begin(); it != pend.end(); it++)
	{
		if (jacobsthal.size() != 0 && last == false)
		{
			sequence.push_back(jacobsthal[0]);
			jacobsthal.erase(jacobsthal.begin());
			last = true;
		}
		else
		{
			std::vector<int>::iterator it2;
			for (it2 = sequence.begin() ; it2 != sequence.end(); it2++)
			{
				if ( *it2 == i )
				{
					i++;
				}
			}
				sequence.push_back(i);
				last = false;
				i++;
		}
	}
	return (sequence);
}

void	PmergeMe::insert_at_index(std::vector<int> &main, int num)
{
	int	index = binary_search(main, num);
	main.insert(main.begin() + index, num);
}

void	PmergeMe::insert_to_main(std::vector<int> &main, std::vector<int> sequence, std::vector<int> &pend)
{
	std::vector<int>::iterator	it;
	int							num_to_insert;
	int							index;
	int							pos;

	for (it = sequence.begin(); it != sequence.end(); it++)
	{
		index = *it - 1;
		if (index >= 0 && index < static_cast<int>(pend.size()))
		{
			num_to_insert = pend[index];
			pos = binary_search(main, num_to_insert);
			main.insert(main.begin() + pos, num_to_insert);
		}
	}
}

void	PmergeMe::sort_vector(void)
{
	std::vector<std::vector<int> >	pairs;
	std::vector<int>				pend;
	std::vector<int>				main;
	std::vector<int>				sequence;
	
	bool	even = (unsorted_vector.size() % 2 == 0 ? true : false);
	int		single = (even ? -1 : unsorted_vector.back());

	if (is_sorted(unsorted_vector))
	{
		std::cout << "Numbers are already sorted\n";
		sorted_vector = unsorted_vector;
		return ;
	}
	pairs = pair_up(unsorted_vector, even);
	sort_pairs(pairs);
	create_pend_main(pairs, main, pend);
	sequence = create_index_sequence(pend);
	insert_to_main(main, sequence, pend);
	if (single != -1)
		insert_at_index(main, single);
	sorted_vector = main;
}

/*---------------------------------------- LIST ----------------------------------------*/

void	PmergeMe::sort_list(void)
{
	std::list<std::list<int> >	pairs;
	std::list<int>				pend;
	std::list<int>				main;
	std::list<int>				sequence;
	
	bool	even = (unsorted_list.size() % 2 == 0 ? true : false);
	int		single = (even ? -1 : unsorted_list.back());

	if (is_sorted(unsorted_list))
	{
		std::cout << "Numbers are already sorted\n";
		sorted_list = unsorted_list;
		return ;
	}
	pairs = pair_up(unsorted_list, even);
	sort_pairs(pairs);
	create_pend_main(pairs, main, pend);
	sequence = create_index_sequence(pend);
	insert_to_main(main, sequence, pend);
	if (single != -1)
		insert_at_index(main, single);
	sorted_list = main;
}

std::list<std::list<int> >	PmergeMe::pair_up(std::list<int> nums, bool even)
{
	std::list<std::list<int> >	pairs;
	std::list<int>				couple;

	if (!even)
		nums.pop_back();
	std::list<int>::iterator	it;
	std::list<int>::iterator	it2;
	for (it = nums.begin(); it != nums.end(); it++)
	{
		it2 = it;
		std::advance(it2, 1);
		if (*it > *it2)
		{
			couple.push_back(*it);
			couple.push_back(*it2);
		}
		else
		{
			couple.push_back(*it2);
			couple.push_back(*it);
		}
		pairs.push_back(couple);
		couple.clear();
		it = it2;
	}
	return (pairs);
}

void	PmergeMe::sort_pairs(std::list<std::list<int> > &pairs)
{
	int	len = pairs.size();
	insertion_sort_pairs(pairs, len - 1);
}

void	PmergeMe::insertion_sort_pairs(std::list<std::list<int> > &pairs, int n)
{
	std::list<std::list<int> >::iterator	list = pairs.begin();

	if ( n == 0)
		return ;
	else
	{
		insertion_sort_pairs(pairs, n - 1);
		std::advance(list, n);
		insert_elem(pairs, *list, n - 1);
	}
}

void	PmergeMe::insert_elem(std::list<std::list<int> > &pairs, std::list<int> elem, int n)
{
	std::list<std::list<int> >::iterator	it = pairs.begin();
	std::advance(it, n);
	std::list<std::list<int> >::iterator	next = it;
	std::advance(next, 1);

	if (n < 0)
		*pairs.begin() = elem;
	else if (elem.front() >= (*it).front())
	{
		int	len = pairs.size();
		if (n == len - 1)
			pairs.push_back(elem);
		else
			*next = elem;
	}
	else
	{
		int	len = pairs.size();
		if (n == len - 1)
			pairs.push_back(*it);
		else
		{
			*next = *it;
			insert_elem(pairs, elem, n - 1);
		}
	}
}

void	PmergeMe::create_pend_main(std::list<std::list<int> > &pairs, std::list<int> &main, std::list<int> &pend)
{
	std::list<std::list<int> >::const_iterator	it;
	it = pairs.begin();

	main.push_back((*it).back());
	main.push_back((*it).front());
	it++;
	for (; it != pairs.end(); it++)
	{
		main.push_back((*it).front());
		pend.push_back((*it).back());
	}
	pairs.clear();
}

std::list<int>	PmergeMe::create_index_sequence(std::list<int> &pend)
{
	std::list<int>		jacobsthal = create_insertion_order(pend);
	std::list<int>		sequence;
	bool				last = false;
	int					i = 1;

	sequence.push_back(1);
	std::list<int>::const_iterator	it;
	for (it = pend.begin(); it != pend.end(); it++)
	{
		if (jacobsthal.size() != 0 && last == false)
		{
			sequence.push_back(jacobsthal.front());
			jacobsthal.erase(jacobsthal.begin());
			last = true;
		}
		else
		{
			std::list<int>::iterator it2;
			for (it2 = sequence.begin() ; it2 != sequence.end(); it2++)
			{
				if ( *it2 == i )
				{
					i++;
				}
			}
				sequence.push_back(i);
				last = false;
				i++;
		}
	}
	return (sequence);
}

std::list<int>	PmergeMe::create_insertion_order(std::list<int> pend)
{
	int	len = pend.size();
	int	jacob_index = 3;
	std::list<int>	insertion_sequence;

	int num = jacobsthal(jacob_index);
	while (num < len - 1)
	{
		insertion_sequence.push_back(num);
		jacob_index++;
		num = jacobsthal(jacob_index);
	}
	return (insertion_sequence);
}

void	PmergeMe::insert_to_main(std::list<int> &main, std::list<int> sequence, std::list<int> &pend)
{
	std::list<int>::iterator	it;
	std::list<int>::iterator	p_it;
	std::list<int>::iterator	m_it;
	int							num_to_insert;
	int							index;
	int							pos;

	for (it = sequence.begin(); it != sequence.end(); it++)
	{
		index = *it - 1;
		if (index >= 0 && index < static_cast<int>(pend.size()))
		{
			p_it = pend.begin();
			std::advance(p_it, index);
			num_to_insert = *p_it;

			pos = binary_search(main, num_to_insert);
			m_it = main.begin();
			std::advance(m_it, pos);
			main.insert(m_it, num_to_insert);
		}
	}
}

int	binary_search( std::list<int> main, int x )
{
	int 						low = 0;
	int 						high = main.size();
	int							mid;
	std::list<int>::iterator	it = main.begin();

	while (low < high)
	{
		it = main.begin();
		mid = ( low + high ) / 2;
		std::advance(it, mid);
		if ( x  < *it )
			high = mid;
		else
			low = mid + 1;
	}
	return (low);
}

void	PmergeMe::insert_at_index(std::list<int> &main, int num)
{
	int							index = binary_search(main, num);
	std::list<int>::iterator	it = main.begin();
	
	std::advance(it, index);
	main.insert(it, num);
}

/*---------------------------------------- HELPERS ----------------------------------------*/

bool	is_sorted(std::vector<int> vector)
{
	size_t	i = 0;
	int	prev = INT_MIN;

	while ( i < vector.size())
	{
		if (vector[i] < prev)
			return (false);
		prev = vector[i];
		i++;
	}
	return (true);
}

bool	is_sorted(std::list<int> list)
{
	int							prev = INT_MIN;
	std::list<int>::iterator	it;
	for (it = list.begin(); it != list.end(); it++)
	{
		if (*it < prev)
			return (false);
		prev = *it;
	}
	return (true);
}

int	binary_search( std::vector<int> main, int x )
{
	int 	low = 0;
	int 	high = main.size();
	int		mid;

	while (low < high)
	{
		mid = ( low + high ) / 2;
		if ( x  < main[mid] )
			high = mid;
		else
			low = mid + 1;
	}
	return (low);
}

int	jacobsthal(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacobsthal(n - 1) + jacobsthal(n - 2) * 2);
}

void	print_list(std::list<int> list)
{
	std::list<int>::const_iterator	it;

	for (it = list.begin(); it != list.end(); it++)
	{
		std::cout << *it;
		std::cout << " ";
	}
}

void	print_vector(std::vector<int> vector)
{
	std::vector<int>::const_iterator	it;

	for (it = vector.begin(); it != vector.end(); it++)
	{
		std::cout << *it;
		std::cout << " ";
	}
}