//
// Created by  Anastasia on 10.10.2021.
//

#ifndef DAY05_FORM_HPP
#define DAY05_FORM_HPP


#include <string>
#include "Bureaucrat.hpp"

class Form {
protected:
//empty constructor
	Form();

	const std::string	_name;
	const int			_signGrade;
	const int 			_execGrade;
	bool				_isSigned;

	static const int min = 1;	//highest possible _grade
	static const int max = 150;	//lowest possible _grade

public:
	Form(const std::string& name, int signGrade, int execGrade);
//copy constructor
	Form(const Form &orig);
//destructor
	virtual ~Form();
//assignment operator
	Form &operator=(const Form &orig);
//getters and setters
	const std::string &getName() const;
	int getSignGrade() const;
	int getExecGrade() const;
	bool isSigned() const;
	void setIsSigned(bool isSigned);

	void beSigned(const Bureaucrat &b);

//exec
	virtual void execute(Bureaucrat const & executor) const; //subject func,
	bool isExecGrade(Bureaucrat const & executor) const;
	virtual void exec(Bureaucrat const & executor) const = 0;  //made Form-class Abstract

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

class FormNotSignedException : public std::logic_error
	{
	public:
		FormNotSignedException(const std::string &err);
	};

};

std::ostream &operator<<(std::ostream &out, const Form &b);



#endif //DAY05_FORM_HPP
