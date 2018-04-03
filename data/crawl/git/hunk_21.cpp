 			return -1;
 		return 0;
 	} else if (!strcmp(name, "push-option")) {
-		string_list_append(&options.push_options, value);
+		if (*value != '"')
+			string_list_append(&options.push_options, value);
+		else {
+			struct strbuf unquoted = STRBUF_INIT;
+			if (unquote_c_style(&unquoted, value, NULL) < 0)
+				die("invalid quoting in push-option value");
+			string_list_append_nodup(&options.push_options,
+						 strbuf_detach(&unquoted, NULL));
+		}
 		return 0;
 
 #if LIBCURL_VERSION_NUM >= 0x070a08
