#ifndef EDITOR_CONTROLLER_H
#define EDITOR_CONTROLLER_H

#include "Document.h"
#include <memory>
#include <string>

// Controller层 - 控制器
class EditorController {
private:
    std::unique_ptr<Document> currentDoc;
    int nextDocId;
    int nextShapeId;
    
public:
    EditorController();
    
    void createNewDocument();
    void importDocument(const std::string& path);
    void exportDocument(const std::string& path);
    void createShape(const std::string& type);
    void deleteShape(int shapeId);
};

#endif