 		die("Authentication failed for '%s'", url);
 	default:
 		show_http_message(&type, &buffer);
-		http_error(url);
-		die("HTTP request failed");
+		die("unable to access '%s': %s", url, curl_errorstr);
 	}
 
 	last= xcalloc(1, sizeof(*last_discovery));