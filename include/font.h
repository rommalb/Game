
#pragma once

#include <string>
#include <SFML/System/Vector2.hpp>

namespace sf
{
  class RenderWindow;
}

namespace font {
  void init_font();
  bool render_string(sf::RenderWindow& renderWindow, std::string& displayText, sf::Vector2f& displayLocation);
}