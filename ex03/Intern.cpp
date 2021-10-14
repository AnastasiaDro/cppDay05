//
// Created by Cesar Erebus on 10/14/21.
//

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {
	form_types[0] = "Shrubbery request";
	form_types[1] = "Robotomy request";
	form_types[2] = "Pardon request";
}

Intern::~Intern() {}

Intern::Intern(const Intern &orig) {
	*this = orig;
}

Intern &Intern::operator=(const Intern &orig) {
	if (this == &orig)
		return *this;
	for (int i = 0; i < _num; i++) {
		this->form_types[i] = orig.form_types[i];
	}
	return *this;
}

Form *Intern::makeForm(std::string formName, std::string target) {
	int i = 0;
	while (i < _num && formName != form_types[i])
		i++;
	Form *nForm = nullptr;

	switch (i) {
		case 0:
			nForm = new ShrubberyCreationForm(target);
			break;
		case 1:
			nForm = new RobotomyRequestForm(target);
			break;
		case 2:
			nForm = new PresidentialPardonForm(target);
			break;
		default:
			printMsg("ERROR! Non-existent type of form!");
			return nForm;
	}
	printMsg("Intern creates " + nForm->getName());
	return nForm;
}
