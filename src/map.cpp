#include "map.h"

#include "search.h"

namespace {
  static std::vector<sf::Vector3i> s_grid;
}

void map::build(const sf::Vector3i start, int32_t distance) {
  search::range(start, distance, s_grid);
}

void map::for_each_tile(std::function<void(const sf::Vector3i& coord)> operation) {
  for (auto grid : s_grid) {
    operation(grid);
  }
}