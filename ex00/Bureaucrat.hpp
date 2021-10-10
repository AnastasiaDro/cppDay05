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
	Bureaucrat(const std::string &name, int grade);
//getters
	const	std::string &getName() const;
	int		getGrade() const;
	void setGrade(int grade);

//_grade operarions
	void 	incGrade(int n);
	void 	decrGrade(int n);

//operators
	Bureaucrat &operator=(const Bureaucrat &orig);

//exceptions
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
