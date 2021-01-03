#include "includes/Lines.hpp"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <initializer_list>

Lines::Lines(std::initializer_list<Point> list)
{
    if(list.size()%2) {
        throw InitalizationError { }; // 이거보단 더 좋은 방법이 있지 않을까요...?
    }
    for(auto&& tmp : list) {
        points.push_back(tmp);
    }
}

void Lines::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(unsigned i = 0; i < points.size(); i+=2) {
        target.draw(&points[i], 2, sf::Lines);
    }
}

void Lines::add(Point p1, Point p2)
{
    points.push_back(p1);
    points.push_back(p2);
}

void Lines::setFillColor(sf::Color color)
{
    for(auto& tmp:points) {
        tmp.color = color;
    }
}
