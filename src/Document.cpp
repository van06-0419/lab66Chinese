#include "Document.h"
#include <iostream>
#include <algorithm>

Document::Document(int docId) : id(docId) {
    std::cout << "Created document #" << id << std::endl;
}

void Document::addShape(std::unique_ptr<Shape> shape) {
    std::cout << "Added shape #" << shape->getId() 
              << " (" << shape->getType() << ") to document #" << id << std::endl;
    shapes.push_back(std::move(shape));
}

void Document::removeShape(int shapeId) {
    auto it = std::remove_if(shapes.begin(), shapes.end(),
        [shapeId](const std::unique_ptr<Shape>& s) { 
            return s->getId() == shapeId; 
        });
    
    if (it != shapes.end()) {
        std::cout << "Removed shape #" << shapeId << " from document #" << id << std::endl;
        shapes.erase(it, shapes.end());
    }
}
