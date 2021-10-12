#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {

	//naming constructor
	Bureaucrat tom("Tom"); //autograde = 75
	Bureaucrat susanne("Susanne", 1);
	Bureaucrat junDev("Junior Developer", 138);
	Bureaucrat senDev("Senior Developer", 45);
	Bureaucrat androDev("AndroDev", 3);

	std:: cout	<< tom << std::endl;
	std:: cout	<< susanne << std::endl;

	printMsg("TESTS ShrubberyCreationForm");
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

//------------------------------//
//NEXT FORM: RobotomyRequestForm//
//------------------------------//


	printMsg("\n\nTESTS RobotomyRequestForm");
	printMsg("\nTEST #0-----generate RobotomyRequestForm------");
	std::string str1 = "SEO";
	RobotomyRequestForm roboForm(str1);
	std::cout << roboForm << std::endl;
	printMsg("SUCSESS!");


	printMsg("\nTEST #1-----try exec RobotomyRequestForm------");
	try {
		roboForm.tryExec(tom);
	} catch (RobotomyRequestForm::FormNotSignedException &e) {
		printMsg("form " + roboForm.getName() + " is not signed! Execution stops");
	}

	printMsg("\nTEST #2-----sign and try exec again RobotomyRequestForm------");

	try {
		roboForm.beSigned(susanne);
		roboForm.tryExec(tom);
	}
	catch (RobotomyRequestForm::FormNotSignedException &e) {
		printMsg("form " + roboForm.getName() + " is not signed! Execution stops");
	}
	catch (RobotomyRequestForm::GradeTooLowException &e) {
		printMsg("form " + roboForm.getName() + " can't be executed by Junior Developer cause he or she hasn't appropriate rights");
	}

	printMsg("\nTEST #3-----try exec RobotomyRequestForm by middle Graded Senior Developer------");
	std::cout << senDev << std::endl;

	try {
		roboForm.tryExec(senDev);
	}
	catch (RobotomyRequestForm::GradeTooLowException &e) {
		printMsg("form " + roboForm.getName() + " can't be executed by Senior Developer cause he or she hasn't appropriate rights");
	}




//------------------------------//
//NEXT FORM: PresidentalPardonForm//
//------------------------------//


	printMsg("\n\nTESTS PresidentialPardonForm");
	printMsg("\nTEST #0-----generate PresidentialPardonForm------");
	std::string str2 = "JunDev";
	PresidentialPardonForm pardonForm(str2);
	std::cout << pardonForm << std::endl;
	printMsg("SUCSESS!");


	printMsg("\nTEST #1-----try exec PresidentialPardonForm------");
	try {
		pardonForm.tryExec(tom);
	} catch (PresidentialPardonForm::FormNotSignedException &e) {
		printMsg("form " + pardonForm.getName() + " is not signed! Execution stops");
	}

	printMsg("\nTEST #2-----sign and try exec again PresidentialPardonForm------");

	try {
		pardonForm.beSigned(susanne);
		pardonForm.tryExec(tom);
	}
	catch (PresidentialPardonForm::FormNotSignedException &e) {
		printMsg("form " + pardonForm.getName() + " is not signed! Execution stops");
	}
	catch (PresidentialPardonForm::GradeTooLowException &e) {
		printMsg("form " + pardonForm.getName() + " can't be executed by Junior Developer cause he or she hasn't appropriate rights");
	}

	printMsg("\nTEST #3-----try exec PresidentialPardonForm by Amazing and Graded Android-Developer------");
	std::cout << androDev << std::endl;

	try {
		pardonForm.tryExec(androDev);
	}
	catch (PresidentialPardonForm::GradeTooLowException &e) {
		printMsg("form " + pardonForm.getName() + " can't be executed by Senior Developer cause he or she hasn't appropriate rights");
	}



}
