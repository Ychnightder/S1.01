cmake_minimum_required(VERSION 3.26)
project(S1_01)

set(CMAKE_CXX_STANDARD 14)

add_executable(S1_01
        main.cpp
        exit/exit.h
        exit/exit.cpp
        inscription/inscription.h
        inscription/inscription.cpp
        mission/mission.h
        mission/mission.cpp
        consultation/consultation.h
        consultation/consultation.cpp
        rapport/rapport.h
        rapport/rapport.cpp
        detail/detail.cpp
        detail/detail.h
        acceptation/acceptation.h
        acceptation/acceptation.cpp)
