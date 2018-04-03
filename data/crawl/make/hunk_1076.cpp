 #ifdef _AMIGA
   remove_intermediates (1);
   if (sig == SIGINT)
-     fputs ("*** Break.\n", stderr);
+     fputs (_("*** Break.\n"), stderr);
 
   exit (10);
 #else /* not Amiga */
