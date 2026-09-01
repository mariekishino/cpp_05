#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define RESET "\033[0m"
#define DARK_GREEN "\033[38;5;22m"
#define NEON_GREEN "\033[1;92m"
#define RED "\033[1;91m"
#define YELLOW "\033[1;93m"


static void printTitle(const std::string &title)
{
    std::cout << "\n========== " << title << " ==========\n";
}

static void separateLine()
{
	std::cout << DARK_GREEN
			  << "-----------------------------------------------------------------------"
			  << RESET << std::endl;
}

int main()
{
    // TEST 1: 正常系
    printTitle("TEST 1: NORMAL EXECUTION");
    try
    {
        Bureaucrat alice("Alice", 1);
        ShrubberyCreationForm form("garden");
		separateLine();

        std::cout << form << std::endl;

        alice.signForm(form);
        alice.executeForm(form);

        std::cout << form << std::endl;
		separateLine();
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // TEST 2: 未署名のまま execute
    printTitle("TEST 2: EXECUTE UNSIGNED FORM");
    try
    {
        Bureaucrat alice("Alice", 1);
        ShrubberyCreationForm form("park");
		separateLine();

        alice.executeForm(form);
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // TEST 3: 署名grade不足
    printTitle("TEST 3: GRADE TOO LOW TO SIGN");
    try
    {
        Bureaucrat bob("Bob", 150);
        ShrubberyCreationForm form("forest");
		separateLine();

        bob.signForm(form);
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // TEST 4: 署名はできるがexecuteのgrade不足
    printTitle("TEST 4: GRADE TOO LOW TO EXECUTE");
    try
    {
        Bureaucrat charlie("Charlie", 140);
        ShrubberyCreationForm form("yard");
		separateLine();

        charlie.signForm(form);
        charlie.executeForm(form);
		separateLine();
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}