#include <iostream>
#include <memory>

class CPointer
{
private:
    std::unique_ptr<int[]> data;
    int m_size;
public:
    explicit CPointer(const int size) : m_size(size) {}
    ~CPointer() 
    {

    }
    void cat();
    auto move_ptr() -> decltype(data);
};

void CPointer::cat()
{
    using namespace std;
    data = std::unique_ptr<int[]> (new int[m_size]);

    for (int i = 0; i < m_size; ++i)
    {
        data[i] = i;
        cout << "data[" << i << "]" << data[i] << endl;
    }
}

auto CPointer::move_ptr() -> decltype(data)
{
    return std::move(data);
}

int main(int argc, char* argv[])
{
    CPointer cpointer(100);
    cpointer.cat();
    auto ptr = cpointer.move_ptr();
    std::cout << "move之后" << std::endl << "new ptr[50]=" << ptr[50] << std::endl;
    return 0;
}
