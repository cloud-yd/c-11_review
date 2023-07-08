#include <iostream>
#include <memory>
#include <unistd.h>

class CUniquePtr
{
private:
    std::unique_ptr<int[]> data;
    int m_size;
public:
    explicit CUniquePtr(const int size) : m_size(size) {}
    ~CUniquePtr() {}
    
    void cat();
    auto move_ptr() -> decltype(data);
};

void CUniquePtr::cat()
{
    using namespace std;
    data = std::unique_ptr<int[]> (new int[m_size]);

    for (int i = 0; i < m_size; ++i)
    {
        data[i] = i;
        cout << "data[" << i << "]" << data[i] << endl;
    }
}

auto CUniquePtr::move_ptr() -> decltype(data)
{
    return std::move(data);
}

class CTest
{
private:
    std::string m_str;
public:
    CTest(std::string str) : m_str(str){}
    ~CTest();

    void output();
    void output2(std::string _str, std::string _str2) 
    {
        m_str = _str2;
        std::cout << _str << std::endl;
    }
};

CTest::~CTest()
{
    std::cout << "我被析构了" << std::endl;
}

void CTest::output()
{
    std::cout << m_str << std::endl;
}

void setInfo_unique(std::unique_ptr<CTest>& ptr)
{
    ptr->output2("unique_ptr传参", "unique修改成功");
}

void setInfo_shared(std::shared_ptr<CTest>& ptr)
{
    ptr->output2("shared_ptr传参", "shared修改成功");
}

void smart_pointer()
{
    //unique_ptr
    std::unique_ptr<CTest> uTestPtr = std::unique_ptr<CTest>(new CTest("这是C++11的unique_ptr, 目前不支持make_unique"));
    uTestPtr->output();
    setInfo_unique(uTestPtr);
    uTestPtr->output();
    std::cout << "----------------------" << std::endl;
    
    //shared_ptr
    std::shared_ptr<CTest> testPtr = std::make_shared<CTest>("这是智能指针");
    testPtr->output();
    std::cout << "shared 计数：" << testPtr.use_count() << std::endl;
    setInfo_shared(testPtr);
    testPtr->output();
    std::cout << "shared 计数：" << testPtr.use_count() << std::endl;
}

void raw_poniter()
{
    CTest* pTest = new CTest("这是原始指针");
    pTest->output();
    //虽然是局部变量，但是使用new申请的内存在堆中
    //函数结束也不会被释放
    delete pTest;
}

int main(int argc, char* argv[])
{
    CUniquePtr cpointer(100);
    cpointer.cat();
    auto ptr = cpointer.move_ptr();
    std::cout << "move之后" << std::endl << "new ptr[50]=" << ptr[50] << std::endl;

    std::cout << "===========" << std::endl;

    smart_pointer();
    std::cout << "===========" << std::endl;
    raw_poniter();

    std::cout << "===========" << std::endl;


    std::cout << "程序结束" << std::endl;

    return 0;
}
