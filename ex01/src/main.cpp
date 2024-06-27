/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/06/28 02:32:11 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <sys/ioctl.h>
#include <unistd.h>

static size_t get_term_line() {
	winsize	terminal_size;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &terminal_size);
	return (terminal_size.ws_col);
}

static void draw_terminal_line() {
	size_t	terminal_col;

	terminal_col = get_term_line();
	for (size_t i = 0; i < terminal_col; i++)
		std::cout << "=";
	std::cout << std::endl;
	return ;
}

int main(void) {
  draw_terminal_line();
  Data originalData = {42};
  uintptr_t raw = Serializer::serialize(&originalData);
  Data* deserializedData = Serializer::deserialize(raw);

  std::cout << "Serialized data: " << raw << std::endl;
  std::cout << "Deserialized data: index = " << deserializedData->index << std::endl;
  if (deserializedData == &originalData) {
      std::cout << "The deserialized pointer is equal to the original pointer." << std::endl;
  } else {
      std::cout << "The deserialized pointer is NOT equal to the original pointer." << std::endl;
  }
  draw_terminal_line();
  return (EXIT_SUCCESS);
}
