     close(pnin[0]);
     close(pnout[1]);
 
-    FDKIN=fdopen(pkin[1],"w");
-    FDKOUT=fdopen(pkout[0],"r");
+    FILE *FDKIN=fdopen(pkin[1],"w");
+    FILE *FDKOUT=fdopen(pkout[0],"r");
 
-    FDNIN=fdopen(pnin[1],"w");
-    FDNOUT=fdopen(pnout[0],"r");
+    FILE *FDNIN=fdopen(pnin[1],"w");
+    FILE *FDNOUT=fdopen(pnout[0],"r");
 
     if (!FDKIN || !FDKOUT || !FDNIN || !FDNOUT) {
         fprintf(stderr, "%s| %s: Could not assign streams for FDKIN/FDKOUT/FDNIN/FDNOUT\n", LogTime(), PROGRAM);
+        closeFds(FDKIN, FDKOUT, FDNIN, FDNOUT);
         return 1;
     }
 
