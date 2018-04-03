                 debugs(29, 9, "authenticateNegotiateFixErrorHeader: Connection authenticated");
                 httpHeaderPutStrf(&rep->header, reqType, "Negotiate");
             }
-
             break;
 
-        case AUTHENTICATE_STATE_NONE:
+        case AuthUser::Unchecked:
             /* semantic change: do not drop the connection.
              * 2.5 implementation used to keep it open - Kinkie */
             debugs(29, 9, "AuthNegotiateConfig::fixHeader: Sending type:" << reqType << " header: 'Negotiate'");
             httpHeaderPutStrf(&rep->header, reqType, "Negotiate");
             break;
 
-        case AUTHENTICATE_STATE_IN_PROGRESS:
+        case AuthUser::Handshake:
             /* we're waiting for a response from the client. Pass it the blob */
             debugs(29, 9, "AuthNegotiateConfig::fixHeader: Sending type:" << reqType << " header: 'Negotiate " << negotiate_request->server_blob << "'");
             httpHeaderPutStrf(&rep->header, reqType, "Negotiate %s", negotiate_request->server_blob);
             safe_free(negotiate_request->server_blob);
             break;
 
-
         default:
-            debugs(29, 0, "AuthNegotiateConfig::fixHeader: state " << negotiate_request->auth_state << ".");
+            debugs(29, DBG_CRITICAL, "AuthNegotiateConfig::fixHeader: state " << negotiate_request->user()->credentials() << ".");
             fatal("unexpected state in AuthenticateNegotiateFixErrorHeader.\n");
         }
     }
