#pragma once

#include <SFML/Graphics.hpp>

#include <cstdint>

class HexagonShape {
public:
  HexagonShape(uint32_t size, sf::Vector2f position);

  const sf::Drawable& get_drawable() const;

private:
  sf::ConvexShape m_polygon;
};