# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appTCP_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appTCP_autogen.dir\\ParseCache.txt"
  "appTCP_autogen"
  )
endif()
