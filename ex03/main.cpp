#include <iostream>

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

#define RESET "\033[0m"
#define DARK_GREEN "\033[38;5;22m"
#define NEON_GREEN "\033[1;92m"
#define RED "\033[1;91m"
#define YELLOW "\033[1;93m"

static void printTitle(const std::string &title)
{
	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << title << std::endl;
	std::cout << "========================================" << std::endl;
}

static void separateLine()
{
	std::cout << DARK_GREEN
			  << "-----------------------------------------------------------------------"
			  << RESET << std::endl;
}

static void testShrubberyCreationForm()
{
	printTitle("TEST 1: CREATE SHRUBBERY CREATION FORM");

	Intern intern;
	AForm *form;

	form = intern.makeForm("shrubbery creation", "garden");
	std::cout << std::endl;
	if (form != NULL)
	{
		std::cout << *form << std::endl;
		separateLine();
		delete form;
	}
}

static void testRobotomyRequestForm()
{
	printTitle("TEST 2: CREATE ROBOTOMY REQUEST FORM");

	Intern intern;
	AForm *form;

	form = intern.makeForm("robotomy request", "Bender");
	std::cout << std::endl;
	if (form != NULL)
	{
		std::cout << *form << std::endl;
		separateLine();
		delete form;
	}
}

static void testPresidentialPardonForm()
{
	printTitle("TEST 3: CREATE PRESIDENTIAL PARDON FORM");

	Intern intern;
	AForm *form;

	form = intern.makeForm("presidential pardon", "Arthur");
	std::cout << std::endl;

	if (form != NULL)
	{
		std::cout << *form << std::endl;
		separateLine();
		delete form;
	}
}

static void testUnknownForm()
{
	printTitle("TEST 4: UNKNOWN FORM");

	Intern intern;
	AForm *form;

	form = intern.makeForm("coffee making", "Office");
	std::cout << std::endl;

	if (form == NULL)
		std::cout << "Form creation correctly failed." << std::endl;
	separateLine();
	delete form;
}

static void testSignAndExecuteForm()
{
	printTitle("TEST 5: CREATE, SIGN AND EXECUTE FORM");

	Intern intern;
	Bureaucrat bureaucrat("Alice", 1);
	AForm *form;

	form = intern.makeForm("shrubbery creation", "home");
	std::cout << std::endl;

	if (form == NULL)
		return;

	std::cout << std::endl;
	std::cout << bureaucrat << std::endl;
	std::cout << *form << std::endl;

	std::cout << std::endl;
	bureaucrat.signForm(*form);

	std::cout << std::endl;
	bureaucrat.executeForm(*form);
	separateLine();
	delete form;
}

static void testInternCopyConstructor()
{
	printTitle("TEST 6: INTERN COPY CONSTRUCTOR");

	Intern original;
	Intern copy(original);

	AForm *form;
	form = copy.makeForm("robotomy request", "Bender");
	std::cout << std::endl;

	if (form != NULL)
	{
		separateLine();
		delete form;		
	}

}

static void testInternAssignmentOperator()
{
	printTitle("TEST 7: INTERN ASSIGNMENT OPERATOR");

	Intern intern1;
	Intern intern2;

	intern2 = intern1;

	AForm *form;


	form = intern2.makeForm("presidential pardon", "Arthur");
	std::cout << std::endl;

	if (form != NULL)
	{
		separateLine();
		delete form;
	}

}

int main()
{
	testShrubberyCreationForm();
	testRobotomyRequestForm();
	testPresidentialPardonForm();
	testUnknownForm();
	testSignAndExecuteForm();
	testInternCopyConstructor();
	testInternAssignmentOperator();

	return (0);
}