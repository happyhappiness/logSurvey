 		add_to_ref_list(sha1, isspace(delim) ?
 				buffer + 41 + offset : "", list);
 	}
+	fpos = ftell(ffd);
+	fclose(ffd);
+	fd = open(path, O_RDONLY);
+	if (fd < 0)
+		return error("could not open '%s'", path);
+	lseek(fd, fpos, SEEK_SET);
 	return fd;
 }
 