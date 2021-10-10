//
// Created by  Anastasia on 10.10.2021.
//

#ifndef DAY05_FORM_HPP
#define DAY05_FORM_HPP


#include <string>

class Form {
private:
	const std::string	_name;
	const int			_signGrade;
	const int 			_execGrade;
	bool				_isSigned;

public:


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


#endif //DAY05_FORM_HPP
