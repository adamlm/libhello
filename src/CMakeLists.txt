add_library(helloLibrary hello.cpp)
add_library(libhello::hello ALIAS helloLibrary)

target_include_directories(helloLibrary
  PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)

target_link_libraries(helloLibrary
  PUBLIC
    fmt::fmt
)

set_target_properties(helloLibrary PROPERTIES
  EXPORT_NAME hello
  OUTPUT_NAME hello
)

if(libhello_BUILD_INSTALL)
  include(GNUInstallDirs)

  install(TARGETS helloLibrary
    EXPORT helloTargets
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  )

  install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/libhello
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING PATTERN *.hpp
  )

  install(FILES ${PROJECT_SOURCE_DIR}/cmake/libhelloConfig.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/libhello
  )

  install(EXPORT helloTargets
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/libhello/libhello
    FILE libhelloTargets.cmake
    NAMESPACE libhello::
  )

endif()
