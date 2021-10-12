#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {

	//naming constructor
	Bureaucrat tom("Tom"); //autograde = 75
	Bureaucrat susanne("Susanne", 1);
	Bureaucrat junDev("Junior Developer", 138);

	std:: cout	<< tom << std::endl;
	std:: cout	<< susanne << std::endl;

	printMsg("\nTEST #0-----generate ShrubberyCreationForm------");
	std::string str = "home";
	ShrubberyCreationForm treeForm(str);
	std::cout << treeForm << std::endl;
	printMsg("SUCSESS!");


	printMsg("\nTEST #1-----try exec ShrubberyCreationForm------");
	try {
		treeForm.tryExec(susanne);
	} catch (ShrubberyCreationForm::FormNotSignedException &e) {
		printMsg("form " + treeForm.getName() + " is not signed! Execution stops");
	}

	printMsg("\nTEST #2-----sign and try exec again ShrubberyCreationForm------");

	try {
		treeForm.beSigned(susanne);
		treeForm.tryExec(susanne);
	}
	catch (ShrubberyCreationForm::FormNotSignedException &e) {
		printMsg("form " + treeForm.getName() + " is not signed! Execution stops");
	}

	printMsg("\nTEST #3-----try exec ShrubberyCreationForm by low Graded Junior Developer------");
	std::cout << junDev << std::endl;

	try {
		treeForm.tryExec(junDev);
	}
	catch (ShrubberyCreationForm::GradeTooLowException &e) {
		printMsg("form " + treeForm.getName() + " can't be executed by Junior Developer cause he or she hasn't appropriate rights");
	}
}
