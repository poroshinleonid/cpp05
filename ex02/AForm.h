#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.h"
#include <iostream>
#include <stdexcept>
#include <string>

class AForm {
public:
  AForm();
  AForm(AForm const &other);
  ~AForm();
  AForm &operator=(const AForm &obj);

  AForm(const std::string &name, int grade_to_sign, int grade_to_execute);

  const std::string &getName() const;
  const bool &isSigned() const;
  const int &getGradeToSign() const;
  const int &getGradeToExecute() const;

  void beSigned(const Bureaucrat &signer);

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade too high"; }
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade too low"; }
  };

private:
  static const int min_possible_grade_value_ = 1;
  static const int max_possible_grade_value_ = 150;
  const std::string name_;
  bool is_signed_;
  const int grade_to_sign_;
  const int grade_to_execute_;
};

std::ostream &operator<<(std::ostream &out_stream, const AForm &AForm);

#endif // AForm_HPP