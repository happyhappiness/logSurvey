 		break;
 	}
 
+#ifndef USE_CURL_MULTI
+	die("git-push is not available for http/https repository when not compiled with USE_CURL_MULTI");
+#endif
+
 	if (!remote->url)
 		usage(http_push_usage);
 