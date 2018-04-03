                 } else if (baselineBypass != service->cfg().bypass) {
                     debugs(93,0, "WARNING: Inconsistent bypass in " << kind <<
                            ' ' << id << " may produce surprising results: " <<
-                           baselineKey << " vs. " << sid);
+                           baselineKey << " vs. " << serviceId);
                 }
             }
         } else {
-            finalizeMsg("ERROR: Unknown adaptation name", sid, true);
+            finalizeMsg("ERROR: Unknown adaptation name", serviceId, true);
         }
     }
     debugs(93,7, HERE << "finalized " << kind << ": " << id);
