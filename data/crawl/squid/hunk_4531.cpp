         case AUTHENTICATE_STATE_NONE:
             /* semantic change: do not drop the connection.
              * 2.5 implementation used to keep it open - Kinkie */
-            debugs(29, 9, "AuthNegotiateConfig::fixHeader: Sending type:" << type << " header: 'NEGOTIATE'");
+            debugs(29, 9, "AuthNegotiateConfig::fixHeader: Sending type:" << type << " header: 'Negotiate'");
             httpHeaderPutStrf(&rep->header, type, "Negotiate");
             break;
 
