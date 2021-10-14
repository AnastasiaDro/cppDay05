//
// Created by Cesar Erebus on 10/12/21.
//

#include <iostream>
#include "ShrubberyCreationForm.hpp"




ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string &target) : Form("ShrubberyCreationForm", 145, 137),
																		_target(target){}

const std::string &ShrubberyCreationForm::getTarget(){
	return this->_target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &orig) : Form(orig.getName(), orig._signGrade, orig.getExecGrade())
{
	*this = orig;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &orig) {
	if (this == &orig)
		return *this;
	this->_target = orig._target;
	return *this;
}

void ShrubberyCreationForm::exec(const Bureaucrat &executor) const {
	std::ofstream fileOut;

	fileOut.open(_target + "_shrubbery");
	if(!fileOut)
	{
		printMsg(executor.getName() + " can't create/open " + _target + "_shrubbery file!");
		return; //исключение!
	}
	printMsg(executor.getName() + " planted a tree in the " + this->_target);
	fileOut << drawTree();
	fileOut.close();
}

std::string ShrubberyCreationForm::drawTree() {

	std::string tree;

	tree = "                                               |\n"
		   "                                              -x-\n"
		   "                                               |\n"
		   "              v .   ._, |_  .,\n"
		   "           `-._\\/  .  \\ /    |/_\n"
		   "               \\\\  _\\, y | \\//\n"
		   "         _\\_.___\\\\, \\\\/ -.\\||\n"
		   "           `7-,--.`._||  / / ,\n"
		   "           /'     `-. `./ / |/_.'\n"
		   "                     |    |//\n"
		   "                     |_    /\n"
		   "                     |-   |\n"
		   "                     |   =|\n"
		   "                     |    |\n"
		   "--------------------/ ,  . \\--------._\n"
		   "Igdrasil";
	return tree;
}

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm scf)
{
	std::cout	<< scf.getName()
				<< ", form sign grade "
				<< scf.getSignGrade()
				<< ", exec grade "
				<< scf.getExecGrade()
				<< ", target "
				<< scf.getTarget();
	return out;
}



