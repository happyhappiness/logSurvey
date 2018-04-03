                 the regular request below.  */
              proxyauth = NULL;
            }
          /* Examples in rfc2817 use the Host header in CONNECT
             requests.  I don't see how that gains anything, given
             that the contents of Host would be exactly the same as
             the contents of CONNECT.  */

          write_error = request_send (connreq, sock, 0);
          request_free (connreq);
