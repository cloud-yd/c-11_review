#include <iostream>
#include <memory>

class CB;
class CC;

class CA
{
private:
    std::weak_ptr<CB> a_b;
    std::weak_ptr<CC> a_c;
public:
    CA(/* args */) {}
    ~CA() {std::cout << "CA被析构了" << std::endl;}

    void set_b_c(std::shared_ptr<CB>& b, std::shared_ptr<CC>& c)
    {
        a_b = b;
        a_c = c;
    }

    void print_b();
    void print_c();

};

class CB
{
private:
    std::shared_ptr<CA> b_a;
public:
    CB(std::shared_ptr<CA>& a) : b_a(a) {}
    ~CB(){std::cout << "CB被析构了" << std::endl;}

    void print() {std::cout << "this is B print" << std::endl;}
};

class CC
{
private:
    std::shared_ptr<CA> c_a;
public:
    CC(std::shared_ptr<CA>& a) : c_a(a) {}
    ~CC(){std::cout << "CC被析构了" << std::endl;}

    void print() {std::cout << "this is C print" << std::endl;}
};

void CA::print_b()
{
    auto b = a_b.lock();
    b->print();
}

void CA::print_c()
{
    auto c = a_c.lock();
    c->print();
}

std::shared_ptr<CB> _b;
std::shared_ptr<CC> _c;

int main (int argc, char* argv[])
{
    std::shared_ptr<CA> _a = std::make_shared<CA>();
    _b = std::make_shared<CB>(_a);
    _c = std::make_shared<CC>(_a);

    _a->set_b_c(_b, _c);
    _a->print_b();
    _a->print_c();

    //测试引用计数
    // _b.reset();
    // _c.reset();

    std::cout << "A use_cout: " << _a.use_count() << std::endl;
    std::cout << "B use_cout: " << _b.use_count() << std::endl;
    std::cout << "C use_cout: " << _c.use_count() << std::endl;

    return 0;
}



