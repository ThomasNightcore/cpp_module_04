/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classTests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 23:25:57 by nightcore         #+#    #+#             */
/*   Updated: 2025/08/18 02:37:20 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Ice.hpp"
#include "../Cure.hpp"
#include "../MateriaSource.hpp"
#include "../Character.hpp"
#include <iostream>

static void testCure(void)
{
    std::cout << "Creating new cure" << std::endl;
    Cure *cure = new Cure();
    std::cout << "* Cure type is: \'" << cure->getType() << "\'" << std::endl;
    std::cout << "Copying cure stored as AMateria..." << std::endl;
    AMateria *copy = new Cure(*cure);
    std::cout << "Deleting original cure" << std::endl;
    delete cure;
    std::cout << "Copied cure type after original deletion is: \'" << copy->getType() << "\'" << std::endl;

    std::cout << "Assigning new locally created stack cure and ice onto copy (type shouldn't change)" << std::endl;
    *copy = Cure();
    std::cout << "* Type is: \'" << copy->getType() << "\'" << std::endl;
    *copy = Ice();
    std::cout << "* Type is: \'" << copy->getType() << "\'" << std::endl;

    delete copy;
}

static void testIce(void)
{
    std::cout << "Creating new ice" << std::endl;
    Ice *ice = new Ice();
    std::cout << "* Ice type is: \'" << ice->getType() << "\'" << std::endl;
    std::cout << "Copying ice stored as AMateria..." << std::endl;
    AMateria *copy = new Ice(*ice);
    std::cout << "Deleting original ice" << std::endl;
    delete ice;
    std::cout << "Copied ice type after original deletion is: \'" << copy->getType() << "\'" << std::endl;

    std::cout << "Assigning new locally created stack cure and ice onto copy "
              << "(type shouldn't change)" << std::endl;
    *copy = Cure();
    std::cout << "* Type is: \'" << copy->getType() << "\'" << std::endl;
    *copy = Ice();
    std::cout << "* Type is: \'" << copy->getType() << "\'" << std::endl;

    delete copy;
}

static void checkMateriaRecepies(MateriaSource &src)
{
    std::cout << "* Checking Materia Recipies:" << std::endl; 
    AMateria *tmp;

    tmp = src.createMateria("ice");
    std::cout << "  - Source has ice ?     " 
              << (tmp == NULL ? "[false]" : "[true]") 
              << std::endl;
    if (tmp != NULL)
        delete tmp;

    tmp = src.createMateria("cure");
    std::cout << "  - Source has cure ?    " 
              << (tmp == NULL ? "[false]" : "[true]") 
              << std::endl;
    if (tmp != NULL)
        delete tmp;
}

static void testMateriaSource(void)
{
    std::cout << "Creating new MateriaSource" << std::endl;
    MateriaSource *src = new MateriaSource();
    std::cout << "Learing Ice and Cure" << std::endl;
    src->learnMateria(new Ice());
    //src->learnMateria(new Cure());
    checkMateriaRecepies(*src);
    std::cout << "Copying original MateriaSource into new obj. "
              << "And deleting original one" << std::endl;
    MateriaSource *copy = new MateriaSource(*src);
    delete src;
    checkMateriaRecepies(*copy);

    std::cout << "Assigning new empy MateriaSource with no learned Materia to copy." << std::endl 
              << "Copy should now have no ice and cure learned anymore." << std::endl;
    *copy = MateriaSource();
    checkMateriaRecepies(*copy);

    delete copy;
}

static void testCharacterInventory(Character &character, Character &target)
{
    std::cout << "Using character \'" << character.getName() << "\' inventory" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << "   [" << i << "] ";
        character.use(i, target);
        std::cout << std::endl;
    }
}

static void testCharacter(void)
{
    MateriaSource src;
    src.learnMateria(new Ice());
    src.learnMateria(new Cure());
    Character target("target");

    std::cout << "Creating new character" << std::endl;
    Character *original = new Character("Original");
    original->equip(src.createMateria("ice"));
    original->equip(src.createMateria("ice"));
    original->equip(src.createMateria("cure"));
    testCharacterInventory(*original, target);

    std::cout << "Copying original into new copy character "
              << "and deleting original one (inventory should be the same)" << std::endl;

    Character *copy = new Character(*original);
    delete original;
    testCharacterInventory(*copy, target);

    std::cout << "Assigning newly created empty character to copy "
              << "(inventory should now be empty)" << std::endl;
    *copy = Character("override");
    testCharacterInventory(*copy, target);

    delete copy;
}

void runClassTests(void)
{
    std::cout << std::endl
              << "========"
              << " Testing Cure "
              << "======== " << std::endl;
    testCure();

    std::cout << std::endl
              << "========"
              << " Testing Ice "
              << "========" << std::endl;
    testIce();

    std::cout << std::endl
              << "========"
              << " Testing MateriaSource "
              << "========" << std::endl;
    testMateriaSource();

    std::cout << std::endl
              << "========"
              << " Testing Character "
              << "========" << std::endl;
    testCharacter();
}
