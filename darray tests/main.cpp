//
//  main.cpp
//  darray tests
//
//  Created by Patrick Sauter on 3/5/14.
//  Copyright (c) 2014 Patrick Sauter. All rights reserved.
//

#include <iostream>
#include "darray.h"

int main(int argc, const char * argv[])
{
	darray<float, 3>	test{1,2,3};
			
	for (auto i = test.begin(); i != test.end(); i++)
		std::cout << *i << " ";
		
	for (auto i = test.cbegin(); i != test.cend(); i++) {
		// *i = 1.0; ERROR
		std::cout << *i << " ";
	}
	
	for (auto i = test.rbegin(); i != test.rend(); i++) {
		std::cout << *i << " ";
	}
	
	for (auto i = test.crbegin(); i != test.crend(); i++) {
		// *i = 2.0; ERROR
		std::cout << *i << " ";
	}
	
	std::cout << std::endl << test[0] << " " << test[1] << " " << test[2];
	
	darray<float, 5>	test2 = { 1, 2, 3 };
	
	test2[3] = 25;
	test2.back() = 100;
	
	std::cout << std::endl << test2.front() << " " << test2[1] << " " << test2.back() << std::endl;
	
	for (auto i : test2) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	
	test2.fill(50);
	
	for (auto i : test2) {
		std::cout << i << " ";
	}
	
	std::cout << std::endl;
	
	try {
		test2.at(50);
	}
	catch (...) {
		std::cout << "EXCEPTION OH NOOOOO" << std::endl;
	}
	
	darray<float, 5>	test3(test2);
	darray<float, 5>	test4 = std::move(test3);
	
	for (auto i = test4.begin(); i != test4.end(); i++) {
		std::cout << *i << " ";
	}
	std::cout << std::endl;

	
	
	darray<float, 5>	test5;
	
	test5 = test4;
	test5 = std::move(test4);
	
	for (auto i = test4.begin(); i != test4.end(); i++) {
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	
    return 0;
}

