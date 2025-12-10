#include "EditorView.h"
#include <iostream>

EditorView::EditorView(std::shared_ptr<EditorController> ctrl) 
    : controller(ctrl) {}

void EditorView::onNewDocument() {
    std::cout << "[GUI] User clicked 'New Document'" << std::endl;
    controller->createNewDocument();
}

void EditorView::onImport(const std::string& path) {
    std::cout << "[GUI] User clicked 'Import Document'" << std::endl;
    controller->importDocument(path);
}

void EditorView::onExport(const std::string& path) {
    std::cout << "[GUI] User clicked 'Export Document'" << std::endl;
    controller->exportDocument(path);
}

void EditorView::onCreateShape(const std::string& type) {
    std::cout << "[GUI] User created shape: " << type << std::endl;
    controller->createShape(type);
}

void EditorView::onDeleteShape(int id) {
    std::cout << "[GUI] User deleted shape #" << id << std::endl;
    controller->deleteShape(id);
}
