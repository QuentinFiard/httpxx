# httpxx library.

set(sources
  Error.cpp
  Flags.cpp
  Message.cpp
  Method.cpp
  Request.cpp
  Response.cpp
  Url.cpp
)
add_library(httpxx ${sources})
target_link_libraries(httpxx http_parser)

set(headers
  BufferedMessage.hpp
  Error.hpp
  Flags.hpp
  Message.hpp
  Method.hpp
  Request.hpp
  Response.hpp
  Url.hpp
)
install(FILES ${headers} DESTINATION include/httpxx)
install(TARGETS httpxx LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
