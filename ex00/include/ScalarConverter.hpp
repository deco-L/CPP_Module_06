/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/08/24 19:03:49 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cstdlib>
#include <iostream>
#include <limits>
#include <exception>
#include <sstream>

class ScalarConverter
{
private:
  static  double  _value;
  static  bool    _inf;
  static  size_t  _zeroCount;
  static  bool    _isDot;

  ScalarConverter( void );
  ScalarConverter( const ScalarConverter& obj );
  ~ScalarConverter();

  static void countZerosAfterDot( const std::string& str);
  static void charConverter( void );
  static void intConverter( void );
  static void floatConverter( void );
  static void doubleConverter( void );
  static bool isExceptionLiteral( const std::string& literal );
  static void isInvalidLiteral( const std::string& literal );

  ScalarConverter&  operator=( const ScalarConverter& obj );

public:
  static void converter( const std::string& literal );

  class invalidArguments : public std::exception
  {
    public:
    virtual const char* what( void ) const throw();
  };

};

#endif
