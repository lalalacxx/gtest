#include <iostream>
int Abs(int x)
{
    return x>0 ? x : -x;
}



#include<gtest/gtest.h>

//C语言中的assert如果断言失败，结果是什么样子的？
//程序崩溃，，进程异常终止，，，最好的回答：怎么样导致程序异常终止
TEST(TestAbs,TestAbs)
{
    //致命断言：一旦断言失败当前的TEST宏中剩余的代码将不再继续执行
    //如果某些前提操作无法满足从而导致后续工作无法继续进行则使用致命断言


    //基础断言（ASSERT_TRUE\ASSET_FALSE）
    ASSERT_TRUE(Abs(10) == 10) << "Abs(10) = "<<Abs(10);//断言失败才打印
    ASSERT_TRUE(Abs(-10) == 10);

    //双目比较（ASSERT_EQ\NE\LT\LE\GT\GE）
    ASSERT_EQ(Abs(-10),10);//有两个参数，判断这两个参数是否相等
    
    ASSERT_TRUE(Abs(0) == 0);

    
    //非致命断言：断言失败以后剩余的代码会依旧执行下去
    //当前的操作对后续工作的影响不大则使用非致命断言
    EXPECT_EQ(Abs(10),10);
    std::cout<<"非致命断言"<<std::endl;
}
