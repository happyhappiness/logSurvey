 	state.num_parent = num_parent;
 	state.n = n;
 
-	xdi_diff_outf(&parent_file, result_file, consume_line, &state,
-		      &xpp, &xecfg);
+	if (xdi_diff_outf(&parent_file, result_file, consume_line, &state,
+			  &xpp, &xecfg))
+		die("unable to generate combined diff for %s",
+		    sha1_to_hex(parent));
 	free(parent_file.ptr);
 
 	/* Assign line numbers for this parent.
