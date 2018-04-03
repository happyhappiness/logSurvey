         switch (fast_header->type) {
         case NTLM_NEGOTIATE:
             /* Obtain challenge against SSPI */
-                debug("attempting SSPI challenge retrieval\n");
-                if ((c = (char *) SSP_MakeChallenge((ntlm_negotiate *) decoded, decodedLen)) != NULL ) {
-                    if (NTLM_packet_debug_enabled) {
-                        printf("TT %s\n",c);
-                        decodedLen = base64_decode(decoded, sizeof(decoded), c);
-                        debug("sending 'TT' to squid with data:\n");
-                        hex_dump(decoded, decodedLen);
-                        if (NTLM_LocalCall)
-                            debug("NTLM Local Call detected\n");
-                    } else {
-                        SEND2("TT %s", c);
-                    }
-                    have_challenge = 1;
-                } else
-                    helperfail("can't obtain challenge");
+            debug("attempting SSPI challenge retrieval\n");
+            if ((c = (char *) SSP_MakeChallenge((ntlm_negotiate *) decoded, decodedLen)) != NULL ) {
+                if (NTLM_packet_debug_enabled) {
+                    printf("TT %s\n",c);
+                    decodedLen = base64_decode(decoded, sizeof(decoded), c);
+                    debug("sending 'TT' to squid with data:\n");
+                    hex_dump(decoded, decodedLen);
+                    if (NTLM_LocalCall)
+                        debug("NTLM Local Call detected\n");
+                } else {
+                    SEND2("TT %s", c);
+                }
+                have_challenge = 1;
+            } else
+                helperfail("can't obtain challenge");
 
-                    return 1;
-                    /* notreached */
-                case NTLM_CHALLENGE:
-                        SEND("NA Got a challenge. We refuse to have our authority disputed");
-                        return 1;
-                        /* notreached */
-                    case NTLM_AUTHENTICATE:
-                            SEND("NA Got authentication request instead of negotiate request");
-                            return 1;
-                            /* notreached */
-                        default:
-                                helperfail("unknown refresh-request packet type");
-                                return 1;
-                            }
+            return 1;
+            /* notreached */
+        case NTLM_CHALLENGE:
+            SEND("NA Got a challenge. We refuse to have our authority disputed");
+            return 1;
+            /* notreached */
+        case NTLM_AUTHENTICATE:
+            SEND("NA Got authentication request instead of negotiate request");
+            return 1;
+            /* notreached */
+        default:
+            helperfail("unknown refresh-request packet type");
+            return 1;
+        }
         return 1;
     }
     if (memcmp(buf, "KK ", 3) == 0) {	/* authenticate-request */