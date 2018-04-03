 {
 #if HAVE_MALLINFO
     struct mallinfo mp;
-
+    int t;
     if (!do_mallinfo)
 	return;
-
     mp = mallinfo();
-
-    fprintf(f, "Malloc Instrumentation via mallinfo(): \n");
-    fprintf(f, "   total space in arena  %d\n", mp.arena);
-    fprintf(f, "   number of ordinary blocks  %d\n", mp.ordblks);
-    fprintf(f, "   number of small blocks  %d\n", mp.smblks);
-    fprintf(f, "   number of holding blocks  %d\n", mp.hblks);
-    fprintf(f, "   space in holding block headers  %d\n", mp.hblkhd);
-    fprintf(f, "   space in small blocks in use  %d\n", mp.usmblks);
-    fprintf(f, "   space in free blocks  %d\n", mp.fsmblks);
-    fprintf(f, "   space in ordinary blocks in use  %d\n", mp.uordblks);
-    fprintf(f, "   space in free ordinary blocks  %d\n", mp.fordblks);
-    fprintf(f, "   cost of enabling keep option  %d\n", mp.keepcost);
+    fprintf(f, "Memory usage for %s via mallinfo():\n", appname);
+    fprintf(f, "\ttotal space in arena:  %6d KB\n",
+	mp.arena >> 10);
+    fprintf(f, "\tOrdinary blocks:       %6d KB %6d blks\n",
+	mp.uordblks >> 10, mp.ordblks);
+    fprintf(f, "\tSmall blocks:          %6d KB %6d blks\n",
+	mp.usmblks >> 10, mp.smblks);
+    fprintf(f, "\tHolding blocks:        %6d KB %6d blks\n",
+	mp.hblkhd >> 10, mp.hblks);
+    fprintf(f, "\tFree Small blocks:     %6d KB\n",
+	mp.fsmblks >> 10);
+    fprintf(f, "\tFree Ordinary blocks:  %6d KB\n",
+	mp.fordblks >> 10);
+    t = mp.uordblks + mp.usmblks + mp.hblkhd;
+    fprintf(f, "\tTotal in use:          %6d KB %d%%\n",
+	t >> 10, percent(t, mp.arena));
+    t = mp.fsmblks + mp.fordblks;
+    fprintf(f, "\tTotal free:            %6d KB %d%%\n",
+	t >> 10, percent(t, mp.arena));
+#ifdef WE_DONT_USE_KEEP
+    fprintf(f, "\tKeep option:           %6d KB\n",
+	mp.keepcost >> 10);
+#endif
 #if HAVE_EXT_MALLINFO
-    fprintf(f, "   max size of small blocks  %d\n", mp.mxfast);
-    fprintf(f, "   number of small blocks in a holding block  %d\n",
+    fprintf(f, "\tmax size of small blocks:\t%d\n",
+	mp.mxfast);
+    fprintf(f, "\tnumber of small blocks in a holding block:\t%d\n",
 	mp.nlblks);
-    fprintf(f, "   small block rounding factor  %d\n", mp.grain);
-    fprintf(f, "   space (including overhead) allocated in ord. blks  %d\n",
+    fprintf(f, "\tsmall block rounding factor:\t%d\n",
+	mp.grain);
+    fprintf(f, "\tspace (including overhead) allocated in ord. blks:\t%d\n",
 	mp.uordbytes);
-    fprintf(f, "   number of ordinary blocks allocated  %d\n",
+    fprintf(f, "\tnumber of ordinary blocks allocated:\t%d\n",
 	mp.allocated);
-    fprintf(f, "   bytes used in maintaining the free tree  %d\n",
+    fprintf(f, "\tbytes used in maintaining the free tree:\t%d\n",
 	mp.treeoverhead);
 #endif /* HAVE_EXT_MALLINFO */
-
 #if PRINT_MMAP
     mallocmap();
 #endif /* PRINT_MMAP */
 #endif /* HAVE_MALLINFO */
 }
+
 static int PrintRusage(f, lf)
      void (*f) ();
      FILE *lf;
 {
-#if HAVE_RUSAGE && defined(RUSAGE_SELF)
+#if HAVE_GETRUSAGE && defined(RUSAGE_SELF)
     struct rusage rusage;
     getrusage(RUSAGE_SELF, &rusage);
-    fprintf(lf, "CPU Usage: user %d sys %d\nMemory Usage: rss %d KB\n",
-	rusage.ru_utime.tv_sec, rusage.ru_stime.tv_sec,
-	rusage.ru_maxrss * getpagesize() / 1000);
-    fprintf(lf, "Page faults with physical i/o: %d\n",
+    fprintf(lf, "CPU Usage: user %d sys %d\n",
+	(int) rusage.ru_utime.tv_sec, (int) rusage.ru_stime.tv_sec);
+    fprintf(lf, "Memory Usage: rss %ld KB\n",
+	rusage.ru_maxrss * getpagesize() >> 10);
+    fprintf(lf, "Page faults with physical i/o: %ld\n",
 	rusage.ru_majflt);
 #endif
     dumpMallocStats(lf);
