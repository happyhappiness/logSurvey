 			prev_posn = 0;
 			lseek(freq->localfile, 0, SEEK_SET);
 			if (ftruncate(freq->localfile, 0) < 0) {
-				error("Couldn't truncate temporary file %s: %s",
-					  freq->tmpfile, strerror(errno));
+				error_errno("Couldn't truncate temporary file %s",
+					    freq->tmpfile);
 				goto abort;
 			}
 		}