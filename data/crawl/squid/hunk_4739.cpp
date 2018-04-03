      * to the user, or keep going without ICAP.
      */
     fatal("Fix this case in ClientRequestContext::icapAclCheckDone()");
+    // And when fixed, check whether the service is down in doIcap and
+    // if it is, abort early, without creating ICAPClientReqmodPrecache.
+    // See Server::startIcap() and its use.
 
     http->doCallouts();
 }
