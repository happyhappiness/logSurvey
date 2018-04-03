 
       /* create batch file to execute command */
       batch = fopen (*batch_filename_ptr, "w");
-      fputs ("@echo off\n", batch);
+      if (!unixy_shell)
+        fputs ("@echo off\n", batch);
       fputs (command_ptr, batch);
       fputc ('\n', batch);
       fclose (batch);
