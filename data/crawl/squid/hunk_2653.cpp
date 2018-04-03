     FDNOUT=fdopen(pnout[0],"r");
 
     if (!FDKIN || !FDKOUT || !FDNIN || !FDNOUT) {
-        fprintf(stderr, "%s| %s: Could not assign streams for FDKIN/FDKOUT/FDNIN/FDNOUT %d/%d/%d/%d\n",
-                LogTime(), PROGRAM, FDKIN, FDKOUT, FDNIN, FDNOUT);
+        fprintf(stderr, "%s| %s: Could not assign streams for FDKIN/FDKOUT/FDNIN/FDNOUT\n", LogTime(), PROGRAM);
         return 1;
     }
 
