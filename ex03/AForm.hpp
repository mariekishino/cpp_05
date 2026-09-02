#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool			  _isSigned;
		const int		  _gradeToSign;
		const int		  _gradeToExec;

		void _checkGrade(int gradeToSign, int gradeToExec);
	
	public:
		AForm();
		AForm(const AForm &other);
		AForm(int gradeToSign, int gradeToExec);
		AForm(std::string const &name);
		AForm(const std::string &name, int gradeToSign, int gradeToExec);
		virtual ~AForm();

		AForm &operator=(AForm const &other);

		const std::string getName() const;
		bool 			  getIsSigned() const;
		int				  getGradeToSign() const;
		int 			  getGradeToExec() const;

		void beSigned(Bureaucrat &Bureaucrat);
		virtual void execute(Bureaucrat const &bureaucrat) const = 0;

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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &other);

#endif
