#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <memory>

// 定义抽象基类Shape（图形）
// 作为所有具体图形类（矩形、圆形等）的基类，定义通用接口
class Shape {
protected:
    // 图形的唯一标识ID，protected修饰使其可被派生类访问
    int id;
    
public:
    // 显式构造函数：创建图形对象时必须指定ID
    // 初始化列表直接初始化基类的id成员，符合C++高效初始化原则
    explicit Shape(int shapeId) : id(shapeId) {}
    
    // 虚析构函数：设为默认实现（=default）
    // 基类声明虚析构函数是为了保证删除派生类对象时，能正确调用派生类析构函数
    // =default表示使用编译器生成的默认析构逻辑，简洁且高效
    virtual ~Shape() = default;
    
    // 获取图形ID的常量成员函数
    // const修饰保证函数不修改对象状态，可被const对象调用
    int getId() const { return id; }
    
    // 纯虚函数：获取图形类型名称
    // =0表示该函数无基类实现，强制派生类必须重写此函数
    // 使Shape成为抽象类，无法直接实例化，只能作为基类使用
    virtual std::string getType() const = 0;
};

// 定义矩形类：公有继承自Shape抽象基类
// 实现Shape的纯虚函数，成为可实例化的具体类
class Rectangle : public Shape {
public:
    // 显式构造函数：接收ID参数，通过初始化列表传递给基类Shape的构造函数
    explicit Rectangle(int id) : Shape(id) {}
    
    // 重写（override）基类的纯虚函数getType
    // override关键字明确表示重写基类虚函数，编译器会检查匹配性，避免拼写/签名错误
    // 返回该图形的具体类型名称"Rectangle"
    std::string getType() const override { return "Rectangle"; }
};

// 定义圆形类：公有继承自Shape抽象基类
class Circle : public Shape {
public:
    // 显式构造函数：将ID传递给基类Shape的构造函数初始化
    explicit Circle(int id) : Shape(id) {}
    
    // 重写基类纯虚函数，返回圆形的类型名称"Circle"
    // override关键字确保函数签名与基类一致，增强代码可读性和安全性
    std::string getType() const override { return "Circle"; }
};

// 头文件卫士结束标记
#endif
