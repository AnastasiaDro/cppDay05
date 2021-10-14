//
// Created by Cesar Erebus on 10/12/21.
//

#include <iostream>
#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string &target) : Form("PresidentialPardonForm", 25, 5),
																_target(target){}

const std::string &PresidentialPardonForm::getTarget(){
	return this->_target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &orig) : Form(orig.getName(), orig._signGrade, orig.getExecGrade())
{
	*this = orig;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &orig) {
	if (this == &orig)
		return *this;
	this->_target = orig._target;
	return *this;
}

void PresidentialPardonForm::exec(const Bureaucrat &executor) const {
	printMsg(executor.getName() + " organized " + this->_target + " has been pardoned by Zafod Beeblebrox");
}

std::ostream &operator<<(std::ostream &out, PresidentialPardonForm scf)
{
	std::cout	<< scf.getName()
				 << ", form sign grade "
				 << scf.getSignGrade()
				 << ", exec grade "
				 << scf.getExecGrade()
				 << ", target "
				 << scf.getTarget();
	return out;
}