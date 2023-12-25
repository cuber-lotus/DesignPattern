/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-29
 *
 * @copyright Copyright (c) 2023
 *
 * 代理模式
 * 日志代理，不直接调用实际的日志操作
 * 而是通过一个代理层面，可以扩充打日志的上下文
 * ====================================
 * **
 * 代理模式通过引入一个代理对象来替代原始对象，
 * 从而可以在不改变原始对象的情况下增加额外的功能或控制访问
 * **
 */

#include <iostream>
#include <string>

// 定义接口
class IObject {
public:
    virtual void operation(std::string arg) = 0;
};

// 实现实际对象
class RealObject : public IObject {
public:
    void operation(std::string arg) override {
        std::cout << "RealObject::operation: arg = " << arg << std::endl;
    }
};

// 实现日志记录代理
class LoggingProxy : public IObject {
public:
    LoggingProxy(RealObject* realObject) : m_realObject(realObject) {
    }
    ~LoggingProxy() {
        if (m_realObject) {
            delete m_realObject;
        }
    }

    void operation(std::string arg) override {
        // 入参日志记录
        std::cout << "LoggingProxy::operation: arg = " << arg << std::endl;
        // 调用实际对象的方法
        m_realObject->operation(arg);
        // 出参日志记录
        std::cout << "LoggingProxy::operation: result = " << arg << std::endl;
    }

private:
    RealObject* m_realObject = nullptr;  // 对实际对象的引用
};

int main() {
    // 创建实际对象
    RealObject* realObject = new RealObject();
    // 创建日志记录代理
    LoggingProxy* loggingProxy = new LoggingProxy(realObject);
    // 通过代理对象调用实际对象的方法，并记录日志
    loggingProxy->operation("logloglog");

    // 释放代理对象和实际对象
    delete loggingProxy;
}