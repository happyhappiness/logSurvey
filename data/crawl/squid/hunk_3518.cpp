                 point = service->cfg().point;
             } else {
                 if (method != service->cfg().method)
-                    finalizeMsg("Inconsistent service method for", sid, true);
+                    finalizeMsg("Inconsistent service method for", serviceId, true);
                 if (point != service->cfg().point)
-                    finalizeMsg("Inconsistent vectoring point for", sid, true);
+                    finalizeMsg("Inconsistent vectoring point for", serviceId, true);
             }
 
             checkUniqueness(pos);
