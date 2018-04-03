 		sort_string_list(&list);
 		for (i = 0; i < list.nr; i++) {
 			struct string_list_item *item = list.items + i;
-			printf("%s%s%s\n", item->string,
-				verbose ? "\t" : "",
-				verbose && item->util ?
-					(const char *)item->util : "");
+			if (verbose)
+				printf("%s\t%s\n", item->string,
+					item->util ? (const char *)item->util : "");
+			else {
+				if (i && !strcmp((item - 1)->string, item->string))
+					continue;
+				printf("%s\n", item->string);
+			}
 		}
 	}
 	return result;