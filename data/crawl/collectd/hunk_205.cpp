 		}
 
 		fprintf (use_stdio == 1 ? stdout : stderr,
-			 "PUTVAL %s interval=%i %s\n",
-			 filename, vl->interval, values);
+			 "PUTVAL %s interval=%.3f %s\n",
+			 filename,
+			 CDTIME_T_TO_DOUBLE (vl->interval),
+			 values);
 		return (0);
 	}
 
