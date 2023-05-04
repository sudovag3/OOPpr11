#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

template<typename T>
class Set
{
    std::set<T> data;
public:
    // 1) Добавление элемента в множество
    void add(const T& value)
    {
        data.insert(value);
    }

    // 2) Удаление элемента из множества
    void remove(const T& value)
    {
        data.erase(value);
    }

    // 3) Принадлежность элемента множеству
    bool contains(const T& value) const
    {
        return data.find(value) != data.end();
    }

    // 4) Пересечение множеств
    Set<T> intersection(const Set<T>& other) const
    {
        Set<T> result;
        std::set_intersection(data.begin(), data.end(), other.data.begin(), other.data.end(),
                              std::inserter(result.data, result.data.begin()));
        return result;
    }

    // 5) Объединение множеств
    Set<T> union_set(const Set<T>& other) const
    {
        Set<T> result;
        std::set_union(data.begin(), data.end(), other.data.begin(), other.data.end(),
                       std::inserter(result.data, result.data.begin()));
        return result;
    }

    // 6) Разность множеств
    Set<T> difference(const Set<T>& other) const
    {
        Set<T> result;
        
        //data.begin(), data.end() - первый диапазон
        //other.data.begin(), other.data.end()
        //std::inserter(result.data, result.data.begin()) - третий диапазон, представляющий новое множество result
        std::set_difference(data.begin(), data.end(), other.data.begin(), other.data.end(),
                            std::inserter(result.data, result.data.begin()));
        return result;
    }

    // Вывод множества
    void print() const
    {
        for (const T& value : data)
        {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    Set<int> a;
    a.add(1);
    a.add(2);
    a.add(3);

    Set<int> b;
    b.add(2);
    b.add(3);
    b.add(4);

    std::cout << "Set A: ";
    a.print();
    std::cout << "Set B: ";
    b.print();

    std::cout << "Intersection: ";
    a.intersection(b).print();

    std::cout << "Union: ";
    a.union_set(b).print();

    std::cout << "Difference (A - B): ";
    a.difference(b).print();

    return 0;
}
