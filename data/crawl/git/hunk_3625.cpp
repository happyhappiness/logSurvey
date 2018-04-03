 		char errbuf[1024];
 		regerror(err, &regex, errbuf, 1024);
 		regfree(&regex);
-		die("invalid log-grep regex: %s", errbuf);
+		die("invalid regex: %s", errbuf);
 	}
 
 	pickaxe(&diff_queued_diff, o, &regex, NULL, diff_grep);
