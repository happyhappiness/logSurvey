     ac->noteAnswer(answer==ACCESS_ALLOWED);
 }
 
+/// process the results of the ACL check
 void
 Adaptation::AccessCheck::noteAnswer(int answer)
 {
-    debugs(93, 5, HERE << "AccessCheck::noteAnswer " << answer);
-    if (candidates.size())
-        debugs(93, 5, HERE << "was checking rule" << topCandidate());
-
-    if (!answer) {
-        candidates.shift(); // the rule did not match
-        checkCandidates();
-        return;
+    Must(!candidates.empty()); // the candidate we were checking must be there
+    debugs(93,5, HERE << topCandidate() << " answer=" << answer);
+
+    if (answer) { // the rule matched
+        ServiceGroupPointer g = topGroup();
+        if (g != NULL) { // the corresponding group found
+            callBack(g);
+            Must(done());
+            return;
+        }
     }
 
-    /*
-     * We use an event here to break deep function call sequences
-     */
-    // XXX: use AsyncCall for callback and remove
-    CallJobHere(93, 5, this, Adaptation::AccessCheck::do_callback);
+    // no match or the group disappeared during reconfiguration
+    candidates.shift();
+    checkCandidates();
 }
 
+/// call back with a possibly nil group; the job ends here because all failures
+/// at this point are fatal to the access check process
 void
-Adaptation::AccessCheck::do_callback()
+Adaptation::AccessCheck::callBack(const ServiceGroupPointer &g)
 {
-    debugs(93, 3, HERE);
-
-    if (candidates.size())
-        debugs(93, 3, HERE << "was checking rule" << topCandidate());
+    debugs(93,3, HERE << g);
 
     void *validated_cbdata;
-    if (!cbdataReferenceValidDone(callback_data, &validated_cbdata)) {
-        debugs(93,3,HERE << "do_callback: callback_data became invalid, skipping");
-        return;
+    if (cbdataReferenceValidDone(callback_data, &validated_cbdata)) {
+        callback(g, validated_cbdata);
     }
+    mustStop("done"); // called back or will never be able to call back
+}
 
-    ServicePointer service = NULL;
+Adaptation::ServiceGroupPointer
+Adaptation::AccessCheck::topGroup() const
+{
+    ServiceGroupPointer g;
     if (candidates.size()) {
         if (AccessRule *r = FindRule(topCandidate())) {
-            service = findBestService(*r, true);
-            if (service != NULL)
-                debugs(93,3,HERE << "do_callback: with service " << service->cfg().uri);
-            else
-                debugs(93,3,HERE << "do_callback: no service for rule" << r->id);
+            g = FindGroup(r->groupId);
+            debugs(93,5, HERE << "top group for " << r->id << " is " << g);
         } else {
-            debugs(93,3,HERE << "do_callback: no rule" << topCandidate());
+            debugs(93,5, HERE << "no rule for " << topCandidate());
         }
-        candidates.shift(); // done with topCandidate()
     } else {
-        debugs(93,3,HERE << "do_callback: no candidate rules");
+        debugs(93,5, HERE << "no candidates"); // should not happen
     }
 
-    callback(service, validated_cbdata);
-    done = TRUE;
+    return g;
 }
 
-Adaptation::ServicePointer
-Adaptation::AccessCheck::findBestService(AccessRule &r, bool preferUp)
+/** Returns true iff the rule's service group will be used after ACL matches.
+    Used to detect rules worth ACl-checking. */
+bool
+Adaptation::AccessCheck::isCandidate(AccessRule &r)
 {
+    debugs(93,7,HERE << "checking candidacy of " << r.id << ", group " <<
+        r.groupId);
 
-    const char *what = preferUp ? "up " : "";
-    debugs(93,7,HERE << "looking for the first matching " <<
-           what << "service in group " << r.groupId);
-
-    ServicePointer secondBest;
-
-    ServiceGroup *g = FindGroup(r.groupId);
+    ServiceGroupPointer g = FindGroup(r.groupId);
 
     if (!g) {
-        debugs(93,5,HERE << "lost " << r.groupId << " group in rule" << r.id);
-        return ServicePointer();
-    }
-
-    ServiceGroup::Loop loop(g->initialServices());
-    typedef ServiceGroup::iterator SGI;
-    for (SGI i = loop.begin; i != loop.end; ++i) {
-
-        ServicePointer service = FindService(*i);
-
-        if (!service)
-            continue;
-
-        if (method != service->cfg().method)
-            continue;
-
-        if (point != service->cfg().point)
-            continue;
-
-        // sending a message to a broken service is likely to cause errors
-        if (service->cfg().bypass && service->broken())
-            continue;
-
-        if (service->up()) {
-            // sending a message to a service that does not want it is useless
-            // note that we cannot check wantsUrl for service that is not "up"
-            // note that even essential services are skipped on unwanted URLs!
-            if (!service->wantsUrl(req->urlpath))
-                continue;
-        } else {
-            if (!secondBest)
-                secondBest = service;
-            if (preferUp) {
-                // the caller asked for an "up" service and we can bypass this one
-                if (service->cfg().bypass)
-                    continue;
-                debugs(93,5,HERE << "cannot skip an essential down service");
-                what = "down-but-essential ";
-            }
-        }
-
-        debugs(93,5,HERE << "found first matching " <<
-               what << "service for " << r.groupId << " group in rule" << r.id <<
-               ": " << service->cfg().key);
-
-        return service;
-    }
-
-    if (secondBest != NULL) {
-        what = "down ";
-        debugs(93,5,HERE << "found first matching " <<
-               what << "service for " << r.groupId << " group in rule" << r.id <<
-               ": " << secondBest->cfg().key);
-        return secondBest;
+        debugs(93,7,HERE << "lost " << r.groupId << " group in rule" << r.id);
+        return false;
     }
 
-    debugs(93,5,HERE << "found no matching " <<
-           what << "services for " << r.groupId << " group in rule" << r.id);
-    return ServicePointer();
+    const bool wants = g->wants(filter);
+    debugs(93,7,HERE << r.groupId << (wants ? " wants" : " ignores"));
+    return wants;
 }
