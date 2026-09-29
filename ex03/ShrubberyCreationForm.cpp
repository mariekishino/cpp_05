#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreatinForm constructor "
			  << this->_target 
			  << " called" << std::endl; 
}

ShrubberyCreationForm::ShrubberyCreationForm(
	const ShrubberyCreationForm &other)
	: AForm(other),
	 _target(other.getTarget())
{
	std::cout << "ShrubberyCreationForm copy constructor " 
			  << other.getName()
			  << " called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor " << this->_target << " called" << std::endl; 
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "start assignation ShrubberyCreationForm to other"
			  << std::endl;

	if (this != &other)
		AForm::operator=(other);
	return(*this);
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();

	if (bureaucrat.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException();

	std::string filename = this->getTarget() + "_shrubbery";
	std::ofstream outfile(filename.c_str());

	if (!outfile)
	{
		std::cerr << "Error: could not open "
				  << filename << std::endl;
		return;
	}
	
	for (int i = 0; i < 5; i++)
	{
		outfile <<
		"         v" << std::endl <<
		"        >X<" << std::endl <<
		"         A" << std::endl <<
		"        d$b" << std::endl <<
		"      .d\\$$b." << std::endl <<
		"    .d$i$$\\$$b." << std::endl <<
		"       d$$@b" << std::endl <<
		"      d\\$$$ib" << std::endl <<
		"    .d$$$\\$$$b" << std::endl <<
		"  .d$$@$$$$\\$$ib." << std::endl <<
		"      d$$i$$b" << std::endl <<
		"     d\\$$$$@$b" << std::endl <<
		"  .d$@$$\\$$$$$@b." << std::endl <<
		".d$$$$i$$$\\$$$$$$b." << std::endl <<
		"        ###" << std::endl <<
		"        ###" << std::endl <<
		"        ###" << std::endl <<
		std::endl;
	}
	outfile.close();
}
