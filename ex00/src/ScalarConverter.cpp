/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/07/14 18:29:39 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

double  ScalarConverter::_value = 0;

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::~ScalarConverter() {}

const char* ScalarConverter::invalidArguments::what(void) const throw()
{
  return ("\e[1;38;5;182mError: Invalid argument.\e[0m");
}

void  ScalarConverter::isInvalidLiteral(const std::string& literal)
{
  std::stringstream ss;

  if (literal.length() == 0)
    throw ScalarConverter::invalidArguments();
  if (std::isdigit(literal[0]) && literal[literal.length() - 1] == 'f')
    ss << literal.substr(0, literal.length() - 1);
  else
    ss << literal;
  ss >> ScalarConverter::_value;
  if (!ss.eof())
    throw ScalarConverter::invalidArguments();
  if (ss.fail() &&
    (ScalarConverter::_value == __DBL_MAX__ ||
    ScalarConverter::_value == -__DBL_MAX__)
  )
    return ;
  if (ss.fail())
  {
    if (literal.length() != 1)
      throw ScalarConverter::invalidArguments();
    _value = static_cast<double>(literal[0]);
  }
  return ;
}

bool  ScalarConverter::isExceptionLiteral(const std::string& literal)
{
  if (literal == "+inf" || literal == "+inff")
  {
    std::cout << "char:\timpossible\n"
              << "int:\timpossible\n"
              << "float:\t" << std::numeric_limits<float>::infinity() << "\n"
              << "double:\t" << std::numeric_limits<double>::infinity()
              << std::endl;
    return (true);
  }
  else if (literal == "-inf" || literal == "-inff")
  {
    std::cout << "char:\timpossible\n"
              << "int:\timpossible\n"
              << "float:\t" << -std::numeric_limits<float>::infinity() << "\n"
              << "double:\t" << -std::numeric_limits<double>::infinity()
              << std::endl;
    return (true);
  }
  else if (literal == "nan" || literal == "nanf")
  {
    std::cout << "char:\timpossible\n"
              << "int:\timpossible\n"
              << "float:\tnanf\n"
              << "double:\tnan" << std::endl;
    return (true);
  }
  return(false) ;
}

void  ScalarConverter::charConverter(void)
{
  char  tmp;

  if (126 < ScalarConverter::_value || ScalarConverter::_value < 32)
  {
    std::cout << "char:\tNon displayable" << std::endl;
    return ;
  }
  tmp = static_cast<char>(ScalarConverter::_value);
  std::cout << "char:\t" << tmp << std::endl;
  return ;
}

void  ScalarConverter::intConverter(void)
{
  int tmp;

  if (__INT_MAX__ < ScalarConverter::_value ||
    ScalarConverter::_value < -__INT_MAX__ - 1)
  {
    std::cout << "int:\timpossible" << std::endl;
    return ;
  }
  tmp = static_cast<int>(ScalarConverter::_value);
  std::cout << "int:\t" << tmp << std::endl;
  return ;
}

void  ScalarConverter::floatConverter(void)
{
  float tmp;

  tmp = static_cast<float>(ScalarConverter::_value);
  std::cout << "float:\t" << tmp << "f" << std::endl;
  return ;
}

void  ScalarConverter::doubleConverter(void)
{
  if (ScalarConverter::_value == __DBL_MAX__)
    std::cout << "double:\tinf" << std::endl;
  else if (ScalarConverter::_value == -__DBL_MAX__)
    std::cout << "double:\t-inf" << std::endl;
  else
    std::cout << "double:\t" << ScalarConverter::_value << std::endl;
  return ;
}

void  ScalarConverter::converter(const std::string& literal)
{
  if (ScalarConverter::isExceptionLiteral(literal))
    return ;
  try
  {
    ScalarConverter::isInvalidLiteral(literal);
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    return ;
  }
  ScalarConverter::charConverter();
  ScalarConverter::intConverter();
  ScalarConverter::floatConverter();
  ScalarConverter::doubleConverter();
  return ;
}
