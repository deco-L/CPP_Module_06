/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/08/24 16:52:43 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdlib>
#include <cstdint>
#include <iostream>

typedef struct s_data Data;

class Serializer
{
private:
  Serializer( void );
  Serializer( const Serializer& obj );
  ~Serializer();

  Serializer& operator=(const Serializer& obj );

public:
  static uintptr_t  serialize( Data* ptr );
  static Data*      deserialize( uintptr_t raw );
};

#endif
