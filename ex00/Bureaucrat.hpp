//
// Created by  Anastasia on 10.10.2021.
//

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


#include <string>

class Bureaucrat {
private:
	Bureaucrat();
	const std::string	_name;
	int 				_grade;
	static const int min = 1;	//highest possible _grade
	static const int max = 150;	//lowest possible _grade

public:
	Bureaucrat(const std::string &name);
//getters
	const	std::string &getName() const;
	int		getGrade() const;

//_grade operarions
	void 	incGrade(int n);
	void 	decrGrade(int n);

//operators
	Bureaucrat &operator=(const Bureaucrat &orig);

//exceptions
class GradeTooHighException
{

};

class GradeTooLowException
{

};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif //DAY05_BUREAUCRAT_HPP
