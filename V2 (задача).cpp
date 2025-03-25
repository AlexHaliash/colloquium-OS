#include <iostream>
#include <vector>
#include <unordered_set>
#include <stdexcept>
#include <cassert>

// Функция для удаления дубликатов из контейнера
std::vector<int> removeDuplicates(const std::vector<int>& input) {
    std::unordered_set<int> seen;
    std::vector<int> output;

    for (int num : input) {
        if (seen.find(num) == seen.end()) {
            seen.insert(num);
            output.push_back(num);
        }
    }
    return output;
}

// Юнит-тесты
void testRemoveDuplicates() {
    // Тест 1: Проверка удаления дубликатов
    std::vector<int> input = {1, 2, 2, 3, 4, 4, 5};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    std::vector<int> result = removeDuplicates(input);
    assert(result == expected);

    // Тест 2: Проверка пустого контейнера
    std::vector<int> emptyInput = {};
    std::vector<int> emptyExpected = {};
    assert(removeDuplicates(emptyInput) == emptyExpected);

    // Тест 3: Проверка контейнера без дубликатов
    std::vector<int> noDuplicates = {1, 2, 3, 4, 5};
    assert(removeDuplicates(noDuplicates) == noDuplicates);
}

int main() {
    testRemoveDuplicates();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
