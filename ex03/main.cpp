/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 21:42:50 by nightcore         #+#    #+#             */
/*   Updated: 2025/08/18 02:11:26 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include <iostream>

void runSubjectTests(void);
void runCustomTests(void);
void runClassTests(void);

int main(void)
{
    std::cout << "Enter which tests you want to run:" << std::endl
              << " * (1) Run constructor, deep copy and assignment tests" << std::endl
              << " * (2) Run subject test" << std::endl
              << " * (3) Run custom test" << std::endl
              << " * (4) All of the above" << std::endl;

    char input;
    std::cin >> std::ws >> input;

    bool test1 = (input == '4') ? true : ((input == '1') ? true : false);
    bool test2 = (input == '4') ? true : ((input == '2') ? true : false);
    bool test3 = (input == '4') ? true : ((input == '3') ? true : false);

    if (!(test1 || test2 || test3))
    {
        std::cout << std::endl <<  "Invalid input. Exiting..." << std::endl;
        return 0;
    }

    if (test1)
    {
        std::cout << std::endl << std::endl
                  << " *** ======================= *** "
                  << " Running constructor, deep copy and assignment tests "
                  << " *** ======================= *** " << std::endl;
        runClassTests();
    }
    if (test2)
    {
        std::cout << std::endl << std::endl
                  << " *** ================================ *** "
                  << " Running test provided by subject "
                  << " *** ================================= *** "
                  << std::endl;
        runSubjectTests();
    }
    if (test3)
    {
        std::cout << std::endl << std::endl
                  << " *** ==================================== *** "
                  << " Running custom made tests "
                  << " *** ==================================== *** "
                  << std::endl;
        runCustomTests();
    }

    return 0;
}