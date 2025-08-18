/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   customTests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 23:26:01 by nightcore         #+#    #+#             */
/*   Updated: 2025/08/18 12:37:15 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Ice.hpp"
#include "../Cure.hpp"
#include "../MateriaSource.hpp"
#include "../Character.hpp"
#include <iostream>

static void testEquiping(void)
{
    MateriaSource src;
    src.learnMateria(new Ice());
    src.learnMateria(new Cure());
    Character *target = new Character("target");
    Character *character = new Character("some guy");
    std::cout << "Created test character \'" << character->getName() 
              << "\' and target character \'" << target->getName()
              << "\'" << std::endl;

    // for (int i = 0; i < 4; i++)
    //    character->equip(src.createMateria("ice"));

    std::cout << "Using and empty inventory from test character" << std::endl;
    for (int i = 0; i < 4; i++)
        character->use(i, *target);
    
    character->equip(src.createMateria("ice"));
    character->equip(src.createMateria("cure"));
    character->equip(src.createMateria("cure"));
    character->equip(src.createMateria("ice"));

    std::cout << " * testing equip with full inventory" << std::endl;
    AMateria *tmp = new Ice();
    character->equip(tmp);
    *tmp = Cure();
    character->equip(tmp);
    delete tmp;
    std::cout << std::endl;

    std::cout << "Filling the inventory and using it again" << std::endl;
    for (int i = 0; i < 4; i++)
        character->use(i, *target);

    
    std::cout << "Trying use with invalid indexes" << std::endl;
    character->use(-2, *target);
    character->use(5, *target);

    delete character;
    target->use(2, *character);

    delete target;
}

static void testUnequipingLeaks(void)
{
    Character target("target");
    MateriaSource src;
    src.learnMateria(new Ice());
    src.learnMateria(new Cure());

    std::cout << " * there should be no leaks coming from here... " 
              << "make sure to check with valgrind --leak-check=full" <<  std::endl;
    Character *character = new Character("guy");
    // There should be no leaks from the allocations here...
    // Materias unequiped have to be handled on their own
    AMateria *tmp1 = new Cure();
    AMateria *tmp2 = new Cure();
    AMateria *tmp3 = new Cure();
    AMateria *tmp4 = new Ice();
    // Creating an extra Materia that cannot be stored... 
    AMateria *tmp5 = new Ice();

    character->equip(tmp1);
    character->equip(tmp2);
    character->equip(tmp3);
    character->equip(tmp4);
    character->equip(tmp5); // Shouldn't do anything

    std::cout << "Equiping materia and using it" << std::endl;
    for (int i = 0; i < 4; i++)
        character->use(i, target);

    std::cout << "Unequiping previously used materia and trying to use empty inventory" << std::endl;
    for (int i = 0; i < 4; i++)
        character->unequip(i);

    // Nothing should happen here since the inverntory was unequipped... 
    for (int i = 0; i < 4; i++)
        character->use(i, target);

    std::cout << "Equiping new materia and using it" << std::endl;
    for (int i = 0; i < 4; i++)
        character->equip(src.createMateria(i & 1 ? "ice" : "cure"));

    for (int i = 0; i < 4; i++)
        character->use(i, target);

    delete character;

    // If we don't delete the previously unequiped Materias here there will be a leak
    delete tmp1;
    delete tmp2;
    delete tmp3;
    delete tmp4;
    delete tmp5;
}

void runCustomTests(void)
{
    std::cout << std::endl
              << "=========="
              << " Checking equiping/unequiping "
              << "==========" << std::endl;
    testEquiping();

    std::cout << std::endl
              << "=========="
              << " Checking for leaks when unequiping Materia "
              << "==========" << std::endl;
    testUnequipingLeaks();
}
