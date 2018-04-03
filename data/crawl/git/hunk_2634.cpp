 		   will fail first.  But just in case..
 		 */
 		if (--mi->content_top < mi->content) {
-			fprintf(stderr, "Detected mismatched boundaries, "
-					"can't recover\n");
-			exit(1);
+			error("Detected mismatched boundaries, can't recover");
+			mi->input_error = -1;
+			mi->content_top = mi->content;
+			return 0;
 		}
 		handle_filter(mi, &newline);
 		strbuf_release(&newline);
+		if (mi->input_error)
+			return 0;
 
 		/* skip to the next boundary */
 		if (!find_boundary(mi, line))
