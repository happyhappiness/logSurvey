 			continue;
 		}
 		error("invalid parameter: expected sha1, got '%s'", arg);
+		errors_found |= ERROR_OBJECT;
 	}
 
 	/*
