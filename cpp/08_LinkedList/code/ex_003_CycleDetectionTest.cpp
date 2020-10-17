/*------------------------------------------------------------------*
 * Cycle Detection
 *-----------------------------------------------------------------*/

#include "bc_000_ListNode.h"

#include <iostream>
#include <vector>
#include <unordered_set>

extern std::shared_ptr<ListNode<int>>
HasCycle(const std::shared_ptr<ListNode<int>> &head);

//--------------------------------------------------------------------

void
testCycleDetection(std::vector<int> & vecList, bool createLoop) {
    std::shared_ptr<ListNode<int>> head;
    createList(head, vecList);

    if(createLoop) {
        auto searchPtr1 = searchList(head, 10);
        auto searchPtr2 = searchList(head, 1);

        searchPtr1->next = searchPtr2;
    }

    std::cout << "------------------------------------" << std::endl;
    auto loopStartPtr = HasCycle(head);

    if(!loopStartPtr)
        std::cout << "No cycles detected" << std::endl;
    else
        std::cout << "Cycle detected and start at: "
                  << loopStartPtr->data << std::endl;
}

//--------------------------------------------------------------------

int
main() {
    std::vector<int> vecList {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    testCycleDetection( vecList, true);
    testCycleDetection( vecList, false);
    return 0;
}

//--------------------------------------------------------------------
