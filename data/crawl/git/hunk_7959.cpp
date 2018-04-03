 	if (run_command(&child))
 		die("There was a problem with the editor %s.", editor);
 
-	fd = open(path, O_RDONLY);
-	if (fd < 0)
-		die("could not open '%s': %s", path, strerror(errno));
-	if (strbuf_read(buffer, fd, 0) < 0) {
-		die("could not read message file '%s': %s", path, strerror(errno));
-	}
-	close(fd);
+	if (strbuf_read_file(buffer, path) < 0)
+		die("could not read message file '%s': %s",
+		    path, strerror(errno));
 }
 
 struct tag_filter {
