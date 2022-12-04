#include "bidir_list.h"

int main() {
   BidirList<int> l;
    int n = 5;
    for (int i = 0; i < n; i++) {
        int el = 0;
        std::cout << "> " << std::endl;
        std::cin >> el;
        l.AddNodeToEnd(el);
    }

   // l.PrintList();
     for(BidirList<int>::Iterator it = l.begin(); it != l.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;


  //  l.ClearList();
  //  std::cout << "clear";
  //  if (l.IsNoEmpty()) {
  //       l.PrintList();
 //  for(BidirList<int>::Iterator it = l.begin(); it != l.end(); ++it) {
 //           std::cout << *it << " ";
 //       }
 //       std::cout << std::endl;
 //   }
    

 //   std::cout << l.GetNode(2) << std::endl;
 //   l.SetNode(8,2);        
 //
    int s = 0;
    for(BidirList<int>::Iterator it = l.begin(); it != l.end(); ++it) {
        if (s==3) {
            l.InsertNodeTo(55, it);
            //l.end()++;
        }
        s++;    
    
    }


    for(BidirList<int>::Iterator it = l.begin(); it != l.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

 //   l.AddNodeToBegin(2);
 //   l.PrintList();
    return 0;
}
