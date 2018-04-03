 	}
 
 	if (freq->localfile < 0) {
-		error("Couldn't create temporary file %s: %s",
-		      freq->tmpfile, strerror(errno));
+		error_errno("Couldn't create temporary file %s", freq->tmpfile);
 		goto abort;
 	}
 
