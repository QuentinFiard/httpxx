// Copyright(c) Andre Caron <andre.l.caron@gmail.com>, 2011
//
// This document is covered by the an Open Source Initiative approved license. A
// copy of the license should have been provided alongside this software package
// (see "LICENSE.txt"). If not, terms of the license are available online at
// "http://www.opensource.org/licenses/mit".

#include "Flags.hpp"

namespace http {

Flags GetFlagsFromParser(const ::http_parser& parser) {
  Flags res;
  if (parser.flags & F_CHUNKED) res.set(flags::CHUNKED);
  if (parser.flags & F_CONNECTION_KEEP_ALIVE) res.set(flags::KEEPALIVE);
  if (parser.flags & F_CONNECTION_CLOSE) res.set(flags::CLOSE);
  if (parser.flags & F_TRAILING) res.set(flags::TRAILING);
  if (parser.flags & F_UPGRADE) res.set(flags::UPGRADE);
  if (parser.flags & F_SKIPBODY) res.set(flags::SKIPBODY);
  return res;
}

}  // namespace http
