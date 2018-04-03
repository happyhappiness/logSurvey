 		);
 	} else {
 	    fprintf(fp,
-		"\t\tparse_%s(&%s);\n",
-		entry->type, entry->loc
+		"\t\tparse_%s(&%s%s);\n",
+		entry->type, entry->loc,
+		entry->array_flag ? "[0]" : ""
 		);
 	}
 	if (entry->ifdef)
