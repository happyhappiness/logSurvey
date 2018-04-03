     // should be configurable.
 }
 
-void ICAPServiceRep::suspend(const char *reason)
+void Adaptation::Icap::ServiceRep::suspend(const char *reason)
 {
     if (isSuspended) {
-        debugs(93,4, "keeping ICAPService suspended, also for " << reason);
+        debugs(93,4, HERE << "keeping suspended, also for " << reason);
     } else {
         isSuspended = reason;
-        debugs(93,1, "suspending ICAPService for " << reason);
-        scheduleUpdate(squid_curtime + TheICAPConfig.service_revival_delay);
+        debugs(93,1, "suspending ICAP service for " << reason);
+        scheduleUpdate(squid_curtime + TheConfig.service_revival_delay);
         announceStatusChange("suspended", true);
     }
 }
 
-bool ICAPServiceRep::probed() const
+bool Adaptation::Icap::ServiceRep::probed() const
 {
     return theLastUpdate != 0;
 }
 
-bool ICAPServiceRep::hasOptions() const
+bool Adaptation::Icap::ServiceRep::hasOptions() const
 {
     return theOptions && theOptions->valid() && theOptions->fresh();
 }
 
-bool ICAPServiceRep::up() const
+bool Adaptation::Icap::ServiceRep::up() const
 {
     return self != NULL && !isSuspended && hasOptions();
 }
 
-bool ICAPServiceRep::wantsUrl(const String &urlPath) const
+bool Adaptation::Icap::ServiceRep::wantsUrl(const String &urlPath) const
 {
     Must(hasOptions());
-    return theOptions->transferKind(urlPath) != ICAPOptions::xferIgnore;
+    return theOptions->transferKind(urlPath) != Adaptation::Icap::Options::xferIgnore;
 }
 
-bool ICAPServiceRep::wantsPreview(const String &urlPath, size_t &wantedSize) const
+bool Adaptation::Icap::ServiceRep::wantsPreview(const String &urlPath, size_t &wantedSize) const
 {
     Must(hasOptions());
 
     if (theOptions->preview < 0)
         return false;
 
-    if (theOptions->transferKind(urlPath) != ICAPOptions::xferPreview)
+    if (theOptions->transferKind(urlPath) != Adaptation::Icap::Options::xferPreview)
         return false;
 
     wantedSize = theOptions->preview;
 
     return true;
 }
 
-bool ICAPServiceRep::allows204() const
+bool Adaptation::Icap::ServiceRep::allows204() const
 {
     Must(hasOptions());
     return true; // in the future, we may have ACLs to prevent 204s
 }
 
 
 static
-void ICAPServiceRep_noteTimeToUpdate(void *data)
+void ServiceRep_noteTimeToUpdate(void *data)
 {
-    ICAPServiceRep *service = static_cast<ICAPServiceRep*>(data);
+    Adaptation::Icap::ServiceRep *service = static_cast<Adaptation::Icap::ServiceRep*>(data);
     Must(service);
     service->noteTimeToUpdate();
 }
 
-void ICAPServiceRep::noteTimeToUpdate()
+void Adaptation::Icap::ServiceRep::noteTimeToUpdate()
 {
     if (self != NULL)
         updateScheduled = false;
 
     if (!self || theOptionsFetcher) {
-        debugs(93,5, "ICAPService ignores options update " << status());
+        debugs(93,5, HERE << "ignores options update " << status());
         return;
     }
 
-    debugs(93,5, "ICAPService performs a regular options update " << status());
+    debugs(93,5, HERE << "performs a regular options update " << status());
     startGettingOptions();
 }
 
 #if 0
 static
-void ICAPServiceRep_noteTimeToNotify(void *data)
+void Adaptation::Icap::ServiceRep_noteTimeToNotify(void *data)
 {
-    ICAPServiceRep *service = static_cast<ICAPServiceRep*>(data);
+    Adaptation::Icap::ServiceRep *service = static_cast<Adaptation::Icap::ServiceRep*>(data);
     Must(service);
     service->noteTimeToNotify();
 }
 #endif
 
-void ICAPServiceRep::noteTimeToNotify()
+void Adaptation::Icap::ServiceRep::noteTimeToNotify()
 {
     Must(!notifying);
     notifying = true;
-    debugs(93,7, "ICAPService notifies " << theClients.size() << " clients " <<
+    debugs(93,7, HERE << "notifies " << theClients.size() << " clients " <<
            status());
 
     // note: we must notify even if we are invalidated
