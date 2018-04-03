     }
 
     if (!reply) {
-        /*
-         * TODO: this occurs when a helper crashes. We should clean
-         * up that helpers resources and queued requests.
-         */
-        fatal("authenticateNegotiateHandleReply: called with no result string\n");
+        debug(29, 1) ("authenticateNegotiateHandleReply: Helper '%p' crashed!.\n", lastserver);
+        reply = "BH Internal error";
     }
 
     auth_user_request = r->auth_user_request;
