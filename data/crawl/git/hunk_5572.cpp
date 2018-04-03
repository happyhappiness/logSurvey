 			break;
 		if (!prefixcmp(buf.buf, "fetch ")) {
 			char *obj = buf.buf + strlen("fetch ");
+			if (nongit)
+				die("Fetch attempted without a local repo");
 			if (!walker)
 				walker = get_http_walker(url, remote);
 			walker->get_all = 1;