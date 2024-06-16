/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/06/16 19:01:05 by csakamot         ###   ########.fr       */
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

void  ScalarConverter::converter(const std::string& literal)
{
  try
  {
    if (ScalarConverter::isCharLiteral(literal))
      std::cout << "char ok!" << std::endl;
    else
    {
      throw ScalarConverter::invalidArguments();
    }
    if (ScalarConverter::isIntLiteral(literal))
      std::cout << "int ok!" << std::endl;
    else
      throw ScalarConverter::invalidArguments();
    if (ScalarConverter::isFloatLiteral(literal))
      std::cout << "float ok!" << std::endl;
    else
      throw ScalarConverter::invalidArguments();
    if (ScalarConverter::isDoubleLiteral(literal))
      std::cout << "double ok!" << std::endl;
    else
      throw ScalarConverter::invalidArguments();
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  return ;
}
