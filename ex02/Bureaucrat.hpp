//
// Created by  Anastasia on 10.10.2021.
//

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


#include <string>
class Form;

class Bureaucrat {
private:
//empty constructor
	Bureaucrat();
	const std::string	_name;
	int 				_grade;
	static const int min = 1;	//highest possible _grade
	static const int max = 150;	//lowest possible _grade

public:
	Bureaucrat(const std::string &name);
	Bureaucrat(const std::string &name, int grade);
//copy constructor
	Bureaucrat(const Bureaucrat &orig);
//destructor
	~Bureaucrat();
//assignment operator
	Bureaucrat &operator=(const Bureaucrat &orig);
	void executeForm(Form const & form) const;
//getters
	const	std::string &getName() const;
	int		getGrade() const;
	void 	setGrade(int grade);

//_grade operarions
	void 	incGrade(int n);
	void 	decrGrade(int n);

//exception classes
class GradeTooHighException : public std::logic_error
	{
	public:
		GradeTooHighException(const std::string &err);
	};

class GradeTooLowException : public std::logic_error
	{
	public:
		GradeTooLowException(const std::string &err);
	};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

void	printMsg(std::string const &msg);

#endif //BUREAUCRAT_HPP
