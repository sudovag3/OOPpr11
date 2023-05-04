#include <iostream>
#include <algorithm>

template<typename T, std::size_t N>
class MyArray
{
    T arr[N]; 
public:
    MyArray(const T &t = T())
    {
        for(std::size_t i=0; i<N; i++)
            arr[i] = t;
    }

    size_t getSize() const
    {
        return N;
    }

    const T& operator[](std::size_t i) const
    {
        if (i<N)
            return arr[i];
    }
    
    T& operator[](std::size_t i)
    {
        if (i<N)
            return arr[i];
    }

    // Шаблонный оператор присваивания для копирования содержимого другого массива obj в текущий объект класса MyArray<T, N>
    template<typename T1, std::size_t N1>
    MyArray<T, N>& operator=(const MyArray<T1, N1>& obj)
    {
        // Определение минимального размера для копирования
        const std::size_t min_size = std::min(N, N1);
        // Копирование элементов другого массива в текущий массив
        for (std::size_t i = 0; i < min_size; i++) {
            arr[i] = static_cast<T>(obj[i]);
        }
        
        // Заполнить оставшиеся элементы значениями по умолчанию
        for (std::size_t i = min_size; i < N; i++) {
            arr[i] = T();
        }
        
        return *this;
    }
};

int main()
{
    MyArray<int, 10> c(2);
    MyArray<double, 5> d(3.0);

    c = d;

    std::cout << "c[2] = " << c[2] << std::endl;
    return 0;
}
