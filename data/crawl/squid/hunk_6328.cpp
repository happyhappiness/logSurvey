 #if MEM_GEN_TRACE
     log_trace_done();
 #endif
-
     debug(1, 0) ("Squid Cache (Version %s): Exiting normally.\n",
 	version_string);
     fclose(debug_log);
     exit(0);
 }
-
-static void
-force_shutdown(void *unused)
-{
-    fdDumpOpen();
-    fatal_dump("Shutdown procedure failed");
-}
