#include <iostream>
#include <memory>

class CPointer
{
private:
    std::unique_ptr<int[]> data;
public:
    explicit CPointer(const int size);
    ~CPointer();
    void catAddress();
};

CPointer::CPointer(const int size)
{
    data = std::unique_ptr<int[]>(new int(100));
}

CPointer::~CPointer()
{
}

void CPointer::catAddress()
{
    std::cout << "data address: " << data.get() << std::endl;
}

int main(int argc, char* argv[])
{
    CPointer cpointer(100);
    cpointer.catAddress();
    return 0;
}
