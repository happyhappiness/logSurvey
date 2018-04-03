 		break;
 	}
 
-	if (!dest || i != argc - 1)
+	if (!dest)
 		usage(ls_remote_usage);
-
+	pattern = argv + i + 1;
 	remote = nongit ? NULL : remote_get(dest);
 	if (remote && !remote->url_nr)
 		die("remote %s has no configured URL", dest);
