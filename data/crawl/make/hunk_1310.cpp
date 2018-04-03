 	     because there was no preceding target, and the line
 	     might have been usable as a variable definition.
 	     But now it is definitely lossage.  */
-	  makefile_fatal (filename, lineno,
+	  fatal (&fileinfo,
 			  "commands commence before first target");
 	}
       else
