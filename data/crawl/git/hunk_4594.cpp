 		strbuf_addstr(&filename, output_directory);
 		if (filename.len >=
 		    PATH_MAX - FORMAT_PATCH_NAME_MAX - suffix_len)
-			return error("name of output directory is too long");
+			return error(_("name of output directory is too long"));
 		if (filename.buf[filename.len - 1] != '/')
 			strbuf_addch(&filename, '/');
 	}
