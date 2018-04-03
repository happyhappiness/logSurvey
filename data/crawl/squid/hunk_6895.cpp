 		entry->type, entry->loc
 		);
 	}
+	if (entry->ifdef)
+	    fprintf(fp, "#endif\n");
     }
 
     fprintf(fp,
