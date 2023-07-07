#include <iostream>
#include <vector>

class CTest
{
private:
    int array[5] = {1, 2, 3, 4, 5};
    std::vector<std::string> vec = {"hello", "C++", "11", "auto", "for"};
public:
    explicit CTest(/* args */);
    ~CTest();

    void change();
    void output();
};

CTest::CTest(/* args */)
{
    std::cout << "array: " << std::endl;
    for(int a : array)
    {
        std::cout << a << std::endl;
    }

    std::cout << "vector: " << std::endl;
    for(auto x : vec)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

CTest::~CTest()
{
}

void CTest::change()
{
    std::cout << "修改vector中的元素: " << std::endl;
    for (auto &x : vec)
    {
        x += std::string("_yangd");
    }
}

void CTest::output()
{
    for (auto x : vec)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}


int main(int argc, char* argv[])
{
    CTest test;
    test.change();
    test.output();
    return 0;
}