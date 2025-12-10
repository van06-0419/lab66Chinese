#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "Shape.h"
#include <vector>
#include <memory>

class Document {
private:
    int id;
    std::vector<std::unique_ptr<Shape>> shapes;
    
public:
    explicit Document(int docId);
    
    int getId() const { return id; }
    void addShape(std::unique_ptr<Shape> shape);
    void removeShape(int shapeId);
};

#endif