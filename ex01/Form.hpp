#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool			  _isSigned;
		const int		  _gradeToSign;
		const int		  _gradeToExec;

		void _checkGrade(int gradeToSign, int gradeToExec);
	
	public:
		Form();
		Form(const Form &other);
		Form(int gradeToSign, int gradeToExec);
		Form(std::string const &name);
		Form(const std::string &name, int gradeToGrade, int gradeToExec);
		~Form();

		Form &operator=(Form const &other);

		const std::string getName() const;
		bool 			  getIsSigned() const;
		int				  getGradeToSign() const;
		int 			  getGradeToExec() const;

		void beSigned(Bureaucrat &Bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};

std::ostream &operator<<(std::ostream &out, const Form &other);


#endif