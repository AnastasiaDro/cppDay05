//
// Created by Cesar Erebus on 10/12/21.
//

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form {
private:
	//empty constructor
	PresidentialPardonForm();
	std::string	_target;
public:
//subject constructor
	PresidentialPardonForm(std::string &target);
//copy constructor
	PresidentialPardonForm(const PresidentialPardonForm &orig);
//detructor
	virtual ~PresidentialPardonForm();
//operator = overloading
	PresidentialPardonForm &operator=(const PresidentialPardonForm &orig);

	const std::string &getTarget();

//execute
	virtual void execute(Bureaucrat const & executor) const;

};

std::ostream &operator<<(std::ostream &out, PresidentialPardonForm scf);

#endif

