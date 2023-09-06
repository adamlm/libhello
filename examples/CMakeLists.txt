add_executable(say_hello say_hello.cpp)

target_link_libraries(say_hello
  PRIVATE
    libhello::hello
)
