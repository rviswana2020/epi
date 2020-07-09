/*-------------------------------------------------------------------*
 * Check if the singly list is a palindrome
 *------------------------------------------------------------------*/

#include <iostream>
#include <memory>
#include <vector>

#include "bc_000_ListNode.h"

bool
recursiveChkPalindrome(std::shared_ptr<ListNode> &first,
                       std::shared_ptr<ListNode> last) {
    if(last == nullptr)
        return true;

    bool result = recursiveChkPalindrome(first, last->next);
    if( result && first->data == last->data) {
        first = first->next;
        return true;
    }
    return false;
 }

//--------------------------------------------------------------------
bool
checkPalindrome(std::shared_ptr<ListNode> head) {
    auto first = head;
    auto last = head;

    return recursiveChkPalindrome(first, last);
}

//--------------------------------------------------------------------

void
testPalindrome(std::vector<int> & vecList) {
    std::shared_ptr<ListNode> list;
    createList(list, vecList);
    std::cout << "Input List: ";
    printList(list);

    bool isPalindrome = checkPalindrome(list);
    std::cout << " The list is "
              << (isPalindrome ? "" : "not") 
              << " Palindrome. " << std::endl;
}

//--------------------------------------------------------------------
int
main() {
    std::vector<int> vecList {1, 2, 3, 4, 3, 2, 1};
    testPalindrome(vecList);

    std::vector<int> vecList1 {1, 2, 3, 3, 2, 1};
    testPalindrome(vecList);

    std::vector<int> vecList2 {3, 2, 1};
    testPalindrome(vecList2);

    return 0;
}

//--------------------------------------------------------------------
