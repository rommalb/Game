#include "camera.h"


Camera::Camera(sf::RenderWindow& window, sf::View& view) :
  m_window(window)
  , m_view(view)
{
}

void Camera::move_to(const sf::Vector2f& position)
{
  m_view.setCenter(position);
  m_window.setView(m_view);
}

void Camera::translate(const sf::Vector2f& offset)
{
  m_view.move(offset);
  m_window.setView(m_view);
}

const sf::RenderWindow& Camera::get_window() const
{
  return m_window;
}

const sf::View& Camera::get_view() const
{
  return m_view;
}