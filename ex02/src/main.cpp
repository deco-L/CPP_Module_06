/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/08/24 19:45:20 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
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

Base* generate(void)
{
  int roll;

  srand(time(NULL));
  roll = std::rand();
  if (roll % 3 == 0)
    return (new A);
  else if (roll % 3 == 1)
    return (new B);
  else
    return (new C);
}

void  identify(Base* p)
{
  if (dynamic_cast<A*>(p))
    std::cout << "The type of this Base pointer is A." << std::endl;
  else if (dynamic_cast<B*>(p))
    std::cout << "The type of this Base pointer is B." << std::endl;
  else if (dynamic_cast<C*>(p))
    std::cout << "The type of this Base pointer is C." << std::endl;
  return ;
}

void  identify(Base& p)
{
  try {
    A& a_ref = dynamic_cast<A&>(p);
    std::cout << "The type of this Base reference is A." << std::endl;
    (void)a_ref;
    return ;
  } catch (const std::bad_cast& e) {
    std::cout << "Failed to cast Base reference: " << e.what() << std::endl;
  }

  try {
    B& b_ref = dynamic_cast<B&>(p);
    std::cout << "The type of this Base reference is B." << std::endl;
    (void)b_ref;
    return ;
  } catch (const std::bad_cast& e) {
    std::cout << "Failed to cast Base reference: " << e.what() << std::endl;
  }

  try {
    C& c_ref = dynamic_cast<C&>(p);
    std::cout << "The type of this Base reference is C." << std::endl;
    (void)c_ref;
    return ;
  } catch (const std::bad_cast& e) {
    std::cout << "Failed to cast Base reference: " << e.what() << std::endl;
  }
}

int main(void) {
  draw_terminal_line();
  {
    Base  *tmp = generate();
    identify(tmp);
    identify(*tmp);
    delete tmp;
  }
  draw_terminal_line();
  return (EXIT_SUCCESS);
}
