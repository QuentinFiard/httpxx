#ifndef _http_Flags_hpp__
#define _http_Flags_hpp__

// Copyright(c) Andre Caron <andre.l.caron@gmail.com>, 2011
//
// This document is covered by the an Open Source Initiative approved license. A
// copy of the license should have been provided alongside this software package
// (see "LICENSE.txt"). If not, terms of the license are available online at
// "http://www.opensource.org/licenses/mit".

#include <bitset>
#include <http_parser/http_parser.h>

namespace http {
namespace flags {

/*!
 * @brief Extra information about the request or response.
 *
 * Flags mainly help with connection/socket management.  In particular,
 * you can determine whether to keep the connection open for keep alive
 * or if you should use switch to an alternate protocol handler
 * (WebSockets, for instance).
 */
enum {
  /*!
   * @brief Check if the message body is in chuncked format.
   */
  CHUNKED,

  /*!
   * @brief Check if the client requested keep-alive.
   *
   * @note Handling keep alive is only requested by the client, it is
   *  in no fashion required to accept this.  Many servers disable
   *  keep alive for performance reasons when their are hordes of
   *  requests coming mostly from different clients.
   *
   * @see CLOSE
   */
  KEEPALIVE,

  /*!
   * @brief Check if a new connection should be established for the
   *  next request.
   *
   * @see KEEPALIVE
   */
  CLOSE,
  TRAILING,

  /*!
   * @brief Check if the client requested a protocol upgrade.
   *
   * Newer HTTP versions support derived protocol (such as WebSockets)
   * to re-use port 80 for additional connections.  When an upgrade is
   * requested, the parser stops accepting data as soon as the headers
   * end.  Whatever data is received next should be interpreted by a
   * specialized protocol handler.
   *
   * In particular, check the "Upgrade" header to determine what
   * protocol was requested.
   */
  UPGRADE,
  SKIPBODY,

  /*!
   * @brief Number of flags.
   */
  MAX_FLAGS
};

}  // namespace flags

typedef std::bitset<flags::MAX_FLAGS> Flags;
Flags GetFlagsFromParser(const ::http_parser& parser);

}  // namespace http

#endif /* _http_Flags_hpp__ */
