/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/08/24 19:08:31 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

double  ScalarConverter::_value = 0;
bool    ScalarConverter::_inf = false;
size_t  ScalarConverter::_zeroCount = 0;
bool    ScalarConverter::_isDot = true;

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter& obj)
{
  *this = obj;
}

ScalarConverter::~ScalarConverter() {}

const char* ScalarConverter::invalidArguments::what(void) const throw()
{
  return ("\e[1;38;5;160mError: Invalid argument.\e[0m");
}

void ScalarConverter::countZerosAfterDot(const std::string& str)
{
  std::size_t dotPos = str.find('.');
  if (dotPos == std::string::npos) {
    ScalarConverter::_isDot = false;
    return ;
  }
  std::string afterDot = str.substr(dotPos + 1);
  for (size_t i = 0; afterDot[i] != '\0' && afterDot[i] != 'f'; i++) {
    if (afterDot[i] != '0') {
      ScalarConverter::_isDot = false;
      ScalarConverter::_zeroCount = 0;
    }
    else
      ScalarConverter::_zeroCount++;
  }
  if (!ScalarConverter::_zeroCount)
    ScalarConverter::_isDot = false;
  return ;
}


void  ScalarConverter::isInvalidLiteral(const std::string& literal)
{
  std::stringstream ss;

  if (literal.length() == 0)
    throw ScalarConverter::invalidArguments();
  ScalarConverter::countZerosAfterDot(literal);
  if (
    (std::isdigit(literal[0]) || literal[0] == '+' || literal[0] == '-')
    && literal[literal.length() - 1] == 'f'
  )
    ss << literal.substr(0, literal.length() - 1);
  else
    ss << literal;
  ss >> ScalarConverter::_value;
  if (!ss.eof())
    throw ScalarConverter::invalidArguments();
  if (ss.fail() &&
    (ScalarConverter::_value == __DBL_MAX__ ||
    ScalarConverter::_value == -__DBL_MAX__)
  ) {
    ScalarConverter::_inf = true;
    return ;
  }
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
  std::cout << "float:\t" << tmp;
  if (ScalarConverter::_isDot)
    std::cout << '.';
  if (ScalarConverter::_zeroCount) {
    std::string zeros(ScalarConverter::_zeroCount, '0');
    std::cout << zeros;
  }
  std::cout << 'f' << std::endl;
  return ;
}

void  ScalarConverter::doubleConverter(void)
{
  if (ScalarConverter::_inf && ScalarConverter::_value == __DBL_MAX__)
    std::cout << "double:\tinf" << std::endl;
  else if (ScalarConverter::_inf && ScalarConverter::_value == -__DBL_MAX__)
    std::cout << "double:\t-inf" << std::endl;
  else {
    std::cout << "double:\t" << ScalarConverter::_value;
    if (ScalarConverter::_isDot)
      std::cout << '.';
    if (ScalarConverter::_zeroCount) {
      std::string zeros(ScalarConverter::_zeroCount, '0');
      std::cout << zeros;
    }
  }
  std::cout << std::endl;
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

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj)
{
  if (this != &obj) {
    ;
  }
  else
    std::cout << "\e[1;31mAnimal Error: "
              << "Attempted self-assignment in copy assignment operator"
              << "\e[0m"
              << std::endl;
  return(*this);
}
