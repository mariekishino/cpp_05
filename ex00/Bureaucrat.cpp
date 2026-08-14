#include "Bureaucrat.hpp"

/* Constructors */

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::out << "default Bureaucrat created" << std::endl;
}


Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(src._name), _grade(src._grade)
{
	std::cout << "create Bureaucrate copy of" << other.getName() << std::endl;
	_validateGrade(this->_grade);
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	_validateGrade(this->_grade);
}


/* Destructor */
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat" << this->_name << "destroyed" << std::endl;
}