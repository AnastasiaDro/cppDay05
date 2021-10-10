//
// Created by  Anastasia on 10.10.2021.
//

#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string &name) : _name(name), _grade(75){}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) {}
//copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &orig) { *this = orig; }
//destructor
Bureaucrat::~Bureaucrat() {}

//assignment operator
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &orig)
{
	if (this == &orig)
		return *this;
	this->_grade = orig.getGrade();
	return *this;
}


const std::string &Bureaucrat::getName() const {
	return _name;
}

void Bureaucrat::incGrade(int n) {

	std::cout << this->_name << " trying to increment the grade to " << this->_grade - n << std::endl;
	if (this->_grade - n < min)
		throw Bureaucrat::GradeTooHighException("Grade too high! The highest grade is 1");
	this->_grade -= n;
}

void Bureaucrat::decrGrade(int n) {
	std::cout << this->_name << " trying to decrement the grade to " << this->_grade + n << std::endl;
	if (this->_grade + n > max)
		throw Bureaucrat::GradeTooLowException("Grade too high! The highest grade is 1");
	this->_grade += n;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::setGrade(int grade) {
	if (grade < min)
		throw Bureaucrat::GradeTooHighException("Grade too high! The highest grade is 1");
	if (grade > max)
		throw Bureaucrat::GradeTooLowException("Grade too low! The lowest grade is 150");
	_grade = grade;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &err) : logic_error(err)
{
	printMsg("EXCEPTION CAUGHT!!! GradeTooHighException");
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &err) : logic_error(err)
{
	printMsg("EXCEPTION CAUGHT!!! GradeTooLowException");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
	std::cout	<< b.getName()
				<< ", bureaucrat grade "
				<< b.getGrade();
	return out;
}

void	printMsg(std::string const &msg)
{
	std::cout << msg << std::endl;
}