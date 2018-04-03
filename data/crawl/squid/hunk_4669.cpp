             storeAppendPrintf(e, " %s", srv->wccp_password);
         }
 
+        storeAppendPrintf(e, "\n");
+
         srv = srv->next;
     }
 }