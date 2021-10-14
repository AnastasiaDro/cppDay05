//
// Created by Cesar Erebus on 10/12/21.
//

#include <iostream>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string &target) : Form("RobotomyRequestForm", 72, 45),
																	_target(target){}

const std::string &RobotomyRequestForm::getTarget(){
	return this->_target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &orig) : Form(orig.getName(), orig._signGrade, orig.getExecGrade())
{
	*this = orig;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &orig) {
	if (this == &orig)
		return *this;
	this->_target = orig._target;
	return *this;
}

void RobotomyRequestForm::exec(const Bureaucrat &executor) const {
	printMsg("* Some drilling noises * " + this->_target + " has been robotomized successfully 50% of the time by " + executor.getName());
}

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm scf)
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