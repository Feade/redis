//
// Created by admin on 2018/1/5.
//
#pragma once
#include <assert.h>
#include <memory>
namespace redis {
// 要想使用共享指针就要继承这个类。内置类型使用不了
class SharedBase {
    template<typename T> friend
    class SharedPtr;
 public:
    typedef SharedBase BaseType;
    SharedBase() : count(0) {}
 private:
    void AddCount() { ++count; }
    void DecCount() { --count; }
    int Count() { return count; }
    int count;
};

template<typename T>
class SharedPtr {
 public:
    explicit SharedPtr(T *ptr = nullptr) { SetPoint(ptr); }

    SharedPtr(const SharedPtr &p) { SetPoint(p.pointer_); }

    SharedPtr &operator=(const SharedPtr &shared_ptr) {
        ClearPoint();
        SetPoint(shared_ptr.pointer_);
        return *this;
    }

    ~SharedPtr() {
        ClearPoint();
    }

    void Reset(T *ptr) {
        ClearPoint();
        SetPoint(ptr);
    }

    int Count() { return pointer_ ? pointer_->Count() : 0; }
    T *operator->() const { return pointer_; }
    T &operator*() const { return *pointer_; }
    explicit operator bool() const { return pointer_ != nullptr; }
 private:
    void ClearPoint() {
        if (pointer_ == nullptr) {
            return;
        }
        pointer_->DecCount();
        if (pointer_->Count() <= 0) {
            delete pointer_;
            pointer_ = nullptr;
        }
    }

    void SetPoint(T *ptr) {
        pointer_ = ptr;
        if (pointer_) {
            pointer_->AddCount();
        }
    }

    T *pointer_;
};

template<typename T, typename ...Args>
SharedPtr<T> MakeShared(Args &&...args) {
    assert(typeid(typename T::BaseType) == typeid(SharedBase));
    T *ret = new T(std::forward<Args>(args)...);
    return SharedPtr<T>(ret);
}

} // namespace redis
