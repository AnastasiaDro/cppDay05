//
// Created by  Anastasia on 10.10.2021.
//

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


#include <string>

class Bureaucrat {
private:
	std::string	name;
	int 		grade;
	static const int min = 1;	//highest possible grade
	static const int max = 150;	//lowest possible grade

public:
//getters
	const	std::string &getName() const;
	void	setName(const std::string &name);
//setters
	int		getGrade() const;
	void	setGrade(int grade);
};


#endif //DAY05_BUREAUCRAT_HPP
