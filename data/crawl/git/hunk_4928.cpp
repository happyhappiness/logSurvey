 		*val++ = '\0';
 		key = pool_intern(t);
 
-		if (key == keys.uuid) {
+		if (key == keys.svn_fs_dump_format_version) {
+			dump_ctx.version = atoi(val);
+			if (dump_ctx.version > 2)
+				die("expected svn dump format version <= 2, found %d",
+				    dump_ctx.version);
+		} else if (key == keys.uuid) {
 			dump_ctx.uuid = pool_intern(val);
 		} else if (key == keys.revision_number) {
 			if (active_ctx == NODE_CTX)