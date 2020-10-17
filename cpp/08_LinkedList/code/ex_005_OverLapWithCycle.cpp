static std::shared_ptr<ListNode<int>>
hasCycle(std::shared_ptr<ListNode<int>> head) {
    auto slow = head;
    auto fast = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            slow = head;

            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}

//--------------------------------------------------------------------

static int
listLength(std::shared_ptr<ListNode<int>> head) {
    int length = 0;
    while(head) {
        head = head->next;
        length++;
    }

    return length;
}

//--------------------------------------------------------------------

static void
advanceNode(std::shared_ptr<ListNode<int>> &head, int k) {
    while(k) {
        head = head->next;
        k--;
    }
}

//--------------------------------------------------------------------

static std::shared_ptr<ListNode<int>>
checkOverlap(std::shared_ptr<ListNode<int>> l0, std::shared_ptr<ListNode<int>> l1) {
    auto length0 = listLength(l0);
    auto length1 = listLength(l1);

    auto diff = abs(length0-length1);
    advanceNode(length0 > length1 ? l0 : l1, diff);

    while(l0 && l1 && (l1 != l0)) {
        l0 = l0->next;
        l1 = l1->next;
    }
    
    return l1;
}

//--------------------------------------------------------------------

static int
gapBetweenNodes(std::shared_ptr<ListNode<int>> node0, std::shared_ptr<ListNode<int>> node1) {

    int length = 0;
    while(node0 != node1) {
        length++;
        node0=node0->next;
    }
    return length;
}

//--------------------------------------------------------------------

std::shared_ptr<ListNode<int>> OverlappingLists(std::shared_ptr<ListNode<int>> l0,
                                           std::shared_ptr<ListNode<int>> l1) {
    // TODO - you fill in here.
    if(!l0 && !l1) 
        return nullptr;

    // There are four cases.
    auto start0 = hasCycle(l0);
    auto start1 = hasCycle(l1);

    // case 1: no cycles no overlap
    if((start0 == nullptr) && (start1 == nullptr)) {
        // case 2: no cylcles but overlap
        return checkOverlap(l0, l1);
    }

    // case 3: one has cycle but other dont
    if((start0 && !start1) || (!start0 && start1))
        return nullptr;

    // case 4: both has cycles
    auto temp = start0;
    do {
        temp = temp->next;
        } while(temp != start0 && temp != start1);

    // case 5: cylces but no overlap
    if(temp != start1)
        return nullptr;
    

    // case 6: cycle but with overlap
    auto g0 = gapBetweenNodes(l0, start0);
    auto g1 = gapBetweenNodes(l1, start1);

    auto diff = abs(g0 - g1);
    
    advanceNode(g0 > g1 ? l0 : l1, diff);

    while(l0 != l1 && l0 != start0 && l1 == start1) {
        l0 = l0->next;
        l1 = l1->next;
    }
    return l0 == l1 ? l0: start1;
}

//--------------------------------------------------------------------
