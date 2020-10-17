cmake_minimum_required(VERSION 3.1...3.14)

SET(CMAKE_CXX_COMPILER "/usr/bin/clang++-9")
SET(CMAKE_CXX_FLAGS "-std=c++17")
set(CMAKE_CXX_STANDARD 17)

project(BackTracking LANGUAGES CXX)

#---------------------------------------------------------------------

add_executable(bc_000_ListNodeTest
                bc_000_ListNodeTest.cpp bc_000_ListNode.cpp)

add_executable(bc_001_DListNodeTest
                bc_001_DListNodeTest.cpp bc_001_DListNode.cpp)

#---------------------------------------------------------------------

add_executable(ex_001_MergeSortedListTest
               bc_000_ListNode.cpp ex_001_MergeSortedList.cpp ex_001_MergeSortedListTest.cpp)

add_executable(ex_002_ReverseSubListTest
               bc_000_ListNode.cpp ex_002_ReverseSubList.cpp ex_002_ReverseSubListTest.cpp)

add_executable(ex_003A_CycleDetection
               bc_000_ListNode.cpp ex_003A_CycleDetection.cpp ex_003_CycleDetectionTest.cpp)
add_executable(ex_003B_CycleDetection
               bc_000_ListNode.cpp ex_003B_CycleDetection.cpp ex_003_CycleDetectionTest.cpp)
add_executable(ex_003C_CycleDetection
               bc_000_ListNode.cpp ex_003C_CycleDetection.cpp ex_003_CycleDetectionTest.cpp)
add_executable(ex_003D_CycleDetection
               bc_000_ListNode.cpp ex_003D_CycleDetection.cpp ex_003_CycleDetectionTest.cpp)

add_executable(ex_004A_OverLapNoCycle
                bc_000_ListNode.cpp ex_004A_OverLapNoCycle.cpp ex_004_OverLapNoCycleTest.cpp)
add_executable(ex_004B_OverLapNoCycle
                bc_000_ListNode.cpp ex_004B_OverLapNoCycle.cpp ex_004_OverLapNoCycleTest.cpp)
add_executable(ex_004C_OverLapNoCycle
                bc_000_ListNode.cpp ex_004C_OverLapNoCycle.cpp ex_004_OverLapNoCycleTest.cpp)

add_executable(ex_006_DeleteNodeFromList
               bc_000_ListNode.cpp ex_006_DeleteNodeFromList.cpp ex_006_DeleteNodeFromListTest.cpp) 

add_executable(ex_007_RemoveKthNodeFromLast
               bc_000_ListNode.cpp ex_007_RemoveKthNodeFromLast.cpp ex_007_RemoveKthNodeFromLastTest.cpp)

add_executable(ex_008_RemoveSortedDuplicates
               ex_008_RemoveSortedDuplicates.cpp bc_000_ListNode.cpp)

add_executable(ex_010_EvenOddMerge
               ex_010_EvenOddMerge.cpp bc_000_ListNode.cpp)

add_executable(ex_011_Palindrome
               ex_011_Palindrome.cpp bc_000_ListNode.cpp)

add_executable(ex_013_AddListBasedIntegers
               ex_013_AddListBasedIntegers.cpp bc_000_ListNode.cpp)

#---------------------------------------------------------------------

add_executable(vt_001_MergeDblySortedLists
               vt_001_MergeDblySortedLists.cpp bc_001_DListNode.cpp)

add_executable(vt_002_ReverseListTest
               bc_000_ListNode.cpp vt_002_ReverseList.cpp vt_002_ReverseListTest.cpp) 

add_executable(vt_003_ReverseKSubList
               vt_003_ReverseKSubList.cpp bc_000_ListNode.cpp)

add_executable(vt_004_CycleDetection
               vt_004_CycleDetection.cpp bc_000_ListNode.cpp)

#---------------------------------------------------------------------

add_custom_command(TARGET bc_000_ListNodeTest POST_BUILD

    COMMAND bc_000_ListNodeTest
    COMMAND bc_001_DListNodeTest

    COMMAND ex_001_MergeSortedListTest
    COMMAND ex_002_ReverseSubListTest

    COMMAND ex_003A_CycleDetection
    COMMAND ex_003B_CycleDetection
    COMMAND ex_003C_CycleDetection
    COMMAND ex_003D_CycleDetection

    COMMAND ex_004A_OverLapNoCycle
    COMMAND ex_004B_OverLapNoCycle
    COMMAND ex_004C_OverLapNoCycle

    COMMAND ex_006_DeleteNodeFromList
    COMMAND ex_007_RemoveKthNodeFromLast
    COMMAND ex_008_RemoveSortedDuplicates
    COMMAND ex_010_EvenOddMerge
    COMMAND ex_011_Palindrome
    COMMAND ex_013_AddListBasedIntegers

    COMMAND vt_001_MergeDblySortedLists
    COMMAND vt_002_ReverseListTest
    COMMAND vt_003_ReverseKSubList
    COMMAND vt_004_CycleDetection

    COMMENT "Running built executable and additional process..."
)

#---------------------------------------------------------------------
