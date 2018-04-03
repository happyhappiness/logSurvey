 		die("repository '%s' not found", url);
 	case HTTP_NOAUTH:
 		show_http_message(&type, &buffer);
-		die("Authentication failed");
+		die("Authentication failed for '%s'", url);
 	default:
 		show_http_message(&type, &buffer);
-		http_error(refs_url, http_ret);
+		http_error(url, http_ret);
 		die("HTTP request failed");
 	}
 