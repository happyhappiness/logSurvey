 		if (n > 0 && fwrite (buf, 1, n, outfile) != n)
 		  pfatal_with_name ("fwrite (temporary file)");
 	      }
-	    /* Try to make sure we won't remake the temporary
-	       file when we are re-exec'd.  Kludge-o-matic!  */
-	    fprintf (outfile, "%s:;\n", name);
 	    (void) fclose (outfile);
 
 	    /* Replace the name that read_all_makefiles will
