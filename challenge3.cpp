#include <forward_list>
#include <iostream>

int recursive_sum_helper(
    std::forward_list<int> sll,
    int total,
    std::forward_list<int>::iterator iter)
{
    // base
    if (iter == sll.end())
    {
        return total;
    }
    // visit
    total += *iter;
    // recursion
    return recursive_sum_helper(sll, total, ++iter);
}

int recursive_sum(std::forward_list<int> sll)
{
    int total = 0;
    auto iter = sll.begin();

    return recursive_sum_helper(sll, total, iter);
}

int main()
{
    std::forward_list<int> container = {1, 2, 3};

    std::cout << recursive_sum(container) << std::endl;

    return 0;
}