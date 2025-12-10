#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <memory>

class Shape {
protected:
    int id;
    
public:
    explicit Shape(int shapeId) : id(shapeId) {}
    virtual ~Shape() = default;
    
    int getId() const { return id; }
    virtual std::string getType() const = 0;
};

class Rectangle : public Shape {
public:
    explicit Rectangle(int id) : Shape(id) {}
    std::string getType() const override { return "Rectangle"; }
};

class Circle : public Shape {
public:
    explicit Circle(int id) : Shape(id) {}
    std::string getType() const override { return "Circle"; }
};

#endif