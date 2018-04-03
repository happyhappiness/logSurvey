         startWriting();
     } else {
         disableRetries();
-        mustStop("ICAP service unusable");
+        throw TexcHere("ICAP service is unusable");
     }
 
     ICAPXaction_Exit();
