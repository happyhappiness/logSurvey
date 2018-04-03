 
 	if (keep_msg) {
 		int keep_fd, keep_msg_len = strlen(keep_msg);
-		if (!keep_name) {
-			snprintf(name, sizeof(name), "%s/pack/pack-%s.keep",
-				 get_object_directory(), sha1_to_hex(sha1));
-			keep_name = name;
-		}
-		keep_fd = open(keep_name, O_RDWR|O_CREAT|O_EXCL, 0600);
+
+		if (!keep_name)
+			keep_fd = odb_pack_keep(name, sizeof(name), sha1);
+		else
+			keep_fd = open(keep_name, O_RDWR|O_CREAT|O_EXCL, 0600);
+
 		if (keep_fd < 0) {
 			if (errno != EEXIST)
-				die("cannot write keep file");
+				die("cannot write keep file '%s' (%s)",
+				    keep_name, strerror(errno));
 		} else {
 			if (keep_msg_len > 0) {
 				write_or_die(keep_fd, keep_msg, keep_msg_len);
 				write_or_die(keep_fd, "\n", 1);
 			}
 			if (close(keep_fd) != 0)
-				die("cannot write keep file");
+				die("cannot close written keep file '%s' (%s)",
+				    keep_name, strerror(errno));
 			report = "keep";
 		}
 	}
