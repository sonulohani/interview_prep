// Binary search works only with sorted arrays. The time complexity of above algorithm is O(n).

#include <iostream>
#include <vector>

#define DEADBEEF 3735928559

int binary_search(const std::vector<int> &vec, const int number_to_search, int left, int right)
{
    if (right >= left)
    {
        int mid = (left + (right - 1)) / 2;

        if (vec[mid] == number_to_search)
            return mid;

        if (vec[mid] > number_to_search)
        {
            return binary_search(vec, number_to_search, left, mid - 1);
        }
        return binary_search(vec, number_to_search, mid + 1, right);
    }
    return DEADBEEF;
}

int main()
{
    int size;

    std::cout << "Enter the size of array: ";
    std::cin >> size;

    std::cout << '\n';

    std::vector<int> elems;
    elems.reserve(size);

    for (int i = 0; i < size; i++)
    {
        int inp;
        std::cin >> inp;
        elems.emplace_back(inp);
    }

    int number_to_search;

    std::cout << "Enter the number to search: ";
    std::cin >> number_to_search;

    auto index = binary_search(elems, number_to_search, 0, elems.size() - 1);

    if (index == DEADBEEF)
    {
        std::cout << "Number is not found in the list\n";
    }
    else
    {
        std::cout << "Number is found at index " << index;
    }
}