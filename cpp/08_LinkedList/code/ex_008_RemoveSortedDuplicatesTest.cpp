/*-------------------------------------------------------------------*
 * Remove Duplicates from sorted List
 * Example L---->2---->2---->3----->3
 * ouput   L---->2---->3
 *------------------------------------------------------------------*/

#include <iostream>
#include <vector>

#include "bc_000_ListNode.h"

extern
std::shared_ptr<ListNode<int>> RemoveDuplicates(const std::shared_ptr<ListNode<int>>& L);

//--------------------------------------------------------------------

void
testRemoveDuplicates(const std::vector<int> & vecList) {
    std::shared_ptr<ListNode<int>> list;
    createList(list, vecList);

    std::cout << "Given List: ";
    printList(list);

	auto newHead = RemoveDuplicates(list);

    std::cout << "After removing duplicates: ";
    printList(newHead);
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
