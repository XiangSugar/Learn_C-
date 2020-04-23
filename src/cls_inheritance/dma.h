// dma.h -- inheritance and dynamic memory allocation
#ifndef DMA_H_
#define DMA_H_
#include <iostream>

// Base Class Using DMA
class baseDMA
{
private:
    char *label;
    int rating;

public:
    baseDMA(const char *l = "null", int r = 0);
    baseDMA(const baseDMA &rs);
    virtual ~baseDMA();
    // 赋值运算符不会被继承，但是派生类可以通过作用域解析运算符来调用（这个公有方法）
    baseDMA &operator=(const baseDMA &rs);
    //友元函数不会被继承，因为其不是类成员函数
    friend std::ostream &operator<<(std::ostream &os,
                                    const baseDMA &rs);
};

/*
子类赋值操作符会不会继承父类,那肯定是不会的.
1. 如果 子类没定义赋值操作符, 那么 子类会自动合成赋值操作符, 子类在赋值的时候会自动
   调用父类的赋值操作符来完成基类部分的复制拷贝.
2. 如果 子类自己定义了赋值操作符, 那么 子类就不会继续自动合成, 仍然子类必须手动调用
   父类的赋值操作符来完成基类部分的赋值拷贝,否则会造成部分复制( partial copy assignment )
*/

// derived class without DMA
// no destructor needed
// uses implicit copy constructor
// uses implicit assignment operator
class lacksDMA : public baseDMA
{
private:
    enum
    {
        COL_LEN = 40
    };
    char color[COL_LEN];

public:
    lacksDMA(const char *c = "blank", const char *l = "null",
             int r = 0);
    lacksDMA(const char *c, const baseDMA &rs);
    friend std::ostream &operator<<(std::ostream &os,
                                    const lacksDMA &rs);
};

// derived class with DMA
class hasDMA : public baseDMA
{
private:
    char *style;

public:
    hasDMA(const char *s = "none", const char *l = "null",
           int r = 0);
    hasDMA(const char *s, const baseDMA &rs);
    hasDMA(const hasDMA &hs);
    ~hasDMA();
    hasDMA &operator=(const hasDMA &rs);
    friend std::ostream &operator<<(std::ostream &os,
                                    const hasDMA &rs);
};
#endif
