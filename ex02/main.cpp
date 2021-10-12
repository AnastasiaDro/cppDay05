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

	printMsg("---TEST #0---");
	printMsg("Let's try to create invalid forms!");
	try{
		printMsg("invalid signGrade: 151");
		Form invForm1("invForm1", 151, 50);
	}
	catch (Form::GradeTooLowException &e) {
		printMsg("Form signGrade is too low");
	}
	try{
		printMsg("invalid signGrade: 0");
		Form invForm2("invForm2", 0, 50);
	}
	catch (Form::GradeTooHighException &e) {
		printMsg("Form signGrade is too high");
	}

	try{
		printMsg("invalid execGrade: 151");
		Form invForm1("invForm1", 50, 151);
	}
	catch (Form::GradeTooLowException &e) {
		printMsg("CATCH: Form execGrade is too low");
	}
	try{
		printMsg("invalid execGradee: 0");
		Form invForm3("invForm2", 50, 0);
	}
	catch (Form::GradeTooHighException &e) {
		printMsg("CATCH: Form signGrade is too high");
	}


	printMsg("\n Let's sign valid forms, guys!");

	printMsg("\n---TEST #1---");
	printMsg("Tom and Form1 are first");
	try {
		form1.beSigned(tom); // can't
	} catch (Form::GradeTooLowException &e) {
		std::cout << "CATCH: " << tom << " can't sign" << form1 << std::endl;
	}

	printMsg("\n---TEST #2---");
	printMsg("Form2, Tom");
	try {
		form2.beSigned(tom); // can't
	} catch (Form::GradeTooLowException &e) {
		std::cout << "CATCH: "  << tom << " can't sign" << form2 << std::endl;
	}

	printMsg("\n---TEST #3---");
	printMsg("Form1, Susanne");
	try {
		form1.beSigned(susanne); // can't
	} catch (Form::GradeTooLowException &e) {
		std::cout << "CATCH: " << susanne << " can't sign" << form1 << std::endl;
	}

	printMsg("\n*****-CANCELING THE SIGNATURES-*****");
	form1.setIsSigned(false);
	form2.setIsSigned(false);

	printMsg("\n---TEST #4---");
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

	printMsg("\n---TEST #5---");
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
