#include <iostream>
#include "student.h"
#include "StudentAfterFirstSession.h"
#include "StudentAfterSecondSession.h"

int main()
{
    int a[4] = { 6, 8, 7, 10 }, b[4] = { 4, 9, 8, 8 }, c[4] = {6, 7, 5, 6};
    int d[5] = { 5, 8, 6, 9, 4 }, e[5] = { 9, 6, 8, 4, 7 }, f[5] = { 6, 6, 6, 8, 9 };
    StudentAfterFirstSession* class1[3] = {  new StudentAfterFirstSession("Maxim Malcev", 1, 1, 3453276, a),
                                             new StudentAfterFirstSession("Pavel Shevchuk", 1, 1, 6346363, b),
                                             new StudentAfterFirstSession("Sergei Kovalev", 1, 1, 9075382, c) };
    std::cout << "first group:\n" << *class1[0] << '\n' << *class1[1] << '\n' << *class1[2] << "\naverage score of the group: " <<
              (class1[0]->getAverageScore() + class1[1]->getAverageScore() + class1[2]->getAverageScore()) / 3 << '\n';

    StudentAfterSecondSession* class2[3] = { new StudentAfterSecondSession("Dritry Ivanov", 1, 2, 3345376, a, d),
                                             new StudentAfterSecondSession("Aleksey Pushkin", 1, 2, 1235253, b, e),
                                             new StudentAfterSecondSession("Daria Golybeva", 1, 2, 9398452, c, f) };
    std::cout << "second group:\n" << *class2[0] << '\n' << *class2[1] << '\n' << *class2[2] << "\naverage score of the group: " <<
              (class2[0]->getAverageScore() + class2[1]->getAverageScore() + class2[2]->getAverageScore()) / 3 << '\n';
}
