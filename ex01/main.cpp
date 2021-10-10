#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {

	//naming constructor
	Bureaucrat tom("Tom"); //autograde = 75
	Bureaucrat susanne("Susanne", 1);
	Form form("")

	std:: cout	<< tom << std::endl;
	std:: cout	<< susanne << std::endl;

	printMsg("Hello, guys!");
	try {
		susanne.incGrade(5);
		tom.decrGrade(80); // has 75 now 75 + 80 = 155 but the lowest is 150
	} catch (Bureaucrat::GradeTooHighException &e){
		std::cout << susanne << " can't increment her grade" << std::endl;
		//worked just first block
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << tom << " can't decrement his grade" << std::endl;
	}

	try {
		tom.decrGrade(80); // has 75 now 75 + 80 = 155 but the lowest is 150
		susanne.incGrade(5);
	} catch (Bureaucrat::GradeTooHighException &e){
		std::cout << susanne << " can't increment her grade" << std::endl;
		//worked just first block
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << tom << " can't decrement his grade" << std::endl;
	}

	try {
		tom.incGrade(40); // has 75 now 75 + 80 = 155 but the lowest is 150
		susanne.decrGrade(100);
	} catch (Bureaucrat::GradeTooHighException &e){
		std::cout << susanne << " can't increment her grade" << std::endl;
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << tom << " can't decrement his grade" << std::endl;
	}
	std::cout << tom << std::endl;
	std::cout << susanne << std::endl;
	return 0;
}
