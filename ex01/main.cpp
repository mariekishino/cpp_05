#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

#define RESET "\033[0m"
#define DARK_GREEN "\033[38;5;22m"
#define NEON_GREEN "\033[1;92m"
#define RED "\033[1;91m"
#define YELLOW "\033[1;93m"

static void printTitle(const std::string &title)
{
    std::cout << std::endl;
    std::cout << DARK_GREEN;
    std::cout << "========================================" << std::endl;
    std::cout << title << std::endl;
    std::cout << "========================================";
    std::cout << RESET << std::endl;
}

static void separateLine()
{
	std::cout << DARK_GREEN
			  << "-----------------------------------------------------------------------"
			  << RESET << std::endl;
}


// test 1

static void testFormCreation(void)
{
    printTitle("TEST 1: VALID FORM CREATION");

    try
    {
        Form form(30, 20);
		separateLine();
		std::cout << std::endl;

        std::cout << "Name          : " << form.getName() << std::endl;
        std::cout << "Signed        : "
                  << (form.getIsSigned() ? "true" : "false") << std::endl;
        std::cout << "Grade to sign : " << form.getGradeToSign() << std::endl;
        std::cout << "Grade to exec : " << form.getGradeToExec() << std::endl;
		std::cout << std::endl;
		separateLine();
    }
    catch (const std::exception &e)
    {
        std::cout << RED << "Unexpected exception: "
                  << e.what() << RESET << std::endl;
    }
}

static void testSuccessfulSign(void)
{
    printTitle("TEST 2: SUCCESSFUL SIGN");

    try
    {
        Bureaucrat alice("Alice", 20);
        Form form(30, 20);
		separateLine();
		std::cout << std::endl;

        std::cout << "Before signing: "
                  << (form.getIsSigned() ? "signed" : "not signed")
                  << std::endl;

        alice.signForm(form);

        std::cout << "After signing : "
                  << (form.getIsSigned() ? "signed" : "not signed")
                  << std::endl;

		std::cout << std::endl;
		separateLine();
    }
    catch (const std::exception &e)
    {
        std::cout << RED << "Unexpected exception: "
                  << e.what() << RESET << std::endl;
    }
}

static void testFailedSign(void)
{
    printTitle("TEST 3: FAILED SIGN - GRADE TOO LOW");

    try
    {
        Bureaucrat bob("Bob", 50);
        Form form(30, 20);
		separateLine();
		std::cout << std::endl;

        std::cout << "Bureaucrat grade : " << bob.getGrade() << std::endl;
        std::cout << "Required grade   : " << form.getGradeToSign() << std::endl;

        bob.signForm(form);

    	std::cout << "Signed status    : "
              	  << (form.getIsSigned() ? "signed" : "not signed")
              	  << std::endl;
		std::cout << std::endl;
		separateLine();
    }
    catch (const std::exception &e)
    {
        std::cout << YELLOW
                  << "Expected exception caught: "
                  << e.what()
                  << RESET << std::endl;
    }
}

static void testExactRequiredGrade(void)
{
    printTitle("TEST 4: EXACT REQUIRED GRADE");

    try
    {
        Bureaucrat charlie("Charlie", 30);
        Form form(30, 20);
		separateLine();
		std::cout << std::endl;

        std::cout << "Signed status before: "
                  << (form.getIsSigned() ? "signed" : "not signed")
                  << std::endl;

        charlie.signForm(form);

        std::cout << "Signed status after: "
                  << (form.getIsSigned() ? "signed" : "not signed")
                  << std::endl;
		
		std::cout << std::endl;
		separateLine();
    }
    catch (const std::exception &e)
    {
        std::cout << RED << "Unexpected exception: "
                  << e.what() << RESET << std::endl;
    }
}

static void testFormGradeTooHigh(void)
{
    printTitle("TEST 5: FORM GRADE TOO HIGH");

    try
    {
        Form form(0, 20);
		separateLine();
		std::cout << std::endl;

    }
    catch (const Form::GradeTooHighException &e)
    {
        std::cout << YELLOW
                  << "Expected exception caught: "
                  << e.what()
                  << RESET << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << RED
                  << "Wrong exception caught: "
                  << e.what()
                  << RESET << std::endl;
    }
}

static void testFormGradeTooLow(void)
{
    printTitle("TEST 6: FORM GRADE TOO LOW");

    try
    {
        Form form(30, 151);
		separateLine();
		std::cout << std::endl;
    }
    catch (const Form::GradeTooLowException &e)
    {
        std::cout << YELLOW
                  << "Expected exception caught: "
                  << e.what()
                  << RESET << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << RED
                  << "Wrong exception caught: "
                  << e.what()
                  << RESET << std::endl;
    }
}

static void testAlreadySignedForm(void)
{
    printTitle("TEST 7: SIGN AN ALREADY SIGNED FORM");

    try
    {
        Bureaucrat alice("Alice", 10);
        Bureaucrat bob("Bob", 20);
        Form form(30, 20);
		separateLine();
		std::cout << std::endl;

        alice.signForm(form);
		std::cout << std::endl;
        std::cout << "First signing complete." << std::endl;
        std::cout << "Trying to sign the same form again..." << std::endl;

		std::cout << std::endl;
        bob.signForm(form);

		std::cout << std::endl;
		separateLine();
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

/*
 * Enable this test after your operator<< implementation matches:
 *
 * std::ostream &operator<<(std::ostream &out, const Form &form);
 */
static void testInsertionOperator(void)
{
    printTitle("TEST 8: INSERTION OPERATOR");

    try
    {
        Bureaucrat alice("Alice", 10);
        Form form(30, 20);
		separateLine();
		std::cout << std::endl;

        std::cout << alice << std::endl;
        std::cout << form << std::endl;
		std::cout << std::endl;

        alice.signForm(form);
		std::cout << std::endl;

        std::cout << form << std::endl;

		std::cout << std::endl;
		separateLine();
    }
    catch (const std::exception &e)
    {
        std::cout << RED << "Unexpected exception: "
                  << e.what() << RESET << std::endl;
    }
}

int main(void)
{
    std::cout << NEON_GREEN;
    std::cout << "CPP05 EX01 - FORM TESTS";
    std::cout << RESET << std::endl;

    testFormCreation();
    testSuccessfulSign();
    testFailedSign();
    testExactRequiredGrade();
    testFormGradeTooHigh();
    testFormGradeTooLow();
    testAlreadySignedForm();
    testInsertionOperator();

    printTitle("ALL TESTS FINISHED");

    return (0);
}
