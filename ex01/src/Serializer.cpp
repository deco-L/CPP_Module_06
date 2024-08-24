/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/08/24 16:54:31 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

Serializer::Serializer(void) {}

Serializer::Serializer(const Serializer& obj)
{
  *this = obj;
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr)
{
  uintptr_t tmp;

  tmp = reinterpret_cast<uintptr_t>(ptr);
  return (tmp);
}

Data* Serializer::deserialize(uintptr_t raw)
{
  Data* tmp;

  tmp = reinterpret_cast<Data*>(raw);
  return (tmp);
}

Serializer& Serializer::operator=(const Serializer& obj)
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
