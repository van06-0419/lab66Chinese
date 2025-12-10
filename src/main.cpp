#include "EditorView.h"
#include <iostream>
#include <memory>

int main() {
    std::cout << "=== 图形编辑器架构演示 ===" << std::endl;
    
    // 创建MVC组件
    auto controller = std::make_shared<EditorController>();
    auto view = std::make_unique<EditorView>(controller);
    
    // 演示功能1: 新建文档
    view->onNewDocument();
    
    // 演示功能2: 创建图形
    view->onCreateShape("rectangle");
    view->onCreateShape("circle");
    view->onCreateShape("rectangle");
    
    // 演示功能3: 删除图形
    view->onDeleteShape(2);
    
    // 演示功能4: 导出文档
    view->onExport("output.svg");
    
    // 演示功能5: 从文件导入
    view->onImport("input.svg");
    view->onCreateShape("circle");
    
    std::cout << "\n=== 演示完成 ===" << std::endl;
    return 0;
}