#pragma once

#include <SFML/Graphics.hpp>

#include <cstdint>

class Camera {
public:
  Camera(sf::RenderWindow& window, sf::View& view);
  Camera(const Camera& copy) = delete;

  void move_to(const sf::Vector2f& position);
  void translate(const sf::Vector2f& offset);

  const sf::RenderWindow& get_window() const;
  const sf::View& get_view() const;

private:
  sf::RenderWindow& m_window;
  sf::View& m_view;
};