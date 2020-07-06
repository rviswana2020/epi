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

add_executable(ex_001_MergeSortedList
               ex_001_MergeSortedList.cpp bc_000_ListNode.cpp)

add_executable(ex_002_ReverseSubList
               ex_002_ReverseSubList.cpp bc_000_ListNode.cpp)

add_executable(ex_003_CycleDetection
               ex_003_CycleDetection.cpp bc_000_ListNode.cpp)

#---------------------------------------------------------------------

add_executable(vt_001_MergeDblySortedLists
               vt_001_MergeDblySortedLists.cpp bc_001_DListNode.cpp)

add_executable(vt_002_ReverseList
               vt_002_ReverseList.cpp bc_000_ListNode.cpp)

add_executable(vt_003_ReverseKSubList
               vt_003_ReverseKSubList.cpp bc_000_ListNode.cpp)

add_executable(vt_004_CycleDetection
               vt_004_CycleDetection.cpp bc_000_ListNode.cpp)

#---------------------------------------------------------------------

add_custom_command(TARGET bc_000_ListNodeTest POST_BUILD

    COMMAND bc_000_ListNodeTest
    COMMAND bc_001_DListNodeTest

    COMMAND ex_001_MergeSortedList
    COMMAND ex_002_ReverseSubList
    COMMAND ex_003_CycleDetection

    COMMAND vt_001_MergeDblySortedLists
    COMMAND vt_002_ReverseList
    COMMAND vt_003_ReverseKSubList
    COMMAND vt_004_CycleDetection

    COMMENT "Running built executable and additional process..."
)

#---------------------------------------------------------------------
