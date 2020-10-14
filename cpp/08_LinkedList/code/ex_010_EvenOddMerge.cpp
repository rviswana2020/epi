/*-------------------------------------------------------------------*
 * Given a list, generate a list that contains all even entries
 * followed by all odd entries
 *------------------------------------------------------------------*/

#include <iostream>
#include <vector>

#include "bc_000_ListNode.h"

std::shared_ptr<ListNode<int>>
evenOddMerge(std::shared_ptr<ListNode<int>> list) {

    std::shared_ptr<ListNode<int>> dummyEven = std::make_shared<ListNode<int>>(-1);
    std::shared_ptr<ListNode<int>> dummyOdd = std::make_shared<ListNode<int>>(-1);

    auto evenTail = dummyEven;
    auto oddTail = dummyOdd;

    int evenOddFlip = 0;
    while(list) {
        if(!evenOddFlip) {
            evenTail->next = list;
            evenTail = evenTail->next;
        } else {
            oddTail->next = list;
            oddTail = oddTail->next;
        }
            list = list->next;
        evenOddFlip ^= 1;
    }
    oddTail->next = nullptr;
    evenTail->next = dummyOdd->next;
    return dummyEven->next;
}

//--------------------------------------------------------------------

void
testEvenOddMerge(const std::vector<int> &vecList) {
    std::shared_ptr<ListNode<int>> list;
    createList(list, vecList);

    std::cout << "Given List: ";
    printList(list);

    auto evenOddList = evenOddMerge(list);
    std::cout << "evenOdd Merged List: ";
    printList(evenOddList);
    std::cout << "---------------------------" << std::endl;
}
    
//--------------------------------------------------------------------

int
main() {
    testEvenOddMerge({0, 1, 2, 3, 4, 5, 6});
    testEvenOddMerge({0});
    testEvenOddMerge({});
    return 0;
}
    
//--------------------------------------------------------------------
