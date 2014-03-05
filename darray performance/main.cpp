//
//  main.cpp
//  darray performance
//
//  Created by Patrick Sauter on 3/5/14.
//  Copyright (c) 2014 Patrick Sauter. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <array>
#include <ctime>

#include "darray.h"

int ms(clock_t start, clock_t stop)
{
    return (int)( 1000.0 * ( stop - start ) / CLOCKS_PER_SEC );
}

template <std::size_t inner_size, std::size_t outer_size, std::size_t moves>
void test1() {
	std::array<std::array<float, inner_size>, outer_size> DERP;
	std::array<std::array<float, inner_size>, outer_size> derp;
	
	for (auto i = 0; i < moves; i++)
		derp = std::move(DERP);
}

template <std::size_t inner_size, std::size_t outer_size, std::size_t moves>
void test2() {
	std::array<darray<float, inner_size>, outer_size> DERP;
	std::array<darray<float, inner_size>, outer_size> derp;
	
	for (auto i = 0; i < moves; i++)
		derp = std::move(DERP);
}

template <std::size_t inner_size, std::size_t outer_size, std::size_t moves>
void test() {
	clock_t volatile start;
    clock_t volatile stop;

	start = clock();
	test1<inner_size, outer_size, moves>();
	stop = clock();
	
	std::cout << std::setw(6) << ms(start,stop) << "    std::array<std::array<float," << inner_size << ">, " << outer_size << "> w/ " << moves << " moves" << std::endl;
	
	start = clock();
	test2<inner_size, outer_size, moves>();
	stop = clock();

	std::cout << std::setw(6) << ms(start,stop) << "    std::array<darray<float," << inner_size << ">, " << outer_size << "> w/ " << moves << " moves" << std::endl;
}


int main(int argc, const char * argv[])
{
	test<100, 100000, 0>();
	test<100000, 100, 0>();
	
	test<100, 100000, 50>();
	test<100000, 100, 50>();
	
	test<100, 100000, 500>();
	test<100000, 100, 500>();
	
    return 0;
}