 	}
 	refs_url = strbuf_detach(&buffer, NULL);
 
-	http_ret = http_get_strbuf(refs_url, &type, &buffer, HTTP_NO_CACHE);
+	http_ret = http_get_strbuf(refs_url, &type, &buffer,
+				   HTTP_NO_CACHE | HTTP_KEEP_ERROR);
 	switch (http_ret) {
 	case HTTP_OK:
 		break;
 	case HTTP_MISSING_TARGET:
+		show_http_message(&type, &buffer);
 		die("%s not found: did you run git update-server-info on the"
 		    " server?", refs_url);
 	case HTTP_NOAUTH:
+		show_http_message(&type, &buffer);
 		die("Authentication failed");
 	default:
+		show_http_message(&type, &buffer);
 		http_error(refs_url, http_ret);
 		die("HTTP request failed");
 	}