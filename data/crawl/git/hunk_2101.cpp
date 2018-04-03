 	return 0;
 }
 
-static int module_sanitize_config(int argc, const char **argv, const char *prefix)
-{
-	struct strbuf sanitized_config = STRBUF_INIT;
-
-	if (argc > 1)
-		usage(_("git submodule--helper sanitize-config"));
-
-	git_config_from_parameters(sanitize_submodule_config, &sanitized_config);
-	if (sanitized_config.len)
-		printf("%s\n", sanitized_config.buf);
-
-	strbuf_release(&sanitized_config);
-
-	return 0;
-}
-
 struct cmd_struct {
 	const char *cmd;
 	int (*fn)(int, const char **, const char *);
