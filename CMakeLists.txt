cmake_minimum_required(VERSION 3.13)
project(project2)

set(CMAKE_CXX_STANDARD 14)

SET(CMAKE_CXX_FLAGS -pthread)

add_executable(project2 Server.h MySerialServer.cpp MySerialServer.h ClientHandler.h MyTestClientHandler.h Solver.h
        CacheManager.h FileCacheManager.h StringReverser.h
        Main.cpp MyTestClientHandler.cpp FileCacheManager.cpp
        ISearchable.h ISearcher.h MyParallelServer.cpp MyParallelServer.h State.h BestFirstSearch.h MyPriorityQueue.h Matrix.cpp Matrix.h Cell.cpp Cell.h AbstractServer.h
        SolverSearcherAdapter.h MyClientHandler.cpp MyClientHandler.h BreadthFirstSearch.h)
