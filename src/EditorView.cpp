#include "EditorView.h"
#include <iostream>

EditorView::EditorView(std::shared_ptr<EditorController> ctrl) 
    : controller(ctrl) {}

void EditorView::onNewDocument() {
    std::cout << "[GUI] 用户点击'新建文档'" << std::endl;
    controller->createNewDocument();
}

void EditorView::onImport(const std::string& path) {
    std::cout << "[GUI] 用户点击'导入文档'" << std::endl;
    controller->importDocument(path);
}

void EditorView::onExport(const std::string& path) {
    std::cout << "[GUI] 用户点击'导出文档'" << std::endl;
    controller->exportDocument(path);
}

void EditorView::onCreateShape(const std::string& type) {
    std::cout << "[GUI] 用户创建" << type << std::endl;
    controller->createShape(type);
}

void EditorView::onDeleteShape(int id) {
    std::cout << "[GUI] 用户删除图元" << id << std::endl;
    controller->deleteShape(id);
}
