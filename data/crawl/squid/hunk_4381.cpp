     if (abortOnBadEntry("entry went bad while waiting for ICAP ACL check"))
         return;
 
+    // TODO: Should nonICAP and postICAP path check this on the server-side?
+    // That check now only happens on client-side, in processReplyAccess().
+    if (virginReply()->expectedBodyTooLarge(*request)) {
+        sendBodyIsTooLargeError();
+        return;
+    }
+    // TODO: Should we check received5CBodyTooLarge on the server-side as well?
+
     startedIcap = startIcap(service, originalRequest());
 
     if (!startedIcap && (!service || service->bypass)) {
