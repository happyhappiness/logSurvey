 {
 	struct string_list *list = priv;
 
-	string_list_append(remote->name, list)->util = remote->url_nr ?
-		(void *)remote->url[0] : NULL;
-	if (remote->url_nr > 1)
-		warning("Remote %s has more than one URL", remote->name);
+	if (remote->url_nr > 0) {
+		int i;
+
+		for (i = 0; i < remote->url_nr; i++)
+			string_list_append(remote->name, list)->util = (void *)remote->url[i];
+	} else
+		string_list_append(remote->name, list)->util = NULL;
 
 	return 0;
 }
