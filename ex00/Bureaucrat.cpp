#include "Bureaucrat.hpp"

/* Constructors */

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	std::cout << "default Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name) : _name(name), _grade(150)
{
	std::cout << "Bereucrat constructor" << this->_name << "called" << std::endl;
}

Bureaucrat::Bureaucrat(int grade) : _name("default")
{
	std::cout << "Bureaucrat default constructor with grade( " << grade << " ) called" << std::endl;
	this->_setGrade(grade);
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name)
{
	std::cout << "Bureaucrat" << this->_name << "constructor with grade(" << grade << " ) called" << std::endl;
	this->_setGrade(grade);
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name)
{
	std::cout << "Bureaucrat copy constructor" << other.getName() << "called" << std::endl;
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	std::cout << "start assignation Bureaucrat to other " << std::endl;
	if (this == &other)
		return (*this);
	this->_grade = other.getGrade();
	return (*this);
}


/* Destructor */
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor" << this->_name << "called" << std::endl;
}