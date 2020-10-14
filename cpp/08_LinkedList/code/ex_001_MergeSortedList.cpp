/*-------------------------------------------------------------- *
 * Merge two sorted input lists.  The output list should contain
 * elements from both input lists in ascending order.
 *--------------------------------------------------------------*/

#include "bc_000_ListNode.h"

static void
append(std::shared_ptr<ListNode<int>> & head, std::shared_ptr <ListNode<int>> &secondList) {
    head->next = secondList;
    secondList = secondList->next;
}

//--------------------------------------------------------------------

std::shared_ptr<ListNode<int>>
mergeSortedList(std::shared_ptr<ListNode<int>> ListA, std::shared_ptr<ListNode<int>> ListB) {

    std::shared_ptr<ListNode<int>> mergeList = std::make_shared<ListNode<int>>(-1);
    auto tmpList = mergeList;

    while(ListA && ListB) {
       append(tmpList,
              ListA->data < ListB->data ? ListA : ListB);
       tmpList = tmpList->next;
    }

    tmpList->next = ListA ? ListA : ListB;

    return mergeList->next;
}

//--------------------------------------------------------------------
