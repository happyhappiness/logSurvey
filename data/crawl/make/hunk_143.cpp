     buffer = AllocMem (len, MEMF_ANY);
 
     if (!buffer)
-      fatal (NILF, "MyExecute: Cannot allocate space for calling a command");
+      O (fatal, NILF, "MyExecute: Cannot allocate space for calling a command\n");
 
     ptr = buffer;
 
