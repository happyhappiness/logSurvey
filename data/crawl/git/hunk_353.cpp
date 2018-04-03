 		return 1;
 
 	for_each_string_list_item(item, &suc.projectlines)
-		utf8_fprintf(stdout, "%s", item->string);
+		fprintf(stdout, "%s", item->string);
 
 	return 0;
 }