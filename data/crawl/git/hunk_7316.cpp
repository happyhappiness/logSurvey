 			if (rename(idx_tmp_name, tmpname))
 				die("unable to rename temporary index file: %s",
 				    strerror(errno));
+
 			free(idx_tmp_name);
 			free(pack_tmp_name);
 			puts(sha1_to_hex(sha1));
