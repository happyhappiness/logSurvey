     }
     // TODO: Should we check receivedBodyTooLarge on the server-side as well?
 
-    startedAdaptation = startAdaptation(service, originalRequest());
-
-    if (!startedAdaptation && (!service || service->cfg().bypass)) {
-        // handle ICAP start failure when no service was selected
-        // or where the selected service was optional
+    if (!group) {
+        debugs(11,3, HERE << "no adapation needed");
         setFinalReply(virginReply());
         processReplyBody();
         return;
     }
 
-    if (!startedAdaptation) {
-        // handle start failure for an essential ICAP service
-        ErrorState *err = errorCon(ERR_ICAP_FAILURE,
-                                   HTTP_INTERNAL_SERVER_ERROR, originalRequest());
-        err->xerrno = errno;
-        errorAppendEntry(entry, err);
-        abortTransaction("ICAP start failure");
-        return;
-    }
-
+    startAdaptation(group, originalRequest());
     processReplyBody();
 }
 
 void
-ServerStateData::adaptationAclCheckDoneWrapper(Adaptation::ServicePointer service, void *data)
+ServerStateData::adaptationAclCheckDoneWrapper(Adaptation::ServiceGroupPointer group, void *data)
 {
     ServerStateData *state = (ServerStateData *)data;
-    state->adaptationAclCheckDone(service);
+    state->adaptationAclCheckDone(group);
 }
 #endif
 
