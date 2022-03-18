#ifndef SINGLETONT_H
#define SINGLETONT_H

#include "singleton_global.h"


#include <QMutex>
#include <QScopedPointer>

template <typename T>
class SingletonT
{
public:
    static T &getInstance(); // 获取单例的唯一实例对象

    SingletonT(const SingletonT &other) = delete;
    SingletonT<T> &operator=(const SingletonT &other) = delete;

private:
    static QMutex mutex;
    static QScopedPointer<T> instance;
};

/*-----------------------------------------------------------------------------|
 |                          SingletonT Implementation                           |
 |----------------------------------------------------------------------------*/
template <typename T> QMutex SingletonT<T>::mutex;
template <typename T> QScopedPointer<T> SingletonT<T>::instance;

template <typename T>
T &SingletonT<T>::getInstance()
{
    if (instance.isNull()) {
        mutex.lock();
        if (instance.isNull()) {
            instance.reset(new
                           T()); // 此指针会在全局变量作用域结束时自动 deleted (main 函数返回后)
        }
        mutex.unlock();
    }

    return *instance.data();
}

/*-----------------------------------------------------------------------------|
 |                               SingletonT Macro                               |
 |----------------------------------------------------------------------------*/
#define SINGLETONT(Class)                           \
private:                                           \
    Class();                                       \
    ~Class();                                      \
    Class(const Class &other) = delete;            \
    Class& operator=(const Class &other) = delete; \
    friend class  SingletonT<Class>;                \
    friend struct QScopedPointerDeleter<Class>;    \
                                                   \
public:                                            \
    static Class& instance() {                     \
        return SingletonT<Class>::getInstance();    \
    }


#endif // SINGLETONT_H
