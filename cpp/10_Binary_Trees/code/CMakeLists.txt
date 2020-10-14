cmake_minimum_required(VERSION 3.1...3.14)

SET(CMAKE_CXX_COMPILER "/usr/bin/clang++-9")
SET(CMAKE_CXX_FLAGS "-std=c++17")
set(CMAKE_CXX_STANDARD 17)

project(BackTracking LANGUAGES CXX)

#---------------------------------------------------------------------

add_executable(bc_000_BinaryTreeNode
                bc_000_BinaryTreeNode.cpp bc_000_BinaryTreeNodeTest.cpp)

add_executable(bc_001_RecursiveTreeTraversal
               bc_000_BinaryTreeNode.cpp bc_001_RecursiveTreeTraversal.cpp bc_001_RecursiveTreeTraversalTest.cpp)

#---------------------------------------------------------------------

#---------------------------------------------------------------------

add_custom_command(TARGET bc_000_BinaryTreeNode POST_BUILD

    COMMAND bc_000_BinaryTreeNode
    COMMAND bc_001_RecursiveTreeTraversal

    COMMENT "Running built executable and additional process..."
)

#---------------------------------------------------------------------
