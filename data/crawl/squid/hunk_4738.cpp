     debugs(93, 4, typeName << "::" << inCall << " caught an exception: " <<
            e.message << ' ' << status());
 
-    if (!done())
-        mustStop("exception");
+    reuseConnection = false; // be conservative
+    mustStop("exception");
 }
 
 void ICAPXaction::callEnd()
