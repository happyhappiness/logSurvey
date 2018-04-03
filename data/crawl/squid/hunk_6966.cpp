 #endif /* HAVE_MALLINFO */
 }
 
-static void
-PrintRusage(void)
+void
+squid_getrusage(struct rusage *r)
 {
 #if HAVE_GETRUSAGE && defined(RUSAGE_SELF)
-    struct rusage rusage;
 #ifdef _SQUID_SOLARIS_
     /* Solaris 2.5 has getrusage() permission bug -- Arjan de Vet */
     enter_suid();
 #endif
-    getrusage(RUSAGE_SELF, &rusage);
+    getrusage(RUSAGE_SELF, r);
 #ifdef _SQUID_SOLARIS_
     leave_suid();
 #endif
-    fprintf(debug_log, "CPU Usage: user %d sys %d\n",
-	(int) rusage.ru_utime.tv_sec, (int) rusage.ru_stime.tv_sec);
-#if defined(_SQUID_SGI_) || defined(_SQUID_OSF_) || defined(BSD4_4)
-    fprintf(debug_log, "Maximum Resident Size: %ld KB\n", rusage.ru_maxrss);
-#else /* _SQUID_SGI_ */
-    fprintf(debug_log, "Maximum Resident Size: %ld KB\n",
-	(rusage.ru_maxrss * getpagesize()) >> 10);
-#endif /* _SQUID_SGI_ */
-    fprintf(debug_log, "Page faults with physical i/o: %ld\n",
-	rusage.ru_majflt);
-#endif /* HAVE_GETRUSAGE */
+#else
+    memset(r, '\0', sizeof(struct rusage));
+#endif
+}
+
+double
+rusage_cputime(struct rusage *r)
+{
+    return (double) r->ru_stime.tv_sec +
+	(double) r->ru_utime.tv_sec +
+	(double) r->ru_stime.tv_usec / 1000000.0 +
+	(double) r->ru_utime.tv_usec / 1000000.0;
+}
+
+int
+rusage_maxrss(struct rusage *r)
+{
+#if defined(_SQUID_SGI_)
+    return r->ru_maxrss;
+#elif defined(_SQUID_OSF_)
+    return r->ru_maxrss;
+#elif defined(BSD4_4)
+    return r->ru_maxrss;
+#else
+    return (r->ru_maxrss * getpagesize()) >> 10;
+#endif
+}
+
+int
+rusage_pagefaults(struct rusage *r)
+{
+    return r->ru_majflt;
+}
+
+
+static void
+PrintRusage(void)
+{
+    struct rusage rusage;
+    squid_getrusage(&rusage);
+    fprintf(debug_log, "CPU Usage: %.3f seconds\n", rusage_cputime(&rusage));
+    fprintf(debug_log, "Maximum Resident Size: %d KB\n",
+	rusage_maxrss(&rusage));
+    fprintf(debug_log, "Page faults with physical i/o: %d\n",
+	rusage_pagefaults(&rusage));
 }
 
 
