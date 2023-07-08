#include <iostream>

template <typename T>
T m_max(T t)
{
    return ++t;
}

template <typename T1, typename T2>
auto m_add(T1 x, T2 y) -> decltype(x+y)
{
    return x + y;
}

template <typename T>
class CPerson
{
private:
    T m_age;
    T m_height;
public:
    explicit CPerson(T age, T height) : m_age(age), m_height(height) {};
    ~CPerson();

    void getInfo();
};
 
template <typename T>
CPerson<T>::~CPerson()
{
}

template <typename T>
void CPerson<T>::getInfo()
{
    std::cout << "age: " << m_age << std::endl;
    std::cout << "height: " << m_height << std::endl;
}

void print_yd(){}

template <typename T, typename... _args>
T print_yd(T value, _args... args)
{
    std::cout << value;
    print_yd(args...);
    return value;
}

int main(int argc, char* argv[])
{
    using namespace std;

    auto ret = m_max(10);
    cout << "this is C++" << ret << endl;

    auto ret2 = m_add(1.12, 2);
    cout << "ret2 = " << ret2 << endl;
    
    cout << "类模板：" << endl;
    CPerson<int> boy(18, 185);
    boy.getInfo();

    CPerson<double> girl(17.5, 167.5);
    girl.getInfo();

    cout << "可变参数模板" << endl;
    print_yd("这是", "C++", 11, "的", "魅力", 2023, "-", 07, "-", 07, "可变参数模板的学习");
    cout << endl;

    return 0;
}