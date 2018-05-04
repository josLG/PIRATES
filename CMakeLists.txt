cmake_minimum_required(VERSION 2.6)
file(TO_CMAKE_PATH "$ENV{IMAGINEPP_ROOT}/CMake" p)
list(APPEND CMAKE_MODULE_PATH "${p}") #For old Imagine++
list(APPEND CMAKE_SYSTEM_FRAMEWORK_PATH /Library/Frameworks) #Mac, why not auto?
find_package(Imagine REQUIRED)

project(Pirates)

add_executable(Jeupirates carte.h carte.cpp
				pixel.h pixel.cpp
				bateau.h bateau.cpp
                                attaque.h attaque.cpp
				deplacement.h deplacement.cpp
				evenement.h evenement.cpp
                                jeu.cpp)
ImagineUseModules(Jeupirates Images)
