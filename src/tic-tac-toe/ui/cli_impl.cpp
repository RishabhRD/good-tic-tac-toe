#include "ui/cli_impl.hpp"
#include "event/event.hpp"
#include <ranges>
#include <string>
#include <vector>

auto to_string_vector(auto &&rng) {
  std::vector<std::string> res;
  for (auto str : rng) {
    std::string cur;
    for (auto c : str)
      cur += c;
    res.push_back(cur);
  }
  return res;
}

auto sep_by_space(std::string_view input) {
  return to_string_vector(std::ranges::split_view(input, ' '));
}

auto to_size_t(std::string const &str) {
  return static_cast<std::size_t>(std::stoi(str));
}

auto to_unsigned(std::string const &str) {
  return static_cast<unsigned>(std::stoi(str));
}

event::event_t cli_details::to_event(std::string_view input) {
  try {
    auto parsed_input = sep_by_space(input);
    if (parsed_input.empty())
      return event::bad_command{};
    if (parsed_input[0] == "stop") {
      return event::stop_app{};
    } else if (parsed_input[0] == "register") {
      // TODO: add additional player context like name and email.
      return event::register_player{};
    } else if (parsed_input[0] == "get_stat") {
      if (parsed_input.size() < 2)
        return event::bad_command{};
      return event::get_player_stats{to_size_t(parsed_input[1])};
    } else if (parsed_input[0] == "new_game") {
      if (parsed_input.size() < 3)
        return event::bad_command{};
      return event::start_new_game{to_size_t(parsed_input[1]),
                                   to_size_t(parsed_input[2])};
    } else if (parsed_input[0] == "game_info") {
      if (parsed_input.size() < 2)
        return event::bad_command{};
      return event::get_game_info{to_size_t(parsed_input[1])};
    } else if (parsed_input[0] == "move") {
      if (parsed_input.size() < 4)
        return event::bad_command{};
      return event::make_move{to_size_t(parsed_input[1]),
                              to_unsigned(parsed_input[2]),
                              to_unsigned(parsed_input[3])};
    }
  } catch (...) {
  }

  return event::bad_command{};
}
