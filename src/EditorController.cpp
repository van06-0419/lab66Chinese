#include "EditorController.h"
#include <iostream>

EditorController::EditorController() : nextDocId(1), nextShapeId(1) {}

void EditorController::createNewDocument() {
    currentDoc = std::make_unique<Document>(nextDocId++);
}

void EditorController::importDocument(const std::string& path) {
    std::cout << "从文件导入文档: " << path << std::endl;
    currentDoc = std::make_unique<Document>(nextDocId++);
}

void EditorController::exportDocument(const std::string& path) {
    if (currentDoc) {
        std::cout << "将" << currentDoc->getId() << "号文档导出到文件: " 
                  << path << std::endl;
    }
}

void EditorController::createShape(const std::string& type) {
    if (!currentDoc) return;
    
    std::unique_ptr<Shape> shape;
    if (type == "rectangle") {
        shape = std::make_unique<Rectangle>(nextShapeId++);
    } else if (type == "circle") {
        shape = std::make_unique<Circle>(nextShapeId++);
    }
    
    if (shape) {
        currentDoc->addShape(std::move(shape));
    }
}

void EditorController::deleteShape(int shapeId) {
    if (currentDoc) {
        currentDoc->removeShape(shapeId);
    }
}
