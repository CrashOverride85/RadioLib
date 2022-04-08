


#file(GLOB FILES *.c *.cpp *.h)

file(GLOB_RECURSE FILES *.c *.cpp *.h)

add_library(RadioLib ${FILES})

target_link_libraries(RadioLib pico_stdlib hardware_spi)

target_include_directories(RadioLib PUBLIC ./)

