#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {

	//naming constructor
	Bureaucrat tom("Tom"); //autograde = 75
	Bureaucrat susanne("Susanne", 1);
	Bureaucrat junDev("Junior Developer", 138);
	Bureaucrat senDev("Senior Developer", 45);
	Bureaucrat androDev("AndroDev", 3);

	std::cout << tom << std::endl;
	std::cout << susanne << std::endl;

//------------------------------//
//NEW "INTERN" TESTS: 			//
//------------------------------//

	Intern intern;
	Form *internForm0;
	Form *internForm1;
	Form *internForm2;
	Form *internForm3;

	printMsg("\nTEST #0-----INTERN generates ShrubberyCreationForm------");
	internForm0 = intern.makeForm("Shrubbery request", "intern_garden");

	std::cout << *internForm0 << std::endl;

	printMsg("\nTEST #1-----INTERN generates RobotomyRequestForm------");

	internForm1 = intern.makeForm("Robotomy request", "the head of the company");
	std::cout << *internForm1 << std::endl;

	printMsg("\nTEST #2-----INTERN generates PresidentialPardonForm------");

	internForm2 = intern.makeForm("Pardon request", "Junior Developer");
	std::cout << *internForm2 << std::endl;

	printMsg("\nTEST #3-----INTERN generates NON-EXISTENT form------");

	internForm3 = intern.makeForm("Sleep request", "the head of the company");
	if (internForm3 != nullptr)
		std::cout << *internForm3 << std::endl;
	else
		std::cout << "empty pointer -> " << internForm3 << std::endl;


	printMsg("\nTEST #4----LET'S sign one of the created by Intern forms------");
	internForm0->beSigned(susanne);
	internForm0->execute(senDev);

	delete internForm0;
	delete internForm1;
	delete internForm2;
	delete internForm3;

////------------------------------//
////OLD TESTS: 					//
////------------------------------//
//
//
//	printMsg("TESTS ShrubberyCreationForm");
//	printMsg("\nTEST #0-----generate ShrubberyCreationForm------");
//	std::string str = "home";
//	ShrubberyCreationForm treeForm(str);
//	std::cout << treeForm << std::endl;
//	printMsg("SUCSESS!");
//
//
//	printMsg("\nTEST #1-----try exec ShrubberyCreationForm------");
//	susanne.executeForm(treeForm);
//
//	printMsg("\nTEST #2-----sign and try exec again ShrubberyCreationForm------");
//	treeForm.beSigned(susanne);
//	susanne.executeForm(treeForm);
//
//	printMsg("\nTEST #3-----try exec ShrubberyCreationForm by low Graded Junior Developer------");
//	std::cout << junDev << std::endl;
//
//	junDev.executeForm(treeForm);
//
////------------------------------//
////NEXT FORM: RobotomyRequestForm//
////------------------------------//
//
//
//	printMsg("\n\nTESTS RobotomyRequestForm");
//	printMsg("\nTEST #0-----generate RobotomyRequestForm------");
//	std::string str1 = "SEO";
//	RobotomyRequestForm roboForm(str1);
//	std::cout << roboForm << std::endl;
//	printMsg("SUCSESS!");
//
//	printMsg("\nTEST #1-----try exec RobotomyRequestForm------");
//	tom.executeForm(roboForm);
//
//
//	printMsg("\nTEST #2-----sign and try exec again RobotomyRequestForm------");
//	roboForm.beSigned(susanne);
//	tom.executeForm(roboForm);
//
//	printMsg("\nTEST #3-----try exec RobotomyRequestForm by middle Graded Senior Developer------");
//	std::cout << senDev << std::endl;
//	senDev.executeForm(roboForm);
//
//
//
//
////------------------------------//
////NEXT FORM: PresidentalPardonForm//
////------------------------------//
//
//	printMsg("\n\nTESTS PresidentialPardonForm");
//	printMsg("\nTEST #0-----generate PresidentialPardonForm------");
//	std::string str2 = "JunDev";
//	PresidentialPardonForm pardonForm(str2);
//	std::cout << pardonForm << std::endl;
//	printMsg("SUCSESS!");
//
//
//	printMsg("\nTEST #1-----try exec PresidentialPardonForm------");
//	tom.executeForm(pardonForm);
//
//	printMsg("\nTEST #2-----sign and try exec again PresidentialPardonForm------");
//
//	pardonForm.beSigned(susanne);
//	tom.executeForm(pardonForm);
//
//	printMsg("\nTEST #3-----try exec PresidentialPardonForm by Amazing and Graded Android-Developer------");
//	std::cout << androDev << std::endl;
//	androDev.executeForm(pardonForm);
}