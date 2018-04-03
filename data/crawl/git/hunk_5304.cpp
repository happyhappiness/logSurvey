 			ret = HTTP_OK;
 		else if (missing_target(&results))
 			ret = HTTP_MISSING_TARGET;
-		else
+		else if (results.http_code == 401) {
+			if (user_name) {
+				ret = HTTP_NOAUTH;
+			} else {
+				/*
+				 * git_getpass is needed here because its very likely stdin/stdout are
+				 * pipes to our parent process.  So we instead need to use /dev/tty,
+				 * but that is non-portable.  Using git_getpass() can at least be stubbed
+				 * on other platforms with a different implementation if/when necessary.
+				 */
+				user_name = xstrdup(git_getpass("Username: "));
+				init_curl_http_auth(slot->curl);
+				ret = HTTP_REAUTH;
+			}
+		} else
 			ret = HTTP_ERROR;
 	} else {
 		error("Unable to start HTTP request for %s", url);
