add_executable(01_calorie_counting 01_calorie_counting.cpp )

target_include_directories(01_calorie_counting PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/dat)
