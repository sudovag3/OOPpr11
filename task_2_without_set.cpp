#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
class Set
{
    std::vector<T> data;
public:
    // 1) Добавление элемента в множество
    void add(const T& value)
    {
        if (!contains(value))
        {
            data.push_back(value);
        }
    }

    // 2) Удаление элемента из множества
    void remove(const T& value)
    {
        auto it = std::find(data.begin(), data.end(), value);
        if (it != data.end())
        {
            data.erase(it);
        }
    }

    // 3) Принадлежность элемента множеству
    bool contains(const T& value) const
    {
        return std::find(data.begin(), data.end(), value) != data.end();
    }

    // 4) Пересечение множеств
    Set<T> intersection(const Set<T>& other) const
    {
        Set<T> result;
        for (const T& value : data)
        {
            if (other.contains(value))
            {
                result.add(value);
            }
        }
        return result;
    }

    // 5) Объединение множеств
    Set<T> union_set(const Set<T>& other) const
    {
        Set<T> result = *this;
        for (const T& value : other.data)
        {
            result.add(value);
        }
        return result;
    }

    // 6) Разность множеств
    Set<T> difference(const Set<T>& other) const
    {
        Set<T> result;
        for (const T& value : data)
        {
            if (!other.contains(value))
            {
                result.add(value);
            }
        }
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
