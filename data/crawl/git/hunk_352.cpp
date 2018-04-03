 		else
 			printf("%06o %s %d\t", ce->ce_mode, sha1_to_hex(ce->sha1), ce_stage(ce));
 
-		utf8_fprintf(stdout, "%s\n", ce->name);
+		fprintf(stdout, "%s\n", ce->name);
 	}
 	return 0;
 }
