 	int argc;
 	int err;
 
+	if (flags & TRANSPORT_PUSH_MIRROR)
+		return error("http transport does not support mirror mode");
+
 	argv = xmalloc((refspec_nr + 11) * sizeof(char *));
 	argv[0] = "http-push";
 	argc = 1;
