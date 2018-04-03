 
         storeAppendPrintf(sentry, "\n");
     }
+
+    if (npc) {
+        storeAppendPrintf(sentry, "\nSearch list:\n");
+
+        for (i=0; i < npc; i++)
+            storeAppendPrintf(sentry, "%s\n", searchpath[i].domain);
+
+        storeAppendPrintf(sentry, "\n");
+    }
 }
 
 static void