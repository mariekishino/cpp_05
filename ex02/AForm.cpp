#include "AForm.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExec(150)
{
	std::cout << "AForm constructor" << this->_name << " called" << std::endl;
}

AForm::AForm(AForm const &other) : _name(other.getName()), _isSigned(false), _gradeToSign(other.getGradeToSign()), _gradeToExec(other.getGradeToExec())
{
	std::cout << "AForm copy of " << other.getName() << " called" << std::endl;
}
AForm::AForm(int gradeToSign, int gradeToExec) : _name("default"), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	std::cout << "AForm constructor default with sign-grade of ( " << gradeToSign << " ) and exec-grade of ( " << gradeToExec << " ) called" << std::endl;
	this->_checkGrade(gradeToSign, gradeToExec);
}

AForm::AForm(std::string const &name) : _name(name), _isSigned(false), _gradeToSign(150), _gradeToExec(150)
{
	std::cout << "AForm constructor " << this->_name << " created" << std::endl;
}

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExec) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	std::cout << "AForm constructor " 
	<< this->_name 
	<< "with sign "
	<< gradeToSign
	<< " and exec "
	<< gradeToExec 
	<< " called"
	<< std::endl;
	this->_checkGrade(gradeToSign, gradeToExec);
}



AForm::~AForm()
{
	std::cout << "AFrom destructor " << this->_name << " called" << std::endl;
}
AForm &AForm::operator=(AForm const &other)
{
	std::cout << "start assignation AFrom to other" << std::endl;
	if (this == &other)
		return (*this);
	return (*this);
}

std::string const AForm::getName() const
{
	return (this->_name);
}

bool AForm::getIsSigned() const
{
	return (this->_isSigned);
}

int AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int AForm::getGradeToExec() const
{
	return (this->_gradeToExec);
}


void AForm::_checkGrade(int gradeToSign, int gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw AForm::GradeTooLowException();
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

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw AForm::GradeTooLowException();

    _isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return("Form needs to be signed before execution");
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

std::ostream &operator<<(std::ostream &out, const AForm &form)
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
