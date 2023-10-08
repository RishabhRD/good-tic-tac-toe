#pragma once

#include "application/application.hpp"
#include "event/event.hpp"
#include <vector>

auto handle_register_player(application_state_t &app,
                            event::register_player evt)
    -> std::vector<event::event_t>;

auto handle_player_won(application_state_t &app, event::player_won evt)
    -> std::vector<event::event_t>;

auto handle_player_lost(application_state_t &app, event::player_lost evt)
    -> std::vector<event::event_t>;

auto handle_player_drew(application_state_t &app, event::player_drew evt)
    -> std::vector<event::event_t>;

auto handle_get_player_stats(application_state_t &app,
                             event::get_player_stats evt)
    -> std::vector<event::event_t>;

auto handle_start_new_game(application_state_t &app, event::start_new_game evt)
    -> std::vector<event::event_t>;

auto handle_get_game_info(application_state_t &app, event::get_game_info evt)
    -> std::vector<event::event_t>;

auto handle_make_move(application_state_t &app, event::make_move evt)
    -> std::vector<event::event_t>;

auto handle_render_game(application_state_t &app, event::render_game evt)
    -> std::vector<event::event_t>;

auto handle_stop_app(application_state_t &app, event::stop_app evt)
    -> std::vector<event::event_t>;

auto handle_bad_cmd(application_state_t &app, event::bad_command evt)
    -> std::vector<event::event_t>;

auto handle_game_event(application_state_t &app, event::event_t evt)
    -> std::vector<event::event_t>;
