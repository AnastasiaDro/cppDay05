#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {

	//naming constructor
	Bureaucrat tom("Tom"); //autograde = 75
	Bureaucrat susanne("Susanne", 1);
	Form form1("Form1", 50, 5);
	Form form2("Form2", 90, 100);

	std:: cout	<< tom << std::endl;
	std:: cout	<< susanne << std::endl;
	std:: cout	<< form1 <<std::endl;
	std:: cout	<< form2 <<std::endl;

	printMsg("Let's sign, guys!");

	printMsg("---TEST #1---");
	printMsg("Tom and Form1 are first");
	try {
		form1.beSigned(tom); // can't
	} catch (Form::GradeTooLowException &e) {
		std::cout << "CATCH: " << tom << " can't sign" << form1 << std::endl;
	}

	printMsg("---TEST #2---");
	printMsg("Form2, Tom");
	try {
		form2.beSigned(tom); // can't
	} catch (Form::GradeTooLowException &e) {
		std::cout << "CATCH: "  << tom << " can't sign" << form2 << std::endl;
	}

	printMsg("---TEST #3---");
	printMsg("Form1, Susanne");
	try {
		form1.beSigned(susanne); // can't
	} catch (Form::GradeTooLowException &e) {
		std::cout << "CATCH: " << susanne << " can't sign" << form1 << std::endl;
	}

	printMsg("---TEST #4---");
	printMsg("Susanne, you're demoted");
	try {
		susanne.decrGrade(101);
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << "CATCH: " << susanne << " can't increment her grade" << std::endl;
	}
	std::cout << susanne << std::endl;

	printMsg("Form1, Susanne");
	try {
		form1.beSigned(susanne); // can't
	} catch (Form::GradeTooLowException &e) {
		std::cout << "CATCH: " << susanne << " can't sign" << form1 << std::endl;
	}

	printMsg("---TEST #5---");
	printMsg("Tom, you're promoted");
	try {
		tom.incGrade(50);
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << "CATCH: " << tom << " can't increment his grade" << std::endl;
	}
	std::cout << tom << std::endl;

	printMsg("Form1, Tom");
	try {
		form1.beSigned(tom); // can't
	} catch (Form::GradeTooLowException &e) {
		std::cout << "CATCH: " << tom << " can't sign" << form1 << std::endl;
	}

	printMsg("Oh, my God, it works! <OoO>");
	return 0;
}
