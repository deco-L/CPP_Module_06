/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/06/28 02:28:26 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

Serializer::Serializer(void) {}

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
