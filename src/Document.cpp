#include "Document.h"
#include <iostream>
#include <algorithm>

Document::Document(int docId) : id(docId) {
    std::cout << "创建了" << id << "号文档" << std::endl;
}

void Document::addShape(std::unique_ptr<Shape> shape) {
    std::cout << "向" << id << "号文档中添加了" << shape->getId() 
              << "号" << shape->getType() << "图元" << std::endl;
    shapes.push_back(std::move(shape));
}

void Document::removeShape(int shapeId) {
    auto it = std::remove_if(shapes.begin(), shapes.end(),
        [shapeId](const std::unique_ptr<Shape>& s) { 
            return s->getId() == shapeId; 
        });
    
    if (it != shapes.end()) {
        std::cout << "从" << id << "号文档中删除了" << shapeId << "号图元" << std::endl;
        shapes.erase(it, shapes.end());
    }
}
