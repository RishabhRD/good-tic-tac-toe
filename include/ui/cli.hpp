#pragma once

#include "event/event.hpp"
#include "game/game.hpp"
#include "iterator.hpp"
#include <bits/iterator_concepts.h>
#include <bits/ranges_base.h>
#include <concepts>
#include <iostream>
#include <optional>
#include <ranges>

struct cli_ui;

class cli_event_stream {
  struct iterator_base {
    using value_type = event::event_t;
    using difference_type = long long;

    void increment() {}

    value_type deref() const { return stream->get_next().value(); }

    bool operator==(iterator_base &) const { return false; }

    bool is_end() const { return stream->to_accept_event == false; }

    cli_event_stream *stream;
  };
  cli_event_stream(cli_event_stream const &) = delete;
  cli_event_stream(cli_event_stream &&) = default;
  cli_event_stream() = default;
  std::optional<event::event_t> get_next();

  bool to_accept_event = true;

public:
  using iterator = iter::derived_input_iterator<iterator_base>;
  static_assert(std::input_iterator<iterator>);

  [[nodiscard]] auto begin() { return iterator{{this}}; }
  [[nodiscard]] auto end() const { return iter::sentinal_iterator<iterator>{}; }
  friend struct cli_ui;
  friend inline bool
  operator==(cli_event_stream::iterator const &iter,
             iter::sentinal_iterator<cli_event_stream::iterator>) {
    return iter.base.is_end();
  }
};

static_assert(std::ranges::input_range<cli_event_stream>);

struct cli_ui {
  void render(game_t const &game);
  void render_error(std::string_view msg);
  cli_event_stream &event_stream();
  void stop_ui();

private:
  cli_event_stream stream;
};
