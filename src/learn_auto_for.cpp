#include <iostream>
#include <vector>
#include <map>
#include "public.h"

class CTest
{
private:
    int array[5] = {1, 2, 3, 4, 5};
    std::vector<std::string> vec = {"hello", "C++", "11", "auto", "for"};
    std::map<int, std::string> m_map;
    using map_pair = std::map<int, std::string>::value_type;
public:
    explicit CTest(std::initializer_list<map_pair> init_list);
    ~CTest();

    void change();
    void output();
};

CTest::CTest(std::initializer_list<map_pair> init_list)
{
    std::cout << "array: " << std::endl;
    for(int a : array)
    {
        std::cout << a;
    }
    std::cout << std::endl;

    std::cout << "vector: " << std::endl;
    for(auto x : vec)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    std::cout << "初始化m_map" << std::endl;
    for (auto it : init_list)
    {
        m_map.insert(it);
    }
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

    for (auto it : m_map)
    {
        std::cout << "{" << it.first << ", " << it.second << "}" << std::endl;
    }
}


int main(int argc, char* argv[])
{
    CTest test {{1, "C++"}, {2, "11"}, {3, "真的"}, {4, "好玩"}};
    test.change();
    test.output();

    using namespace CPP;

    for (int i = 0; i <= static_cast<int>(m_enum::max); i++)
    {
        switch (i)
        {
        case static_cast<int>(m_enum::min):
            std::cout << "enum class: " << i << "; ";
            break;
        case static_cast<int>(m_enum::medium):
            std::cout << "enum class: " << i << "; ";
            break;
        case static_cast<int>(m_enum::max):
            std::cout << "enum class: " << i << "; ";
            break;

        default:
            break;
        }
    }

    std::cout << std::endl;

    return 0;
}