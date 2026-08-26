#include "Bureaucrat.hpp"
#include <iostream>

#define GREEN "\033[38;5;22m"
#define RED "\033[31m"
#define BOLD "\033[1m"
#define RESET "\033[0m"


static void printTitle(const std::string &title)
{
	std::cout << std::endl;
	std::cout << BOLD << GREEN
			  << "======= " << title << " ======="
			  << RESET << std::endl;
	std::cout << std::endl;
}
static void partationLine()
{
	std::cout << GREEN
			  << "----------------------------------------------------------"
			  << RESET << std::endl;
}

int main()
{
	// normal bureaucrat
	printTitle("1. BASIC TEST");

	try
	{
		Bureaucrat basic("Hanako", 42);
		partationLine();

		std::cout << basic << std::endl;

		std::cout << "Name  : " << basic.getName() << std::endl;
		std::cout << "Grade : " << basic.getGrade() << std::endl;
		partationLine();
	}
	catch(const std::exception& e)
	{
		std::cout << RED
				  << "Exception : " 
				  << e.what() 
				  << RESET << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;

	// check if incrementGrade() is correct
	printTitle("2. INCREMENT GRADE TEST");
	
	try
	{
		Bureaucrat top("Taro", 3);
		partationLine();
		std::cout << "Before : " << top << std::endl;
		top.incrementGrade();
		std::cout << "After  : " << top << std::endl;
		partationLine();
	}
	catch(const std::exception &e)
	{
		std::cout << RED
				  << "Exception : " 
				  << e.what() 
				  << RESET << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;

	// checking decrementGrade()
	printTitle("3. DECREMENT GRADE TEST");

	try
	{
		Bureaucrat bottom("Ichiro", 3);
		partationLine();
		std::cout << "Before : " << bottom << std::endl;
		bottom.decrementGrade();
		std::cout << "After  : " << bottom << std::endl;
		partationLine();
	}
	catch (const std::exception &e)
	{
		std::cout << RED
				  << "Exception : " 
				  << e.what() 
				  << RESET << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;

	printTitle("4. INVALID TOO HIGH TEST");
	try
	{
		Bureaucrat high("hanako", 0);
		partationLine();
		std::cout << high << std::endl;
		partationLine();
	}
	catch(const Bureaucrat::GradeTooHighException &e)
	{
		partationLine();
		std::cout << RED
				  << "Caught GradeTooHighException: "
				  << e.what()
				  << RESET << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;

	// instatize with grade 0 -> catch is called
	printTitle("5. INVALID TOO LOW TEST");
	try
	{
		Bureaucrat low("Taro", 151);
		partationLine();
		std::cout << low << std::endl;
		partationLine();
	}
	catch(const Bureaucrat::GradeTooLowException &e)
	{
		partationLine();
		std::cout << RED
		          << "Caught GradeTooLowException : "
				  << e.what()
				  << RESET << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;


	printTitle("6. EXCEPTION TEST - INCREMENT");
	try
	{
		Bureaucrat top("Hanako", 1);

		partationLine();
		std::cout << "Before : " << top << std::endl;

		top.incrementGrade();

		std::cout << "After  : " << top << std::endl;
	}
	catch(const Bureaucrat::GradeTooHighException &e)
	{
		std::cout << std::endl;
		std::cout << RED
				  << "Caught GradeTooHigh Exception : "
		   		  << e.what() 
				  << RESET << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;


	printTitle("7. EXCEPTION TEST - DECREMENT");
	try
	{
		Bureaucrat bottom("Taro", 150);
		partationLine();

		std::cout << "Before : " << bottom << std::endl;
		bottom.decrementGrade();

		std::cout << "After  : " << bottom << std::endl;
		partationLine();
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cout << std::endl;
		std::cout << RED
				  << "Caught GradeTooLowException : "
				  << e.what()
				  << RESET << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;

	printTitle("8. STD::EXCEPTION TEST pt.1");
	
	try
	{
		Bureaucrat error("Error", 0);
		partationLine();
		std::cout << error << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED
				  << "Caught as std::exception : "
			      << e.what()
				  << RESET << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;


	printTitle("9. STD::EXCEPTION TEST pt.2");
	try
	{
		Bureaucrat error("Error", 151);
		partationLine();
		std::cout << error << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED
				  << "Caught as std::exception : "
			      << e.what()
				  << RESET << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	// copy constructor
	printTitle("10. COPY TEST");

	try
	{
		Bureaucrat original("Taro", 50);
		Bureaucrat copy(original);
		partationLine();

		std::cout << "<< BEFORE >>" << std::endl;
		std::cout << "Original : " << original << std::endl;
		std::cout << "Copy     : " << copy << std::endl;

		copy.incrementGrade();

		std::cout << std::endl;
		std::cout << "<< AFTER >> " << std::endl;
		std::cout << "Original : " << original << std::endl;
		std::cout << "Copy	   : " << copy << std::endl;
		partationLine();
	}
	catch(const std::exception& e)
	{
		std::cout << RED 
				  << "0Exception: "
				  << e.what() 
				  << RESET << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;

	printTitle("11. ASSIGNMENT OPERATOR TEST");

	try
	{
		Bureaucrat original("Taro", 50);
		Bureaucrat assigned("Hanako", 100);
		partationLine();

		std::cout << "Before   : " << std::endl;
		std::cout << "Original : " << original << std::endl;
		std::cout << "Assigned : " << assigned << std::endl;

		assigned = original;

		std::cout << std::endl;
		std::cout << "After assignment : " << std::endl;
		std::cout << "Origina0l : " << original << std::endl;
		std::cout << "Assigned : " << assigned << std::endl;
		partationLine();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << std::endl;

	printTitle("12. DEFAULT CONSTRUCTOR TEST");

	try
	{	
    	Bureaucrat basic;

    	partationLine();

    	std::cout << basic << std::endl;
    	std::cout << "Name  : " << basic.getName() << std::endl;
    	std::cout << "Grade : " << basic.getGrade() << std::endl;

    	partationLine();
	}
	catch (const std::exception &e)
	{
    	std::cout << RED
              	<< "Exception : "
              	<< e.what()
              	<< RESET << std::endl;
	}

	return 0;
	
}