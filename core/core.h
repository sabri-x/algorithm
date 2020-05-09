#ifndef CORE_H
#define CORE_H

#include "core_global.h"

class CORE_EXPORT Core
{
public:
    Core();
    void Test();
    
    /*! 字符串匹配的Boyer-Moore算法 测试
     */
    void BoyerMoreTest();
    
    /*! 排序算法 -测试
     */
    void sortTest();
};

#endif // CORE_H
