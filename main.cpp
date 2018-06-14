// URL : https://beta.atcoder.jp/contests/abc099/tasks/abc099_c

#include <iostream>
class Bank {
    const size_t units[3] = {1, 3, 9};
    static constexpr size_t max_idx = 2;
    static constexpr size_t min_idx = 1;
    size_t remain;
    size_t counter[3] = {0, 0, 0};
public :
    Bank(size_t const N) : remain(N) {}
    bool Remained() {
        return remain < units[min_idx];
    }
    void AddCounter() {
        for (size_t i = max_idx; min_idx <= i; i++) {
            size_t const unit = units[i];
            size_t devided = remain;
            size_t current_pow = unit;
            bool filled = false;
            while (unit <= devided) {
                filled = true;
                devided /= unit;
            }
            counter[i] += devided;
            if (filled) return;
            remain -= (current_pow) * devided; 
        }
    }
    size_t GetSum() {
        size_t ret = remain;
        for (size_t i = min_idx; i <= max_idx; i++) ret +=  counter[i];
        return ret;
    }
};


int main() {
    size_t N;
    std::cin >> N;
    Bank bank(N);
    while (bank.Remained()) {
        bank.AddCounter();
    };
    
    std::cout << bank.GetSum() << std::endl;
}
