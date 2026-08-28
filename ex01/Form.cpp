#include "Form.hpp"

Form::Form() : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExec(150)
{
	std::cout << "Form constructor" << this->_name << " called" << std::endl;
}

Form::Form(Form const &other) : _name(other.getName()), _isSigned(false), _gradeToSign(other.getGradeToSign()), _gradeToExec(other.getGradeToExec())
{
	std::cout << "Form copy of " << other.getName() << " created" << std::endl;
}
Form::Form(int gradeToSign, int gradeToExec) : _name("default"), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	std::cout << "Form constructor default with sign-grade of ( " << gradeToSign << " ) and exec-grade of ( " << gradeToExec << " ) called" << std::endl;
	this->_checkGrade(gradeToSign, gradeToExec);
}

Form::Form(std::string const &name) : _name(name), _isSigned(false), _gradeToSign(150), _gradeToExec(150)
{
	std::cout << "Form constructor " << this->_name << " created" << std::endl;

}

Form::Form(std::string const &name, int gradeToSign, int gradeToExec) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	std::cout << "Form constructor " 
	          << this->_name 
			  << " with sign-grade " 
			  << gradeToSign 
			  << " and exec-grade "
			  << gradeToExec
			  << " created" << std::endl; 
	this->_checkGrade(gradeToSign, gradeToExec);

}


Form::~Form()
{
	std::cout << "From destructor" << this->_name << " called" << std::endl;
}
Form &Form::operator=(Form const &other)
{
	std::cout << "start assignation Form to other" << std::endl;
	if (this == &other)
		return (*this);
	return (*this);
}

std::string const Form::getName() const
{
	return (this->_name);
}

bool Form::getIsSigned() const
{
	return (this->_isSigned);
}

int Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int Form::getGradeToExec() const
{
	return (this->_gradeToExec);
}


void Form::_checkGrade(int gradeToSign, int gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw Form::GradeTooLowException();
}
// void Form::beSigned(Bureaucrat &Bureaucrat)
// {
// 	if ((int)Bureaucrat.getGrade() > this->_gradeToSign)
// 		throw Form::GradeTooLowException();
// 	else if (!this->_isSigned)
// 	{
// 		std::cout << "\t" << Bureaucrat.getName() << " signed " << this->getName() << std::endl;
// 		this->_isSigned = true;
// 	}
// 	else
// 		std::cout << "\t" << Bureaucrat.getName() << "couldn't sign " << this->getName() << " since it's already signed" << std::endl;
// }

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw Form::GradeTooLowException();

    _isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}
// std::ostream &operator<<(std::ostream &out, Form *form)
// {
// 	std::string isSigned = form->getIsSigned() ? "is signed" : "isn't signed";
// 	out << form->getName() << " Form " << isSigned;
// 	out << ". Sign-grade: " << form->getGradeToSign();
// 	out << ", Exec-grade: " << form->getGradeToExec();
// 	out << std::endl;
// 	return (out);
// }

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    std::string isSigned;

    if (form.getIsSigned())
        isSigned = "is signed";
    else
        isSigned = "isn't signed";

    out << form.getName() << " Form " << isSigned;
    out << ". Sign-grade: " << form.getGradeToSign();
    out << ", Exec-grade: " << form.getGradeToExec();

    return (out);
}