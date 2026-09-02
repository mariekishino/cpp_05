#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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

static void printSignedState(const AForm &form)
{
	std::cout << form.getName()
			  << " signed: "
			  << (form.getIsSigned() ? "YES" : "NO")
			  << std::endl;
}

int main()
{
	/* ================================================================ */
	/* SHRUBBERY                                                        */
	/* ================================================================ */

	// TEST 1: 正常系
	printTitle("TEST 1: SHRUBBERY NORMAL EXECUTION");

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


	// TEST 2: 未署名のままexecute
	printTitle("TEST 2: SHRUBBERY EXECUTE UNSIGNED FORM");

	try
	{
		Bureaucrat alice("Alice", 1);
		ShrubberyCreationForm form("park");

		separateLine();

		alice.executeForm(form);

		separateLine();
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	// TEST 3: 署名grade不足
	printTitle("TEST 3: SHRUBBERY GRADE TOO LOW TO SIGN");

	try
	{
		Bureaucrat bob("Bob", 150);
		ShrubberyCreationForm form("forest");

		separateLine();

		bob.signForm(form);
		printSignedState(form);

		separateLine();
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	// TEST 4: 署名はできるがexecuteのgrade不足
	printTitle("TEST 4: SHRUBBERY GRADE TOO LOW TO EXECUTE");

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


	/* ================================================================ */
	/* ROBOTOMY                                                         */
	/* ================================================================ */

	// TEST 5: Robotomy 正常系
	printTitle("TEST 5: ROBOTOMY NORMAL EXECUTION");

	try
	{
		Bureaucrat david("David", 1);
		RobotomyRequestForm form("Bender");

		separateLine();

		std::cout << form << std::endl;

		david.signForm(form);
		david.executeForm(form);

		separateLine();
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	// TEST 6: Robotomy 未署名
	printTitle("TEST 6: ROBOTOMY UNSIGNED FORM");

	try
	{
		Bureaucrat emma("Emma", 1);
		RobotomyRequestForm form("Wall-E");

		separateLine();

		emma.executeForm(form);

		separateLine();
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	// TEST 7: Robotomy 署名grade不足
	printTitle("TEST 7: ROBOTOMY GRADE TOO LOW TO SIGN");

	try
	{
		Bureaucrat frank("Frank", 100);
		RobotomyRequestForm form("R2-D2");

		separateLine();

		frank.signForm(form);
		printSignedState(form);

		separateLine();
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	// TEST 8: Robotomy 署名できるがexecute不可
	printTitle("TEST 8: ROBOTOMY GRADE TOO LOW TO EXECUTE");

	try
	{
		Bureaucrat george("George", 60);
		RobotomyRequestForm form("C-3PO");

		separateLine();

		george.signForm(form);
		george.executeForm(form);

		separateLine();
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	// TEST 9: Robotomy 50% success / failure
	printTitle("TEST 9: ROBOTOMY RANDOM RESULT");

	try
	{
		Bureaucrat helen("Helen", 1);
		RobotomyRequestForm form("T-800");

		separateLine();

		helen.signForm(form);

		for (int i = 0; i < 10; i++)
		{
			std::cout << "Attempt " << i + 1 << ":" << std::endl;
			helen.executeForm(form);
		}

		separateLine();
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	/* ================================================================ */
	/* PRESIDENTIAL PARDON                                              */
	/* ================================================================ */

	// TEST 10: 正常系
	printTitle("TEST 10: PRESIDENTIAL PARDON NORMAL EXECUTION");

	try
	{
		Bureaucrat alice("Alice", 1);
		PresidentialPardonForm form("Arthur");

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


	// TEST 11: 未署名
	printTitle("TEST 11: PRESIDENTIAL PARDON UNSIGNED FORM");

	try
	{
		Bureaucrat bob("Bob", 1);
		PresidentialPardonForm form("Ford");

		separateLine();

		bob.executeForm(form);

		separateLine();
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	// TEST 12: 署名grade不足
	printTitle("TEST 12: PRESIDENTIAL PARDON GRADE TOO LOW TO SIGN");

	try
	{
		Bureaucrat charlie("Charlie", 30);
		PresidentialPardonForm form("Trillian");

		separateLine();

		charlie.signForm(form);
		printSignedState(form);

		separateLine();
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	// TEST 13: signはできるがexecute不可
	printTitle("TEST 13: PRESIDENTIAL PARDON GRADE TOO LOW TO EXECUTE");

	try
	{
		Bureaucrat david("David", 10);
		PresidentialPardonForm form("Marvin");

		separateLine();

		david.signForm(form);
		david.executeForm(form);

		separateLine();
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	/* ================================================================ */
	/* BOUNDARY TESTS                                                   */
	/* ================================================================ */

	// TEST 14: Shrubbery sign境界値
	// 必要grade = 145
	printTitle("TEST 14: SHRUBBERY SIGN GRADE BOUNDARY");

	try
	{
		ShrubberyCreationForm form145("boundary_145");
		ShrubberyCreationForm form146("boundary_146");

		Bureaucrat grade145("Grade145", 145);
		Bureaucrat grade146("Grade146", 146);

		separateLine();

		std::cout << "Grade 145 should be able to sign:" << std::endl;
		grade145.signForm(form145);
		printSignedState(form145);

		std::cout << std::endl;

		std::cout << "Grade 146 should NOT be able to sign:" << std::endl;
		grade146.signForm(form146);
		printSignedState(form146);

		separateLine();
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	// TEST 15: Shrubbery execute境界値
	// 必要grade = 137
	printTitle("TEST 15: SHRUBBERY EXECUTE GRADE BOUNDARY");

	try
	{
		Bureaucrat signer("Signer", 1);

		ShrubberyCreationForm form137("exec_137");
		ShrubberyCreationForm form138("exec_138");

		Bureaucrat grade137("Grade137", 137);
		Bureaucrat grade138("Grade138", 138);

		signer.signForm(form137);
		signer.signForm(form138);

		separateLine();

		std::cout << "Grade 137 should execute:" << std::endl;
		grade137.executeForm(form137);

		std::cout << std::endl;

		std::cout << "Grade 138 should NOT execute:" << std::endl;
		grade138.executeForm(form138);

		separateLine();
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	// TEST 16: Robotomy boundary
	// sign = 72, execute = 45
	printTitle("TEST 16: ROBOTOMY GRADE BOUNDARIES");

	try
	{
		RobotomyRequestForm sign72("Sign72");
		RobotomyRequestForm sign73("Sign73");

		Bureaucrat grade72("Grade72", 72);
		Bureaucrat grade73("Grade73", 73);

		separateLine();

		std::cout << "Grade 72 should sign:" << std::endl;
		grade72.signForm(sign72);
		printSignedState(sign72);

		std::cout << std::endl;

		std::cout << "Grade 73 should NOT sign:" << std::endl;
		grade73.signForm(sign73);
		printSignedState(sign73);

		std::cout << std::endl;

		RobotomyRequestForm exec45("Exec45");
		RobotomyRequestForm exec46("Exec46");

		Bureaucrat signer("Signer", 1);
		Bureaucrat grade45("Grade45", 45);
		Bureaucrat grade46("Grade46", 46);

		signer.signForm(exec45);
		signer.signForm(exec46);

		std::cout << "Grade 45 should execute:" << std::endl;
		grade45.executeForm(exec45);

		std::cout << std::endl;

		std::cout << "Grade 46 should NOT execute:" << std::endl;
		grade46.executeForm(exec46);

		separateLine();
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	// TEST 17: Presidential boundary
	// sign = 25, execute = 5
	printTitle("TEST 17: PRESIDENTIAL PARDON GRADE BOUNDARIES");

	try
	{
		PresidentialPardonForm sign25("Sign25");
		PresidentialPardonForm sign26("Sign26");

		Bureaucrat grade25("Grade25", 25);
		Bureaucrat grade26("Grade26", 26);

		separateLine();

		std::cout << "Grade 25 should sign:" << std::endl;
		grade25.signForm(sign25);
		printSignedState(sign25);

		std::cout << std::endl;

		std::cout << "Grade 26 should NOT sign:" << std::endl;
		grade26.signForm(sign26);
		printSignedState(sign26);

		std::cout << std::endl;

		PresidentialPardonForm exec5("Exec5");
		PresidentialPardonForm exec6("Exec6");

		Bureaucrat signer("Signer", 1);
		Bureaucrat grade5("Grade5", 5);
		Bureaucrat grade6("Grade6", 6);

		signer.signForm(exec5);
		signer.signForm(exec6);

		std::cout << "Grade 5 should execute:" << std::endl;
		grade5.executeForm(exec5);

		std::cout << std::endl;

		std::cout << "Grade 6 should NOT execute:" << std::endl;
		grade6.executeForm(exec6);

		separateLine();
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	/* ================================================================ */
	/* COPY / ASSIGNMENT                                                */
	/* ================================================================ */

	// TEST 18: Copy constructor
	printTitle("TEST 18: COPY CONSTRUCTOR");

	try
	{
		Bureaucrat alice("Alice", 1);

		ShrubberyCreationForm original("original");

		alice.signForm(original);

		separateLine();

		std::cout << "Before copy:" << std::endl;
		std::cout << "Original target: "
				  << original.getTarget() << std::endl;
		printSignedState(original);

		std::cout << std::endl;

		ShrubberyCreationForm copy(original);

		std::cout << "After copy:" << std::endl;
		std::cout << "Copy target: "
				  << copy.getTarget() << std::endl;
		printSignedState(copy);

		separateLine();
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	// TEST 19: Assignment operator
	printTitle("TEST 19: ASSIGNMENT OPERATOR");

	try
	{
		Bureaucrat alice("Alice", 1);

		ShrubberyCreationForm first("first");
		ShrubberyCreationForm second("second");

		alice.signForm(first);

		separateLine();

		std::cout << "Before assignment:" << std::endl;

		std::cout << "first target: "
				  << first.getTarget() << std::endl;
		printSignedState(first);

		std::cout << "second target: "
				  << second.getTarget() << std::endl;
		printSignedState(second);

		std::cout << std::endl;

		second = first;

		std::cout << "After second = first:" << std::endl;

		std::cout << "first target: "
				  << first.getTarget() << std::endl;
		printSignedState(first);

		std::cout << "second target: "
				  << second.getTarget() << std::endl;
		printSignedState(second);

		separateLine();
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	/* ================================================================ */
	/* POLYMORPHISM                                                     */
	/* ================================================================ */

	// TEST 20:
	// 3種類ともAForm*として扱えるか確認
	printTitle("TEST 20: POLYMORPHISM THROUGH AFORM POINTER");

	try
	{
		Bureaucrat boss("Boss", 1);

		AForm *forms[3];

		forms[0] = new ShrubberyCreationForm("polymorphic_garden");
		forms[1] = new RobotomyRequestForm("PolymorphicRobot");
		forms[2] = new PresidentialPardonForm("PolymorphicCitizen");

		separateLine();

		for (int i = 0; i < 3; i++)
		{
			std::cout << std::endl;
			std::cout << "Form " << i + 1 << ": "
					  << forms[i]->getName()
					  << std::endl;

			boss.signForm(*forms[i]);
			boss.executeForm(*forms[i]);
		}

		separateLine();

		std::cout << "Deleting through AForm pointers..."
				  << std::endl;

		for (int i = 0; i < 3; i++)
			delete forms[i];

		separateLine();
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return (0);
}