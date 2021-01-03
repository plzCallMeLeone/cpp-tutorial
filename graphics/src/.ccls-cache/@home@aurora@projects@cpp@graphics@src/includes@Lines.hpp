#ifndef __LINES_HPP__
#define __LINES_HPP__


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <initializer_list>

using Point = sf::Vector2f;
using Size  = sf::Vector2f;

class Line: public sf::Drawable
{
public:
    Line(Point start, Point end)
        :points{sf::Lines, 2} {
        points[0] = start;
        points[1] = end;
    }

    void setFillColor(sf::Color color) {
        points[0].color = color;
        points[1].color = color;
    }
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(points);
    }
    sf::VertexArray points;
};

class Lines : public sf::Drawable
{
public:
    Lines() { };
    Lines(std::initializer_list<Point> list);
    void add(Point p1, Point p2);
    void setFillColor(sf::Color color);
    class InitalizationError{ };
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    std::vector<sf::Vertex> points;
};

class OpenPolyLine : public sf::Drawable {
public:
    OpenPolyLine() { }
    OpenPolyLine(std::initializer_list<Point> args) {
        for(auto &&tmp : args) { points.push_back(tmp); }
    }
    void add(Point p) { points.push_back(p); }
private:
    std::vector<sf::Vertex> points;
    virtual void draw (sf::RenderTarget& target, sf::RenderStates state) const {
        if(!points.size()) { return; }
        for(auto i = 0; i < points.size() - 1; ++i) {
            target.draw(&points[i], 2, sf::Lines);
        }
    }
};
class ClosePolyLine : public sf::Drawable {
public:
    ClosePolyLine(std::initializer_list<Point> args) {
        for (auto &&tmp : args) { points.push_back(tmp); }
    }
    void add(Point p) { points.push_back(p); }
private:
    std::vector<sf::Vertex> points;
    virtual void draw (sf::RenderTarget& target, sf::RenderStates state) const {
        if(!points.size()) { return; }
        for(auto i = 0; i < points.size() - 1; ++i) {
            target.draw(&points[i], 2, sf::Lines);
        }

        std::array<sf::Vertex, 2> arr = {points[0], points[points.size()-1]};
        target.draw(&arr[0], 2, sf::Lines);
    }
};

#endif