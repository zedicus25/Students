#include <iostream>
#include "c_Student.h"
int main()
{
    c_Student* st = new c_Student("JON");
    st->addMark(12);
    st->addMark(12);
    st->addMark(12);
    st->addMark(12);
    std::cout << st->info() << "\n";
}