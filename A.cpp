#include <iostream>
#include <vector>
#include <cmath>

class Heap {
public:
    Heap() {
        heap = std::vector<int64_t>(0);
        heap_size = 0;
    }

    void insert(int64_t n) {
        int64_t i, parent;
        i = heap_size;
        heap.push_back(0);
        heap[i] = n;
        parent = (i - 1) / 2;
        while(parent >= 0 && i > 0)  {
            if(heap[i] > heap[parent]) {
                std::swap(heap[i], heap[parent]);
            }
            i = parent;
            parent = (i - 1) / 2;
        }
        heap_size++;
    }

    int extract() {
        int64_t res;
        res = heap[0];
        heap[0] = heap[heap_size - 1];
        --heap_size;
        heapify(0);
        return(res);
    }

    void heapify(int64_t i) {
        int64_t left, right, max;
        left = 2 * i + 1;
        right = 2 * i + 2;
        if ((left < heap_size) && (heap[left] > heap[i])) {
            max = left;
        } else {
            max = i;
        }

        if ((right < heap_size) && (heap[right] > heap[max])) {
            max = right;
        }

        if (max != i) {
            std::swap(heap[i], heap[max]);
            heapify(max);
        }
        return;
    }

    ~Heap() = default;

private:
    std::vector<int64_t> heap;
    int64_t heap_size = 0;
};

int main() {
    int64_t commands_count, number;
    std::cin >> commands_count;
    int64_t command;
    Heap my_heap;
    for (int64_t i = 0; i < commands_count; ++i) {
        std::cin >> command;
        if (command == 0) {
            std::cin >> number;
            my_heap.insert(number);
        } else if (command == 1) {
            std::cout << my_heap.extract() << "\n";
        }
    }
}