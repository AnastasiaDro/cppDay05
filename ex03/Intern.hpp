//
// Created by Cesar Erebus on 10/14/21.
//

#ifndef DAY05_INTERN_HPP
#define DAY05_INTERN_HPP
#include "Form.hpp"

class Intern {
private:
	static const int _num = 3;
	std::string form_types[_num];

public:
	Intern();
	~Intern();
	Intern(const Intern &orig);
	//
	//ShrubberyCreationForm &operator=(const ShrubberyCreationForm &orig);
	Intern &operator = (const Intern &orig);

	Form *makeForm(std::string formName, std::string target);
};


#endif //DAY05_INTERN_HPP
