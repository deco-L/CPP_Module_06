/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/06/27 13:19:35 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

const char* ScalarConverter::invalidArguments::what(void) const throw()
{
  return ("\e[1;38;5;182mError: Invalid argument.\e[0m");
}

bool  ScalarConverter::isCharLiteral(const std::string& literal)
{
  return literal.length() == 1;
}

bool  ScalarConverter::isIntLiteral(const std::string& literal)
{
  char* end;
  
  strtol(literal.c_str(), &end, 10);
  return *end == '\0';
}

bool  ScalarConverter::isFloatLiteral(const std::string& literal)
{
  char  *end;

  strtof(literal.c_str(), &end);
  return *end == '\0';
}

bool  ScalarConverter::isDoubleLiteral(const std::string& literal)
{
  char* end;
  strtod(literal.c_str(), &end);
  return *end == '\0';
}

bool  ScalarConverter::isInvalidLiteral(const std::string& literal)
{
  if (literal.length() != 1)
    return (false);
  return (true);
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
  }
  else if (literal == "-inf" || literal == "-inff")
  {
    std::cout << "char:\timpossible\n"
              << "int:\timpossible\n"
              << "float:\t" << -std::numeric_limits<float>::infinity() << "\n"
              << "double:\t" << -std::numeric_limits<double>::infinity()
              << std::endl;
  }
  else if (literal == "nan" || literal == "nanf")
  {
    std::cout << "char:\timpossible\n"
              << "int:\timpossible\n"
              << "float:\tnanf\n"
              << "double:\tnan" << std::endl;
  }
  return (true);
}

void  ScalarConverter::converter(const std::string& literal)
{
  ScalarConverter::isExceptionLiteral(literal);
  return ;
}
