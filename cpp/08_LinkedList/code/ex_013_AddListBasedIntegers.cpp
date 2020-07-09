/*-------------------------------------------------------------------*
 * Add list based Integers
 *   Given two integers that are represented by nodes of a singly
 *   linked list.  Also assume that the numbers starts with least
 *   significant digits.
 *    first_number 3------>1------->4
 *   second_number 7------>0------->9
 *   sum           0------>2------->3------>1
 *------------------------------------------------------------------*/

#include <iostream>
#include <vector>

#include "bc_000_ListNode.h"

std::shared_ptr<ListNode>
addListBasedNums(std::shared_ptr<ListNode> listNum1,
                 std::shared_ptr<ListNode> listNum2) {

    int sum = 0;
    int carry = 0;

    std::shared_ptr<ListNode> sumListHead = std::make_shared<ListNode>(-1);
    auto sumList = sumListHead;

    while(listNum1 || listNum2) {

        int curDigit = carry;

        if(listNum1)
            curDigit += listNum1->data;

        if(listNum2)
            curDigit += listNum2->data;

        sum = curDigit % 10;
        carry = curDigit / 10;

        sumList->next = std::make_shared<ListNode>(sum);
        listNum1 = listNum1->next;
        listNum2 = listNum2->next;
        sumList = sumList->next;
    }

    if(carry) {
        sumList->next = std::make_shared<ListNode>(carry);
    }

    return sumListHead->next;
}

//--------------------------------------------------------------------

void
testAddListBasedNums(const std::vector<int> & num1,
                     const std::vector<int> & num2) {
    std::shared_ptr<ListNode> listNum1;
    std::shared_ptr<ListNode> listNum2;

    createList(listNum1, num1);
    createList(listNum2, num2);

    auto sumList = addListBasedNums(listNum1, listNum2);

    std::cout << "first number: ";
    printList(listNum1);

    std::cout << "second number: ";
    printList(listNum2);

    std::cout << "Sum: ";
    printList(sumList);
}


//--------------------------------------------------------------------

int
main() {
    std::vector<int> num1 {3, 1, 4};
    std::vector<int> num2 {7, 0, 9};

    testAddListBasedNums(num1, num2);

    testAddListBasedNums({1, 2, 3 }, {9, 9 ,9 });

    return 0;
}

//--------------------------------------------------------------------
