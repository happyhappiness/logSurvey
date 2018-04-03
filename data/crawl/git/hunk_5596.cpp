 	return result;
 }
 
-#ifndef NO_CURL
-static int curl_transport_push(struct transport *transport, int refspec_nr, const char **refspec, int flags)
-{
-	const char **argv;
-	int argc;
-
-	if (flags & TRANSPORT_PUSH_MIRROR)
-		return error("http transport does not support mirror mode");
-
-	argv = xmalloc((refspec_nr + 12) * sizeof(char *));
-	argv[0] = "http-push";
-	argc = 1;
-	if (flags & TRANSPORT_PUSH_ALL)
-		argv[argc++] = "--all";
-	if (flags & TRANSPORT_PUSH_FORCE)
-		argv[argc++] = "--force";
-	if (flags & TRANSPORT_PUSH_DRY_RUN)
-		argv[argc++] = "--dry-run";
-	if (flags & TRANSPORT_PUSH_VERBOSE)
-		argv[argc++] = "--verbose";
-	argv[argc++] = transport->url;
-	while (refspec_nr--)
-		argv[argc++] = *refspec++;
-	argv[argc] = NULL;
-	return !!run_command_v_opt(argv, RUN_GIT_CMD);
-}
-
-#endif
-
 struct bundle_transport_data {
 	int fd;
 	struct bundle_header header;
