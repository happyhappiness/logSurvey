         }
     }
 
-    DEBUG(2)
-    fprintf(stderr, "%d diskd exiting\n", (int) mypid);
+    DEBUG(2) {
+        fprintf(stderr, "%d diskd exiting\n", (int) mypid);
+    }
 
     if (msgctl(rmsgid, IPC_RMID, 0) < 0)
         perror("msgctl IPC_RMID");
