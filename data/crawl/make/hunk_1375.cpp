 		if (i > 0)
 		  {
 		    if (buffer[i - 1] == '\n')
-		      buffer[--i] = '\0';
+		      {
+			if (i > 1 && buffer[i - 2] == '\r')
+			  --i;
+			buffer[--i] = '\0';
+		      }
 		    else
 		      buffer[i] = '\0';
+
 		    p = buffer;
-		    while ((p = index (p, '\n')) != 0)
-		      *p++ = ' ';
+		    for (p2=p; *p != '\0'; ++p)
+		      {
+			if (p[0] == '\r' && p[1] == '\n')
+			  continue;
+			if (*p == '\n')
+			  *p2++ = ' ';
+			else
+			  *p2++ = *p;
+		      }
+		    *p2 = '\0';
 		    o = variable_buffer_output (o, buffer, i);
 		  }
 	      }
 
 	    free (buffer);
 	  }
-#else	/* Amiga */
+#else   /* Amiga */
 	 {
 	   /* Amiga can't fork nor spawn, but I can start a program with
-	      redirection of my choice.   However, this means that we
+	      redirection of my choice.  However, this means that we
 	      don't have an opportunity to reopen stdout to trap it.  Thus,
 	      we save our own stdout onto a new descriptor and dup a temp
 	      file's descriptor onto our stdout temporarily.  After we
 	      spawn the shell program, we dup our own stdout back to the
 	      stdout descriptor.  The buffer reading is the same as above,
-	      except that we're now reading from a file. */
+	      except that we're now reading from a file.  */
 #include <dos/dos.h>
 #include <proto/dos.h>
 
