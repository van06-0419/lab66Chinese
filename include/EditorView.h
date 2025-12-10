#ifndef EDITOR_VIEW_H
#define EDITOR_VIEW_H

#include "EditorController.h"
#include <memory>

// View层 - 视图(模拟GUI)
class EditorView {
private:
    std::shared_ptr<EditorController> controller;
    
public:
    explicit EditorView(std::shared_ptr<EditorController> ctrl);
    
    void onNewDocument();
    void onImport(const std::string& path);
    void onExport(const std::string& path);
    void onCreateShape(const std::string& type);
    void onDeleteShape(int id);
};

#endif