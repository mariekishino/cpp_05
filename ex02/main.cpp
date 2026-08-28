#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

static void printTitle(const std::string &title)
{
    std::cout << "\n========== " << title << " ==========\n";
}

int main()
{
    // TEST 1: 正常系
    printTitle("TEST 1: NORMAL EXECUTION");
    try
    {
        Bureaucrat alice("Alice", 1);
        ShrubberyCreationForm form("garden");

        std::cout << form << std::endl;

        alice.signForm(form);
        alice.executeForm(form);

        std::cout << form << std::endl;
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

        charlie.signForm(form);
        charlie.executeForm(form);
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}