 		old_data = NULL;
 	} else if (node_ctx.action == NODEACT_CHANGE) {
 		uint32_t mode;
-		old_data = svn_repo_read_path(node_ctx.dst.buf, &mode);
+		old_data = fast_export_read_path(node_ctx.dst.buf, &mode);
 		if (mode == S_IFDIR && type != S_IFDIR)
 			die("invalid dump: cannot modify a directory into a file");
 		if (mode != S_IFDIR && type == S_IFDIR)