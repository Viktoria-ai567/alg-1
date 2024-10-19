#include <iostream>
#include <fstream>
#include <vector>
int main() {
    // Создаем три вектора: vec1, vec2 и sum_vec
    std::vector<int> vec1, vec2, sum_vec;
    int n;

 // Открываем первый файл
    std::ifstream file1("file1.txt");
    if (file1.is_open()) {
        // Считываем количество элементов
        file1 >> n;

        // Считываем и добавляем элементы в вектор vec1
        for (int i = 0; i < n; i++) {
            int x;
            file1 >> x;
            vec1.push_back(x);
        }

        // Закрываем файл
        file1.close();
    } else {
        std::cout << "The file could not be opened file1.txt" << std::endl;
        return 1;
    }

    // Чтение данных из второго файла
    std::ifstream file2("file2.txt");
    if (file2.is_open()) {
        // Считываем количество элементов во втором файле
        file2 >> n;
        // Считываем элементы и добавляем их в вектор vec2
        for (int i = 0; i < n; i++) {
            int x;
            file2 >> x;
            vec2.push_back(x);
        }
        file2.close();
    } else {
        std::cout << "The file could not be opened file2.txt" << std::endl;
        return 1;
    }
    // Вычисление суммы векторов
    if (vec1.size() == vec2.size()) {
        // Складываем соответствующие элементы vec1 и vec2 и добавляем результат в sum_vec
        for (int i = 0; i < vec1.size(); i++) {
            sum_vec.push_back(vec1[i] + vec2[i]);
        }
        // Вывод результата
        std::cout << "Sum of the vectors: ";
        for (int x : sum_vec) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Vectors have different lengths, addition is impossible" << std::endl;
    }
    return 0;
}