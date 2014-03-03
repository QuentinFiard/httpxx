#ifndef _http_Method__
#define _http_Method__

// Copyright(c) Andre Caron <andre.l.caron@gmail.com>, 2011
//
// This document is covered by the an Open Source Initiative approved license. A
// copy of the license should have been provided alongside this software package
// (see "LICENSE.txt"). If not, terms of the license are available online at
// "http://www.opensource.org/licenses/mit".

#include <http_parser/http_parser.h>

namespace http {

/*!
 * @brief Enumeration of "well known" HTTP request methods.
 */

enum Method {
  //! @defgroup Standard HTTP methods.
  //! @{

  /*!
   * @brief Delete the resource.
   */
  DELETE,

  /*!
   * @brief Fetch the resource.
   */
  GET,

  /*!
   * @brief Like GET, but don't send a response body (headers only).
   */
  HEAD,

  /*!
   * @brief Submit information about the resource.
   *
   * @see PUT
   * @see PATCH
   */
  POST,

  /*!
   * @brief Replace the resource.
   *
   * @see POST
   * @see PATCH
   */
  PUT,

  //! @}

  //! @defgroup Standard HTTP extension methods.
  //! @{

  /*!
   * @brief Partially update the resource (RFC 5789).
   *
   * @see POST
   * @see PUT
   */
  PATCH,

  //! @}

  /*!
   * @brief Establish a connection for tunnelling another protocol.
   */
  CONNECT,

  /*!
   * @brief Fetch requirements or capabilities w/ respect to the URI.
   */
  OPTIONS,

  /*!
   * @brief Echo request as response body.
   *
   * The TRACE method is used for network diagnostics (e.g. to detect
   * proxies and gateways) and for testing, to check what is received
   * at the other end of the connection.
   */
  TRACE,

  //! @defgroup WebDAV HTTP extension methods.
  //! @{
  COPY,
  LOCK,
  MKCOL,
  MOVE,
  PROPFIND,
  PROPPATCH,
  UNLOCK,

  //! @}

  //! @defgroup Subversion HTTP extension methods.
  //! @{
  REPORT,
  MKACTIVITY,
  CHECKOUT,
  MERGE,

  //! @}

  //! @defgroup Universal Plug and Play (UPNP) HTTP extension methods.
  //! @{
  MSEARCH,
  NOTIFY,
  SUBSCRIBE,
  UNSUBSCRIBE

  //! @}
};

Method GetMethodFromParser(const http_parser& parser);
const char* GetMethodName(Method method);

}  // namespace http

#endif /* _http_Method__ */
