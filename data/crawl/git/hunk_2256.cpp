 		if (info->remote_name && !strcmp(info->remote_name, rename.old)) {
 			strbuf_reset(&buf);
 			strbuf_addf(&buf, "branch.%s.remote", item->string);
-			if (git_config_set(buf.buf, rename.new)) {
-				return error(_("Could not set '%s'"), buf.buf);
-			}
+			git_config_set_or_die(buf.buf, rename.new);
 		}
 	}
 
