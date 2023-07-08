#include <iostream>
#include <memory>

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

int main(int argc, char* argv[])
{
    CUniquePtr cpointer(100);
    cpointer.cat();
    auto ptr = cpointer.move_ptr();
    std::cout << "move之后" << std::endl << "new ptr[50]=" << ptr[50] << std::endl;
    return 0;
}
