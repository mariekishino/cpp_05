#include "Intern.hpp"

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	std::cout << "Intern copy assignment operator called" << std::endl;

	if (this != &other)
	{
		// Intern has no attributes to copy.
	}

	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

static AForm *makePresidential(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

static AForm *makeRobotomy(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *makeShrubbery(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	AForm *(*formGenerator[3])(const std::string &) =
	{
		&makePresidential,
		&makeRobotomy,
		&makeShrubbery
	};

	const std::string formNames[3] =
	{
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			AForm *generatedForm;

			generatedForm = formGenerator[i](target);

			std::cout << "Intern creates "
					  << formName
					  << std::endl;

			return (generatedForm);
		}
	}

	std::cout << "Intern cannot create "
			  << formName
			  << ": unknown form name"
			  << std::endl;

	return (NULL);
}
