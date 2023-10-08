#include "event/handler.hpp"
#include "application/application.hpp"
#include "event/event.hpp"
#include "functional.hpp"
#include <functional>
#include <variant>

auto handle_register_player(application_state_t &, event::register_player)
    -> std::vector<event::event_t> {
  return {};
}

auto handle_player_won(application_state_t &, event::player_won)
    -> std::vector<event::event_t> {
  return {};
}

auto handle_player_lost(application_state_t &, event::player_lost)
    -> std::vector<event::event_t> {
  return {};
}

auto handle_player_drew(application_state_t &, event::player_drew)
    -> std::vector<event::event_t> {
  return {};
}

auto handle_get_player_stats(application_state_t &, event::get_player_stats)
    -> std::vector<event::event_t> {
  return {};
}

auto handle_start_new_game(application_state_t &, event::start_new_game)
    -> std::vector<event::event_t> {
  return {event::render_game{0}};
}

auto handle_get_game_info(application_state_t &, event::get_game_info)
    -> std::vector<event::event_t> {
  return {};
}

auto handle_make_move(application_state_t &, event::make_move evt)
    -> std::vector<event::event_t> {
  return {event::render_game{evt.game_id}};
}

auto handle_render_game(application_state_t &app, event::render_game evt)
    -> std::vector<event::event_t> {
  // TODO: This is wrong implementation
  app.ui.render(evt.game_id);
  return {};
}

auto handle_stop_game(application_state_t &app, event::stop_app)
    -> std::vector<event::event_t> {
  app.ui.stop_ui();
  return {};
}

auto handle_bad_cmd(application_state_t &app, event::bad_command)
    -> std::vector<event::event_t> {
  app.ui.render_error("Bad Command");
  return {};
}

auto handle_game_event(application_state_t &app, event::event_t evt)
    -> std::vector<event::event_t> {
#define handler(func) std::bind_front(lift(func), std::ref(app))
  auto event_handler = fun::overloaded{
      handler(handle_register_player),  handler(handle_player_won),
      handler(handle_player_lost),      handler(handle_player_drew),
      handler(handle_get_player_stats), handler(handle_start_new_game),
      handler(handle_get_game_info),    handler(handle_make_move),
      handler(handle_render_game),      handler(handle_stop_game),
      handler(handle_bad_cmd),
  };
  return std::visit(event_handler, evt);
}
