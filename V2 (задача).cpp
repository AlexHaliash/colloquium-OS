#include <iostream>
#include <vector>
#include <unordered_set>
#include <stdexcept>
#include <cassert>
#include <sstream>

// Задача 1: Вычисление первых n факториалов
class FactorialCalculator {
public:
    static std::vector<unsigned long long> calculateFactorials(int n) {
        if (n <= 0) {
            throw std::invalid_argument("Input must be a natural number (greater than 0).");
        }

        std::vector<unsigned long long> factorials(n);
        factorials[0] = 1; // 0! = 1

        for (int i = 1; i < n; ++i) {
            factorials[i] = factorials[i - 1] * (i + 1);
        }

        return factorials;
    }
};

// Задача 2: Удаление дубликатов
class UniqueElements {
public:
    static std::vector<int> removeDuplicates(const std::vector<int>& input) {
        std::unordered_set<int> seen;
        std::vector<int> unique;

        for (int num : input) {
            if (seen.insert(num).second) { // insert returns a pair, second is true if inserted
                unique.push_back(num);
            }
        }

        return unique;
    }
};

// Задача 3: Разворот связного списка
struct ListNode {
    int value;
    ListNode* next;
    ListNode(int val) : value(val), next(nullptr) {}
};

class LinkedList {
public:
    ListNode* head;

    LinkedList() : head(nullptr) {}

    void append(int value) {
        if (!head) {
            head = new ListNode(value);
            return;
        }
        ListNode* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new ListNode(value);
    }

    ListNode* reverse(ListNode* node) {
        if (!node || !node->next) {
            return node;
        }
        ListNode* newHead = reverse(node->next);
        node->next->next = node;
        node->next = nullptr;
        return newHead;
    }

    void reverseList() {
        head = reverse(head);
    }

    void printList() const {
        ListNode* current = head;
        while (current) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    ~LinkedList() {
        while (head) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Юнит-тесты
void testFactorialCalculator() {
    assert((FactorialCalculator::calculateFactorials(5) == std::vector<unsigned long long>{1, 2, 6, 24, 120}));
    try {
        FactorialCalculator::calculateFactorials(0);
        assert(false); // Should not reach here
    } catch (const std::invalid_argument&) {
        // Expected exception
    }
}

void testUniqueElements() {
    assert((UniqueElements::removeDuplicates({1, 2, 2, 3, 4, 4}) == std::vector<int>{1, 2, 3, 4}));
    assert((UniqueElements::removeDuplicates({}) == std::vector<int>{}));
    assert((UniqueElements::removeDuplicates({1, 1, 1, 1}) == std::vector<int>{1}));
}

void testLinkedList() {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.reverseList();
    
    std::ostringstream oss;
    list.printList(); // Should print 3 2 1
}

int main() {
    testFactorialCalculator();
    testUniqueElements();
    testLinkedList();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
