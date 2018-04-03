             decodedLen = base64_decode(decoded, sizeof(decoded), buf+3);
         else {
             debug("Negotiate packet not supplied - self generated\n");
-            memcpy(decoded, local_lego, sizeof(local_nego));
-            decodedLen = sizeof(localnego);
+            memcpy(decoded, &local_nego, sizeof(local_nego));
+            decodedLen = sizeof(local_nego);
         }
         if ((size_t)decodedLen < sizeof(ntlmhdr)) {		/* decoding failure, return error */
-            SEND("NA Packet format error, couldn't base64-decode");
+            SEND_ERR("message=\"Packet format error, couldn't base64-decode\"");
             return 1;
         }
         /* fast-track-decode request type. */
         fast_header = (struct _ntlmhdr *) decoded;
 
         /* sanity-check: it IS a NTLMSSP packet, isn't it? */
         if (ntlm_validate_packet(fast_header, NTLM_ANY) != NTLM_ERR_NONE) {
-            SEND("NA Broken authentication packet");
+            SEND_ERR("message=\"Broken authentication packet\"");
             return 1;
         }
         switch (fast_header->type) {
-        case NTLM_NEGOTIATE:
+        case NTLM_NEGOTIATE: {
             /* Obtain challenge against SSPI */
             debug("attempting SSPI challenge retrieval\n");
-            if ((c = (char *) SSP_MakeChallenge((ntlm_negotiate *) decoded, decodedLen)) != NULL ) {
+            char *c = (char *) SSP_MakeChallenge((ntlm_negotiate *) decoded, decodedLen);
+            if (c) {
+                SEND_TT(c);
                 if (NTLM_packet_debug_enabled) {
-                    printf("TT %s\n",c);
                     decodedLen = base64_decode(decoded, sizeof(decoded), c);
-                    debug("sending 'TT' to squid with data:\n");
-                    hex_dump(decoded, decodedLen);
-                    if (NTLM_LocalCall)
+                    debug("send 'TT' to squid with data:\n");
+                    hex_dump(reinterpret_cast<unsigned char*>(decoded), decodedLen);
+                    if (NTLM_LocalCall) {
                         debug("NTLM Local Call detected\n");
-                } else {
-                    SEND2("TT %s", c);
+                    }
                 }
                 have_challenge = 1;
             } else
-                helperfail("can't obtain challenge");
+                helperfail("message=\"can't obtain challenge\"");
 
             return 1;
-            /* notreached */
+        }
+        /* notreached */
         case NTLM_CHALLENGE:
-            SEND("NA Got a challenge. We refuse to have our authority disputed");
+            SEND_ERR("message=\"Got a challenge. We refuse to have our authority disputed\"");
             return 1;
             /* notreached */
         case NTLM_AUTHENTICATE:
-            SEND("NA Got authentication request instead of negotiate request");
+            SEND_ERR("message=\"Got authentication request instead of negotiate request\"");
             return 1;
             /* notreached */
         default:
-            helperfail("unknown refresh-request packet type");
+            helperfail("message=\"unknown refresh-request packet type\"");
             return 1;
         }
         return 1;
     }
     if (memcmp(buf, "KK ", 3) == 0) {	/* authenticate-request */
         if (!have_challenge) {
-            helperfail("invalid challenge");
+            helperfail("message=\"invalid challenge\"");
             return 1;
         }
         /* figure out what we got */
         decodedLen = base64_decode(decoded, sizeof(decoded), buf+3);
 
         if ((size_t)decodedLen < sizeof(ntlmhdr)) {		/* decoding failure, return error */
-            SEND("NA Packet format error, couldn't base64-decode");
+            SEND_ERR("message=\"Packet format error, couldn't base64-decode\"");
             return 1;
         }
         /* fast-track-decode request type. */
         fast_header = (struct _ntlmhdr *) decoded;
 
         /* sanity-check: it IS a NTLMSSP packet, isn't it? */
         if (ntlm_validate_packet(fast_header, NTLM_ANY) != NTLM_ERR_NONE) {
-            SEND("NA Broken authentication packet");
+            SEND_ERR("message=\"Broken authentication packet\"");
             return 1;
         }
         switch (fast_header->type) {
         case NTLM_NEGOTIATE:
-            SEND("NA Invalid negotiation request received");
+            SEND_ERR("message=\"Invalid negotiation request received\"");
             return 1;
             /* notreached */
         case NTLM_CHALLENGE:
-            SEND
-            ("NA Got a challenge. We refuse to have our authority disputed");
+            SEND_ERR("message=\"Got a challenge. We refuse to have our authority disputed\"");
             return 1;
             /* notreached */
-        case NTLM_AUTHENTICATE:
+        case NTLM_AUTHENTICATE: {
             /* check against SSPI */
-            err = ntlm_check_auth((ntlm_authenticate *) decoded, user, domain, decodedLen);
+            int err = ntlm_check_auth((ntlm_authenticate *) decoded, user, domain, decodedLen);
             have_challenge = 0;
             if (err != NTLM_ERR_NONE) {
 #if FAIL_DEBUG
                 fail_debug_enabled =1;
 #endif
-                switch (ntlm_errno) {
+                switch (err) {
                 case NTLM_ERR_NONE:
                     break;
                 case NTLM_BAD_NTGROUP:
-                    SEND("NA Incorrect Group Membership");
+                    SEND_ERR("message=\"Incorrect Group Membership\"");
                     return 1;
                 case NTLM_BAD_REQUEST:
-                    SEND("NA Incorrect Request Format");
+                    SEND_ERR("message=\"Incorrect Request Format\"");
                     return 1;
                 case NTLM_SSPI_ERROR:
                     FormatMessage(
