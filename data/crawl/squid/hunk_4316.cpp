 }
 
 void
-ServerStateData::icapAclCheckDone(ICAPServiceRep::Pointer service)
+ServerStateData::adaptationAclCheckDone(Adaptation::ServicePointer service)
 {
-    icapAccessCheckPending = false;
+    adaptationAccessCheckPending = false;
 
     if (abortOnBadEntry("entry went bad while waiting for ICAP ACL check"))
         return;
