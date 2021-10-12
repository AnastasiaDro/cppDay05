//
// Created by  Anastasia on 10.10.2021.
//

#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() :	_name("Default"),
				_signGrade(1),
				_execGrade(150),
				_isSigned(false) {}

Form::Form(const std::string& name, int signGrade, int execGrade) :	_name(name),
																_signGrade(signGrade),
																_execGrade(execGrade)
{
	if (signGrade < min)
		throw Form::GradeTooHighException("Invalid SIGN grade: GradeTooHigh");
	if (signGrade > max)
		throw Form::GradeTooLowException("Invalid SIGN grade: GradeTooLow");
	if (execGrade < min)
		throw Form::GradeTooHighException("Invalid EXEC grade: GradeTooHigh");
	if (execGrade > max)
		throw Form::GradeTooLowException("Invalid EXEC grade: GradeTooLow");
	_isSigned = false;
}

Form::Form(const Form &orig) :	_name(orig._name),
								_signGrade(orig._signGrade),
								_execGrade(orig._execGrade)
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
	if (this->_isSigned)
	{
		printMsg("ATTENTION! Form is already signed!");
		return;
	}
	if (b.getGrade() > this->_signGrade)
	{
		printMsg("SIGNING: " + b.getName() + "  cannot sign " + this->getName() + " because of low grade");
		throw Form::GradeTooLowException("GradeToLowException");
	}
	else
	{
		this->_isSigned = true;
		std::cout << "SIGNING: " << b << " signs " << *this << std::endl;
	}
}

void Form::execute(const Bureaucrat &executor) const {

}

void Form::tryExec(const Bureaucrat &executor) {
	if (!this->isSigned())
	{
		printMsg("Failure!");
		throw FormNotSignedException("FormNotSignedException");
	}
	if (!this->isExecGrade(executor))
	{
		printMsg("Failure!");
		throw GradeTooLowException("GradeToLowException");
	}
	printMsg(executor.getName() + " executing " + this->getName());
	execute(executor);
}

bool Form::isExecGrade(const Bureaucrat &executor) const {
	if (executor.getGrade() > this->_execGrade)
		return false;
	else
		return true;
}

Form::GradeTooHighException::GradeTooHighException(const std::string &err) : logic_error(err)
{
	printMsg("CAUGHT " + err);
}

Form::GradeTooLowException::GradeTooLowException(const std::string &err) : logic_error(err)
{
	printMsg("CAUGHT " + err);
}

Form::FormNotSignedException::FormNotSignedException(const std::string &err) : logic_error(err)
{
	printMsg("CAUGHT " + err);
}

std::ostream &operator<<(std::ostream &out, const Form &b)
{
	std::cout	<< b.getName()
				 << ", form sign grade "
				 << b.getSignGrade();
	return out;
}
