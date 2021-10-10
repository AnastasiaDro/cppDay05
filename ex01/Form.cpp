//
// Created by  Anastasia on 10.10.2021.
//

#include <iostream>
#include "Form.hpp"

Form::Form() : _name("Default"), _signGrade(1), _execGrade(150) {}

Form::Form(const Form &orig) : _name(orig._name), _signGrade(orig._signGrade), _execGrade(orig._execGrade)
{
	*this = orig;
}

Form::~Form() {}

Form &Form::operator=(const Form &orig) {
	if (this == &orig)
		return *this;
	this->_isSigned = orig._isSigned;
	return *this;
}

const std::string &Form::getName() const {
	return _name;
}

int Form::getSignGrade() const {
	return _signGrade;
}

int Form::getExecGrade() const {
	return _execGrade;
}

bool Form::isSigned() const {
	return _isSigned;
}

void Form::setIsSigned(bool isSigned) {
	_isSigned = isSigned;
}

void Form::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException("SIGNING: " + b.getName() + "  cannot sign  " + this->getName() + " because of low grade");
	else
		printMsg(b.getName() + " signs " + this->getName());
}

Form::GradeTooHighException::GradeTooHighException(const std::string &err) : logic_error(err)
{
	printMsg("FORM___EXCEPTION CAUGHT!!! GradeTooHighException");
}

Form::GradeTooLowException::GradeTooLowException(const std::string &err) : logic_error(err)
{
	printMsg("FORM___EXCEPTION CAUGHT!!! GradeTooLowException");
}


std::ostream &operator<<(std::ostream &out, const Form &b)
{
	std::cout	<< b.getName()
				 << ", form sign grade "
				 << b.getSignGrade();
	return out;
}

void	printMsg(std::string const &msg)
{
	std::cout << msg << std::endl;
}