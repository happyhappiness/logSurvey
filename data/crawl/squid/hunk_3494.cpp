     t = mp.uordblks + mp.usmblks + mp.hblkhd;
 
     fprintf(debug_log, "\tTotal in use:          %6d KB %d%%\n",
-            t >> 10, percent(t, mp.arena));
+            t >> 10, Math::intPercent(t, mp.arena));
 
     t = mp.fsmblks + mp.fordblks;
 
     fprintf(debug_log, "\tTotal free:            %6d KB %d%%\n",
-            t >> 10, percent(t, mp.arena));
+            t >> 10, Math::intPercent(t, mp.arena));
 
 #if HAVE_STRUCT_MALLINFO_MXFAST
 
