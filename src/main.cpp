#include "bidir_list.h"

int main() {
    BidirList<int> l;
    int n = 5;
    for (int i = 0; i < n; i++) {
        int el = 0;
        std::cout << "> " << std::endl;
        std::cin >> el;
        l.AddNodeToBegin(el);
    }

    l.PrintList();
    return 0;
}
