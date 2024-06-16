/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/06/16 18:25:13 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cstdlib>
#include <iostream>
#include <exception>

class ScalarConverter
{
private:
  ScalarConverter( void );
  static bool isCharLiteral( const std::string& literal );
  static bool isIntLiteral( const std::string& literal );
  static bool isFloatLiteral( const std::string& literal );
  static bool isDoubleLiteral( const std::string& literal );

public:
  static void converter( const std::string& literal );

  class invalidArguments : public std::exception
  {
    public:
    virtual const char* what( void ) const throw();
  };
};

#endif
