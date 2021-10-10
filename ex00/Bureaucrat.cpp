//
// Created by  Anastasia on 10.10.2021.
//

#include <iostream>
#include "Bureaucrat.hpp"

const std::string &Bureaucrat::getName() const {
	return _name;
}

void Bureaucrat::incGrade(int n) {
	this->_grade -= n;
}

void Bureaucrat::decrGrade(int n) {
	this->_grade += n;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &orig) {
	if (this == &orig)
		return *this;
	this->_grade = orig.getGrade();
	return *this;
}

Bureaucrat::Bureaucrat(const std::string &name) : _name(name) {}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
	std::cout	<< b.getName()
				<< ", bureaucrat grade "
				<< b.getGrade()
					<< std::endl;
	return out;
}

void	printMsg(std::string const &msg)
{
	std::cout << msg << std::endl;
}