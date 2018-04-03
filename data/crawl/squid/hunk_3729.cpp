     Adaptation::Initiate::start();
 
     Must(theInitiator);
-    launchXaction(false);
+    launchXaction("first");
 }
 
-void Adaptation::Icap::Launcher::launchXaction(bool final)
+void Adaptation::Icap::Launcher::launchXaction(const char *xkind)
 {
     Must(!theXaction);
     ++theLaunches;
-    debugs(93,4, HERE << "launching xaction #" << theLaunches);
+    debugs(93,4, HERE << "launching " << xkind << " xaction #" << theLaunches);
     Adaptation::Icap::Xaction *x = createXaction();
-    if (final)
+    x->attempts = theLaunches;
+    if (theLaunches > 1)
         x->disableRetries();
+    if (theLaunches >= TheConfig.repeat_limit)
+        x->disableRepeats("over icap_retry_limit");
     theXaction = initiateAdaptation(x);
     Must(theXaction);
 }
