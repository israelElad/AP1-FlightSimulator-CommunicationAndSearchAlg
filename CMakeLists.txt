cmake_minimum_required(VERSION 3.13)
project(project2)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)

add_executable(project2 Server.h MySerialServer.cpp MySerialServer.h ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Solver.h CacheManager.h FileCacheManager.h  StringReverser.cpp StringReverser.h Thread.cpp Thread.h Runnable.h RunnableTask.cpp RunnableTask.h Task.h OpenServerTask.cpp OpenServerTask.h Main.cpp)
