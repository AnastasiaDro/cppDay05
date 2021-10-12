//
// Created by Cesar Erebus on 10/12/21.
//

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP


#include "Form.hpp"

class ShrubberyCreationForm : public virtual Form {
private:
//empty constructor
	ShrubberyCreationForm();
	std::string	_target;
public:
//subject constructor
	ShrubberyCreationForm(std::string	&target);
//copy constructor
	ShrubberyCreationForm(const ShrubberyCreationForm &orig);
//detructor
	virtual ~ShrubberyCreationForm();
//operator = overloading
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &orig);

	const std::string &getTarget();
};

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm scf);

#endif //DAY05_SHRUBBERYCREATIONFORM_HPP
