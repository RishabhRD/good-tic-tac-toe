#include "ui/cli.hpp"
#include "event/event.hpp"
#include "ui/cli_impl.hpp"
#include <iostream>
#include <string>

std::optional<event::event_t> cli_event_stream::get_next() {
  if (!to_accept_event)
    return std::nullopt;
  std::cout << "You input >>> ";
  std::string input;
  std::getline(std::cin, input);
  return cli_details::to_event(input);
}

void cli_ui::render(game_t const &game) {
  std::cout << "----------------------------------" << std::endl;
  std::cout << game << std::endl;
  std::cout << "----------------------------------" << std::endl;
}

void cli_ui::render_error(std::string_view msg) {
  std::cout << "----------------------------------" << std::endl;
  std::cout << msg << std::endl;
  std::cout << "----------------------------------" << std::endl;
}

void cli_ui::stop_ui() { stream.to_accept_event = false; }

cli_event_stream &cli_ui::event_stream() { return stream; }
