#pragma once

#include <string_view>
#include <variant>

namespace event {

struct register_player {
  // TODO: player payload here
};

struct player_won {
  std::size_t player_id;
};

struct player_lost {
  std::size_t player_id;
};

struct player_drew {
  std::size_t player_id;
};

struct get_player_stats {
  std::size_t player_id;
};

struct start_new_game {
  std::size_t player_id_1;
  std::size_t player_id_2;
};

struct get_game_info {
  std::size_t game_id;
};

struct make_move {
  std::size_t game_id;
  unsigned row;
  unsigned col;
};

struct render_game {
  std::size_t game_id;
};

struct stop_app {};

struct bad_command {};

using event_t =
    std::variant<register_player, player_won, player_lost, player_drew,
                 start_new_game, make_move, get_player_stats, get_game_info,
                 render_game, stop_app, bad_command>;
} // namespace event
