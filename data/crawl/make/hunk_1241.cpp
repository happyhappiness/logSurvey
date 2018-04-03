 	     because there was no preceding target, and the line
 	     might have been usable as a variable definition.
 	     But now it is definitely lossage.  */
-	  fatal (&fileinfo,
-			  "commands commence before first target");
+	  fatal(&fileinfo, "commands commence before first target");
 	}
       else
 	{
