         parseBody();
 }
 
-void ICAPModXact::callException(const std::exception &e)
+void Adaptation::Icap::ModXact::callException(const std::exception &e)
 {
     if (!canStartBypass || isRetriable) {
-        ICAPXaction::callException(e);
+        Adaptation::Icap::Xaction::callException(e);
         return;
     }
 
     try {
-        debugs(93, 3, "bypassing ICAPModXact::" << inCall << " exception: " <<
-               e.what() << ' ' << status());
+        debugs(93, 3, HERE << "bypassing " << inCall << " exception: " <<
+            e.what() << ' ' << status());
         bypassFailure();
     } catch (const std::exception &bypassE) {
-        ICAPXaction::callException(bypassE);
+        Adaptation::Icap::Xaction::callException(bypassE);
     }
 }
 
-void ICAPModXact::bypassFailure()
+void Adaptation::Icap::ModXact::bypassFailure()
 {
     disableBypass("already started to bypass");
 
