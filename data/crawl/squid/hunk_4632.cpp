     Must(state.serviceWaiting);
     state.serviceWaiting = false;
 
-    Must(service().up());
-
-    startWriting();
+    if (service().up()) {
+        startWriting();
+    } else {
+        disableRetries();
+        mustStop("ICAP service unusable");
+    }
 
     ICAPXaction_Exit();
 }
 
 void ICAPModXact::startWriting()
 {
     state.writing = State::writingConnect;
+
+    decideOnPreview(); // must be decided before we decideOnRetries
+    decideOnRetries();
+
     openConnection();
     // put nothing here as openConnection calls commConnectStart
     // and that may call us back without waiting for the next select loop
