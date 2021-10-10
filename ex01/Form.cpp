//
// Created by  Anastasia on 10.10.2021.
//

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
