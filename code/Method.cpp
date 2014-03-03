// Copyright(c) Andre Caron <andre.l.caron@gmail.com>, 2011
//
// This document is covered by the an Open Source Initiative approved license. A
// copy of the license should have been provided alongside this software package
// (see "LICENSE.txt"). If not, terms of the license are available online at
// "http://www.opensource.org/licenses/mit".

#include "Method.hpp"

#include <iostream>

namespace http {

Method GetMethodFromParser(const http_parser& parser) {
  switch (parser.method) {
    case HTTP_DELETE:
      return DELETE;
    case HTTP_GET:
      return GET;
    case HTTP_HEAD:
      return HEAD;
    case HTTP_POST:
      return POST;
    case HTTP_PUT:
      return PUT;
    case HTTP_CONNECT:
      return CONNECT;
    case HTTP_OPTIONS:
      return OPTIONS;
    case HTTP_TRACE:
      return TRACE;
    case HTTP_COPY:
      return COPY;
    case HTTP_LOCK:
      return LOCK;
    case HTTP_MKCOL:
      return MKCOL;
    case HTTP_MOVE:
      return MOVE;
    case HTTP_PROPFIND:
      return PROPFIND;
    case HTTP_PROPPATCH:
      return PROPPATCH;
    case HTTP_UNLOCK:
      return UNLOCK;
    case HTTP_REPORT:
      return REPORT;
    case HTTP_MKACTIVITY:
      return MKACTIVITY;
    case HTTP_CHECKOUT:
      return CHECKOUT;
    case HTTP_MERGE:
      return MERGE;
    case HTTP_MSEARCH:
      return MSEARCH;
    case HTTP_NOTIFY:
      return NOTIFY;
    case HTTP_SUBSCRIBE:
      return SUBSCRIBE;
    case HTTP_UNSUBSCRIBE:
      return UNSUBSCRIBE;
    case HTTP_PATCH:
      return PATCH;
    default:
      std::cerr << "Unknown HTTP method: " << parser.method << std::endl;
      exit(1);
  }
}

const char* GetMethodName(Method method) {
  switch (method) {
    case DELETE:
      return "DELETE";
    case GET:
      return "GET";
    case HEAD:
      return "HEAD";
    case POST:
      return "POST";
    case PUT:
      return "PUT";
    case CONNECT:
      return "CONNECT";
    case OPTIONS:
      return "OPTIONS";
    case TRACE:
      return "TRACE";
    case COPY:
      return "COPY";
    case LOCK:
      return "LOCK";
    case MKCOL:
      return "MKCOL";
    case MOVE:
      return "MOVE";
    case PROPFIND:
      return "PROPFIND";
    case PROPPATCH:
      return "PROPPATCH";
    case UNLOCK:
      return "UNLOCK";
    case REPORT:
      return "REPORT";
    case MKACTIVITY:
      return "MKACTIVITY";
    case CHECKOUT:
      return "CHECKOUT";
    case MERGE:
      return "MERGE";
    case MSEARCH:
      return "MSEARCH";
    case NOTIFY:
      return "NOTIFY";
    case SUBSCRIBE:
      return "SUBSCRIBE";
    case UNSUBSCRIBE:
      return "UNSUBSCRIBE";
    case PATCH:
      return "PATCH";
    default:
      std::cerr << "Unknown HTTP method: " << method << std::endl;
      exit(1);
  }
}

}  // namespace http
