 	}
 	string_list_clear(&skipped, 0);
 
+	if (!result) {
+		strbuf_addf(&buf, "remote.%s", remote->name);
+		if (git_config_rename_section(buf.buf, NULL) < 1)
+			return error(_("Could not remove config section '%s'"), buf.buf);
+	}
+
 	return result;
 }
 