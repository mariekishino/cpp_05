#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm constructor"
		      << this->_target
			  << " called"
			  << std::endl;			
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other.getTarget())
{
	std::cout << "RobotomyRequestFrom copy constructor "
			  << other.getName()
			  << " called"
			  << std::endl;	
}
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor "
			  << this->_target
			  << " called"
			  << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout <<  "start assignation RobotomyRequestForm to other"
			  << std::endl;
	if (this == &other)
		return (*this);
	
	AForm::operator=(other);
	return (*this);
}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void RobotomyRequestForm::execute(const Bureaucrat &bureaucrat) const
{
	if (bureaucrat.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException();
	else if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	
	std::cout << "* drilling noises *" << std::endl;

	static bool seeded = false;

	if (!seeded)
	{
		std::srand(std::time(NULL));
		seeded = true;
	}
	if (std::rand() % 2 == 0)
	{
		std::cout << this->_target
				  << " has been robotomized successfully."
				  << std::endl;
	}
	else
	{
		std::cout << "Robotomy of "
				  << this->_target
				  << " failed."
				  << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm *src)
{
	std::string isSigned = src->getIsSigned() ? " is signed" : " isn't signed";

	out << src->getName() << isSigned;
	out << ". Sign-grade: " << src->getGradeToSign();
	out << ", execution-grade " << src->getGradeToExec() << std::endl;

	return(out);
}