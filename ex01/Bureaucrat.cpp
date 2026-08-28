#include "Bureaucrat.hpp"

#define RESET "\033[0m"
#define DARK_GREEN "\033[38;5;22m"
#define NEON_GREEN "\033[1;92m"
#define RED "\033[1;91m"
#define YELLOW "\033[1;93m"


/* Constructors */

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	std::cout << "Bureaucrat constructor default called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name) : _name(name), _grade(150)
{
	std::cout << "Bereucrat constructor " << this->_name << "called" << std::endl;
}

Bureaucrat::Bureaucrat(int grade) : _name("default")
{
	std::cout << "Bureaucrat constructor default with grade ( " << grade << " ) called" << std::endl;
	this->_setGrade(grade);
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name)
{
	std::cout << "Bureaucrat constructor " << this->_name << " with grade ( " << grade << " ) called" << std::endl;
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
	std::cout << "Bureaucrat destructor " << this->_name << " called" << std::endl;
}

std::string const Bureaucrat::getName() const
{
	return(this->_name);
}

int Bureaucrat::getGrade() const
{
	return(this->_grade);
}

void Bureaucrat::_setGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

void Bureaucrat::incrementGrade()
{
	this->_setGrade(this->_grade - 1);
}

void Bureaucrat::decrementGrade()
{
	this->_setGrade(this->_grade + 1);
}

// void Bureaucrat::signForm(Form &form)
// {
// 	form.beSigned(*this);
// }

void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed "
                  << form.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << RED
				  << _name << " couldn't sign "
                  << form.getName()
                  << " because "
                  << e.what() 
				  << RESET << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

// 参照で受け取るのが自然
std::ostream &operator<<(std::ostream &out, const Bureaucrat &other)
{
	out << other.getName() 
		<< ", bureaucrat grade " 
		<< other.getGrade() 
		<< ".";

	return (out);
}
