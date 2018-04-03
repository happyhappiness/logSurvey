 	discard_index(&o->result);
 	if (!o->gently) {
 		if (message)
-			return error(message);
+			return error("%s", message);
 		return -1;
 	}
 	return -1;