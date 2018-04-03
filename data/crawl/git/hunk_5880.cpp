 			NULL, NULL, rev.date_mode, 0);
 	}
 	if (write(fd, out.buf, out.len) < 0)
-		die("Writing SQUASH_MSG: %s", strerror(errno));
+		die_errno("Writing SQUASH_MSG");
 	if (close(fd))
-		die("Finishing SQUASH_MSG: %s", strerror(errno));
+		die_errno("Finishing SQUASH_MSG");
 	strbuf_release(&out);
 }
 
