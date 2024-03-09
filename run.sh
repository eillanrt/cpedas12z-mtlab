#!/bin/bash

# Compile the project
g++ -std=c++17 main.cpp DataStructs/DoublyLinkedList.hpp DataStructs/Node.hpp Song/Song.cpp Song/Song.hpp Playlist/Playlist.cpp Playlist/Playlist.hpp -o myprogram

# Check if compilation was successful
if [ $? -eq 0 ]; then
    # If successful, run the program
    ./myprogram
else
    # If compilation failed, print an error message
    echo "Compilation failed."
fi
