 	}
 
 	close(po.in);
+
+	if (args->stateless_rpc) {
+		char *buf = xmalloc(LARGE_PACKET_MAX);
+		while (1) {
+			ssize_t n = xread(po.out, buf, LARGE_PACKET_MAX);
+			if (n <= 0)
+				break;
+			send_sideband(fd, -1, buf, n, LARGE_PACKET_MAX);
+		}
+		free(buf);
+		close(po.out);
+		po.out = -1;
+	}
+
 	if (finish_command(&po))
 		return error("pack-objects died with strange error");
 	return 0;
