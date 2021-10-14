//
// Created by Cesar Erebus on 10/12/21.
//

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form {
private:
	//empty constructor
	RobotomyRequestForm();
	std::string	_target;
public:
//subject constructor
	RobotomyRequestForm(std::string &target);
//copy constructor
	RobotomyRequestForm(const RobotomyRequestForm &orig);
//detructor
	virtual ~RobotomyRequestForm();
//operator = overloading
	RobotomyRequestForm &operator=(const RobotomyRequestForm &orig);

	const std::string &getTarget();

//execute
	virtual void exec(Bureaucrat const & executor) const;

};

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm scf);

#endif