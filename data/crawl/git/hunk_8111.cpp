 			die("input format error: %s", sb.buf);
 		ptr = ntr + 1; /* type */
 		ntr = strchr(ptr, ' ');
-		if (!ntr || sb.buf + len <= ntr + 41 ||
+		if (!ntr || sb.buf + sb.len <= ntr + 40 ||
 		    ntr[41] != '\t' ||
 		    get_sha1_hex(ntr + 1, sha1))
 			die("input format error: %s", sb.buf);
