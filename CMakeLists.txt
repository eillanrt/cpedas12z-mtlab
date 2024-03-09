cmake_minimum_required(VERSION 3.27)
project(das_fistpt)

set(CMAKE_CXX_STANDARD 17)

add_executable(das_fistpt main.cpp
        Song/Song.hpp
        Song/Song.cpp
        DataStructs/DoublyLinkedList.hpp
        DataStructs/Node.hpp
        Playlist/Playlist.hpp
        Playlist/Playlist.cpp
)
