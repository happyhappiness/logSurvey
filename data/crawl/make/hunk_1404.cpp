 
 	    free (buffer);
 	  }
-#else	/* MSDOS or Amiga */
-#ifndef _AMIGA
-         {
-	   /* MS-DOS can't do fork, but it can do spawn.  However, this
-	      means that we don't have an opportunity to reopen stdout to
-	      trap it.  Thus, we save our own stdout onto a new descriptor
-	      and dup a temp file's descriptor onto our stdout temporarily.
-	      After we spawn the shell program, we dup our own stdout back
-	      to the stdout descriptor.  The buffer reading is the same as
-	      above, except that we're now reading from a file.  */
-
-	   int save_stdout;
-	   int child_stdout;
-	   char tmp_output[FILENAME_MAX];
-	   FILE *child_stream;
-	   unsigned int maxlen = 200;
-	   int cc;
-	   char *buffer;
-
-	   strcpy (tmp_output, "shXXXXXX");
-	   mktemp (tmp_output);
-	   child_stdout = open (tmp_output,
-				O_WRONLY|O_CREAT|O_TRUNC|O_TEXT, 0644);
-	   save_stdout = dup (1);
-	   dup2 (child_stdout, 1);
-	   spawnvp (P_WAIT, argv[0], argv);
-	   dup2 (save_stdout, 1);
-	   close (child_stdout);
-	   close (save_stdout);
-
-	   child_stdout = open (tmp_output, O_RDONLY|O_TEXT, 0644);
-
-	   buffer = xmalloc (maxlen);
-	   i = 0;
-	   do
-	     {
-	       if (i == maxlen)
-		 {
-		   maxlen += 512;
-		   buffer = (char *) xrealloc (buffer, maxlen + 1);
-		 }
-
-	       cc = read (child_stdout, &buffer[i], maxlen - i);
-	       if (cc > 0)
-		 i += cc;
-	     } while (cc > 0);
-
-	   close (child_stdout);
-	   unlink (tmp_output);
-
-	   if (i > 0)
-	     {
-	       if (buffer[i - 1] == '\n')
-		 buffer[--i] = '\0';
-	       else
-		 buffer[i] = '\0';
-	       p = buffer;
-	       while ((p = index (p, '\n')) != 0)
-		 *p++ = ' ';
-	       o = variable_buffer_output (o, buffer, i);
-	     }
-	   free (buffer);
-	 }
-#else /* Amiga */
+#else	/* Amiga */
 	 {
 	   /* Amiga can't fork nor spawn, but I can start a program with
-	      redirection of my choice. The rest is the same as above. */
+	      redirection of my choice.   However, this means that we
+	      don't have an opportunity to reopen stdout to trap it.  Thus,
+	      we save our own stdout onto a new descriptor and dup a temp
+	      file's descriptor onto our stdout temporarily.  After we
+	      spawn the shell program, we dup our own stdout back to the
+	      stdout descriptor.  The buffer reading is the same as above,
+	      except that we're now reading from a file. */
 #include <dos/dos.h>
 #include <proto/dos.h>
 
