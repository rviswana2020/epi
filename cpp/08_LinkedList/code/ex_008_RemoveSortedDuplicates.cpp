/*-------------------------------------------------------------------*
 * Remove Duplicates from sorted List
 * Example L---->2---->2---->3----->3
 * ouput   L---->2---->3
 *------------------------------------------------------------------*/

#include <iostream>
#include <vector>

#include "bc_000_ListNode.h"

void
removeDuplicates(std::shared_ptr<ListNode> list) {
    while(list && list->next) {
        while(list && list->next && list->data == list->next->data) {
            list->next = list->next->next;
        }
        list = list->next;
    }
}

//--------------------------------------------------------------------

void
testRemoveDuplicates(const std::vector<int> & vecList) {
    std::shared_ptr<ListNode> list;
    createList(list, vecList);

    std::cout << "Given List: ";
    printList(list);

    removeDuplicates(list);

    std::cout << "After removing duplicates: ";
    printList(list);
    std::cout << "------------------------------------" << std::endl;
}

//--------------------------------------------------------------------

int
main() {
    testRemoveDuplicates({2, 2, 2, 2, 3, 4, 5, 6, 6});
    testRemoveDuplicates({2, 2, 2, 2 });
    testRemoveDuplicates({2, 2 });
    testRemoveDuplicates({2 });
    return 0;
}

//--------------------------------------------------------------------
