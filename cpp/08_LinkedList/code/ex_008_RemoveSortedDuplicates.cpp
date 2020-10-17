/*-------------------------------------------------------------------*
 * Remove Duplicates from sorted List
 * Example L---->2---->2---->3----->3
 * ouput   L---->2---->3
 *------------------------------------------------------------------*/

#include <iostream>
#include <vector>

#include "bc_000_ListNode.h"

//--------------------------------------------------------------------

std::shared_ptr<ListNode<int>> RemoveDuplicates(const std::shared_ptr<ListNode<int>>& L) {
    auto iter = L;

    while(iter) {
        auto next_distinct = iter->next;

        while(next_distinct && next_distinct->data == iter->data) {
            next_distinct = next_distinct->next;
        }

        iter->next = next_distinct;
        iter = next_distinct;
    }

    return L;
}

//--------------------------------------------------------------------
