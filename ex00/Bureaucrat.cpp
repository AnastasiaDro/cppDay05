//
// Created by  Anastasia on 10.10.2021.
//

#include "Bureaucrat.hpp"

const std::string &Bureaucrat::getName() const {
	return name;
}

void Bureaucrat::setName(const std::string &name) {
	Bureaucrat::name = name;
}

int Bureaucrat::getGrade() const {
	return grade;
}

void Bureaucrat::setGrade(int grade) {
	Bureaucrat::grade = grade;
}
