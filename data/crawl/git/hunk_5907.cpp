 		if (ret <= 0) {
 			if (!ret)
 				die("early EOF");
-			die("read error on input: %s", strerror(errno));
+			die_errno("read error on input");
 		}
 		input_len += ret;
 		if (from_stdin)
