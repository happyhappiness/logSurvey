 	l_item->e = e;
 	l_item->value_index = e->value_list.nr - 1;
 
-	if (cf) {
+	if (!cf)
+		die("BUG: configset_add_value has no source");
+	if (cf->name) {
 		kv_info->filename = strintern(cf->name);
 		kv_info->linenr = cf->linenr;
 	} else {
