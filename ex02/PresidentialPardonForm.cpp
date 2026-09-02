#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm constructor "
			  << this->_target
			  << " called"
			  << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), _target(other.getTarget())
{
	std::cout << "PresidentialPardonForm copy constructor "
			  << other.getName()
			  << " called"
			  << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor "
		      << this->_target
			  << " called"
			  << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << "start assignation PresidentialPardonForm to other"
			  << std::endl;
	
	if (this == &other)
		return (*this);
	AForm::operator=(other);

	return (*this);
}


std::string PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) const
{
	if (bureaucrat.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException();
	
	else if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	
	std::cout << this->_target
			  << " has been pardoned by Zephod Beeblebrox."
			  << std::endl;
}

std::ostream &operator<<(std::ostream &out, PresidentialPardonForm *src)
{
	std::string isSigned =
		src->getIsSigned() ? " is signed" : " isn't signed";
	
	out << src->getName() << isSigned;
	out << " . Sign-grade: " << src->getGradeToSign();
	out << ", execution-grade " << src->getGradeToExec()
		<< std::endl;
	
	return (out);
}


