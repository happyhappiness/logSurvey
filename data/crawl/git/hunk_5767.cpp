 {
 	const char **argv;
 	int argc;
-	int err;
 
 	if (flags & TRANSPORT_PUSH_MIRROR)
 		return error("http transport does not support mirror mode");
