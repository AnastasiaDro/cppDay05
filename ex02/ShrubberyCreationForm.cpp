//
// Created by Cesar Erebus on 10/12/21.
//

#include <iostream>
#include "ShrubberyCreationForm.hpp"




ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string &target) : Form("ShrubberyCreationForm", 145, 137),
																		_target(target){}

const std::string &ShrubberyCreationForm::getTarget(){
	return this->_target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &orig) : Form(orig.getName(), orig._signGrade, orig.getExecGrade())
{
	*this = orig;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &orig) {
	if (this == &orig)
		return *this;
	this->_target = orig._target;
	return *this;
}

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm scf)
{
	std::cout	<< scf.getName()
				<< ", form sign grade "
				<< scf.getSignGrade()
				<< ", exec grade "
				<< scf.getExecGrade()
				<< ", target "
				<< scf.getTarget()
				<< std::endl;
	return out;
}



