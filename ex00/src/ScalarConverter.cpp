/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/06/26 17:57:06 by csakamot         ###   ########.fr       */
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
  return (true);
}

bool  ScalarConverter::isExceptionLiteral(const std::string& literal)
{
  if (literal == "+inf")
  {

  }
  else if (literal == "-inf")
  {

  }
  else if (literal == "nan")
  {
    std::cout << "char:\vimpossible\n"
              << "int:\vimpossible\n"
              << "float:\vnanf\n"
              << "double:\vnan" << std::endl;
  }
  return (true);
}

void  ScalarConverter::converter(const std::string& literal)
{
  if (ScalarConverter::isCharLiteral(literal))
    std::cout << "char ok!" << std::endl;
  if (ScalarConverter::isIntLiteral(literal))
    std::cout << "int ok!" << std::endl;
  if (ScalarConverter::isFloatLiteral(literal))
    std::cout << "float ok!" << std::endl;
  if (ScalarConverter::isDoubleLiteral(literal))
    std::cout << "double ok!" << std::endl;
  return ;
}
