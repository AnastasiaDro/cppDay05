//
// Created by  Anastasia on 10.10.2021.
//

#include "Bureaucrat.hpp"

const std::string &Bureaucrat::getName() const {
	return name;
}

void Bureaucrat::incGrade(int n) {
	this->grade += n;
}

void Bureaucrat::decrGrade(int n) {
	this->grade -= n;
}

int Bureaucrat::getGrade() const {
	return grade;
}


