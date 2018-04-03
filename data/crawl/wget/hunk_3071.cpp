     }
 
   printf (_("Continuing in background, pid %lu.\n"), pi.dwProcessId);
-  if (info->changedp)
+  if (info->logfile_changed)
     printf (_("Output will be written to `%s'.\n"), info->lfilename);
 
   UnmapViewOfFile (info);
