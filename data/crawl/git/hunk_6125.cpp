 		    squelch_whitespace_errors < whitespace_error) {
 			int squelched =
 				whitespace_error - squelch_whitespace_errors;
-			fprintf(stderr, "warning: squelched %d "
-				"whitespace error%s\n",
+			warning("squelched %d "
+				"whitespace error%s",
 				squelched,
 				squelched == 1 ? "" : "s");
 		}
