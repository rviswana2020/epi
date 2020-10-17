/*-------------------------------------------------------------- *
 * Merge two sorted input lists.  The output list should contain
 * elements from both input lists in ascending order.
 *--------------------------------------------------------------*/

#include "bc_000_ListNode.h"

#include <memory>

void
AppendNode(std::shared_ptr<ListNode<int>>& node, std::shared_ptr<ListNode<int>> & tail) {
	tail->next = node;
	tail = tail->next;

	node = node->next;
}

//--------------------------------------------------------------------

std::shared_ptr<ListNode<int>> 
MergeTwoSortedLists(std::shared_ptr<ListNode<int>> L1,
                    std::shared_ptr<ListNode<int>> L2) {
	auto dummyHead{ std::make_shared<ListNode<int>>(0, nullptr)};
	auto tail = dummyHead;

	while(L1 && L2) {
		AppendNode(L1->data < L2->data ? L1 : L2, tail);
	}
	tail->next = L1 ? L1 : L2;

	return dummyHead->next;
}	

//--------------------------------------------------------------------
