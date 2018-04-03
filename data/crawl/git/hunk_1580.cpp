 		*value = STATUS_FORMAT_PORCELAIN;
 	else if (!strcmp(arg, "v1") || !strcmp(arg, "1"))
 		*value = STATUS_FORMAT_PORCELAIN;
+	else if (!strcmp(arg, "v2") || !strcmp(arg, "2"))
+		*value = STATUS_FORMAT_PORCELAIN_V2;
 	else
 		die("unsupported porcelain version '%s'", arg);
 
