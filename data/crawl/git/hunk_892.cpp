 		usage(index_pack_usage);
 	if (fix_thin_pack && !from_stdin)
 		die(_("--fix-thin cannot be used without --stdin"));
+	if (from_stdin && !startup_info->have_repository)
+		die(_("--stdin requires a git repository"));
 	if (!index_name && pack_name)
 		index_name = derive_filename(pack_name, ".idx", &index_name_buf);
 	if (keep_msg && !keep_name && pack_name)