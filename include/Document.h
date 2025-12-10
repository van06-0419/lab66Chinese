// 防止头文件重复包含的保护机制（头文件卫士）
// 当第一次包含该头文件时，DOCUMENT_H未定义，会定义它并包含后续内容
// 后续重复包含时，由于DOCUMENT_H已定义，会跳过中间内容，避免重复定义错误
#ifndef DOCUMENT_H
#define DOCUMENT_H

// 包含Shape类的头文件，因为Document类中使用了Shape类型
// Shape应该是一个基类（抽象类），定义了图形的通用接口
#include "Shape.h"

// 包含vector容器头文件，用于存储多个图形对象
#include <vector>
// 包含智能指针头文件，使用unique_ptr管理Shape对象的内存
#include <memory>

// 定义Document类，用于管理一组图形（Shape）对象
// 职责：维护文档ID、管理图形对象的增删
class Document {
private:
    // 文档的唯一标识ID，用于区分不同的文档
    int id;
    
    // 存储图形对象的容器：
    // 1. vector：动态数组，支持高效的遍历和随机访问
    // 2. unique_ptr<Shape>：独占式智能指针，确保每个Shape对象只有一个所有者
    //    避免内存泄漏，自动释放资源，同时支持多态（指向Shape子类对象）
    std::vector<std::unique_ptr<Shape>> shapes;
    
public:
    // 显式构造函数：创建Document对象时必须指定文档ID
    // explicit关键字防止隐式类型转换（避免int自动转为Document）
    explicit Document(int docId);
    
    // 常量成员函数：获取文档ID
    // const修饰：保证函数不会修改对象的成员变量，可被const对象调用
    // 内联函数（直接在类内定义）：提高访问效率
    int getId() const { return id; }
    
    // 成员函数：添加图形到文档中
    // 参数：unique_ptr<Shape> shape - 转移图形对象的所有权到文档
    void addShape(std::unique_ptr<Shape> shape);
    
    // 成员函数：从文档中移除指定ID的图形
    // 参数：int shapeId - 要移除的图形的唯一标识
    void removeShape(int shapeId);
};

// 头文件卫士结束标记
#endif
