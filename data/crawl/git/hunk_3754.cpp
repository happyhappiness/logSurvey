 	case HTTP_OK:
 		break;
 	case HTTP_MISSING_TARGET:
-		if (!show_http_message(&type, &buffer))
-			die("repository '%s' not found", url);
-		die("%s not found: did you run git update-server-info on the"
-		    " server?", refs_url);
+		show_http_message(&type, &buffer);
+		die("repository '%s' not found", url);
 	case HTTP_NOAUTH:
 		show_http_message(&type, &buffer);
 		die("Authentication failed");