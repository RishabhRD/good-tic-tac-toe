#include "application/application.hpp"
#include "event/event.hpp"
#include "event/handler.hpp"
#include <queue>

void run_event_loop(application_state_t &app) {
  std::queue<event::event_t> events;
  for (auto evt : app.ui.event_stream()) {
    events.push(std::move(evt));
    while (events.size()) {
      auto cur_event = std::move(events.front());
      events.pop();
      for (auto new_evt : handle_game_event(app, std::move(cur_event))) {
        events.push(new_evt);
      }
    }
  }
}

int main() {
  application_state_t app;
  run_event_loop(app);
}
