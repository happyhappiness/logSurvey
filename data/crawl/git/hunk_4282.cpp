 	strbuf_trim(pair[0]);
 	if (!pair[0]->len) {
 		strbuf_list_free(pair);
-		return -1;
+		return error("bogus config parameter: %s", text);
 	}
-	ct = xcalloc(1, sizeof(struct config_item));
-	ct->name = strbuf_detach(pair[0], NULL);
-	if (pair[1]) {
-		strbuf_trim(pair[1]);
-		ct->value = strbuf_detach(pair[1], NULL);
+	lowercase(pair[0]->buf);
+	if (fn(pair[0]->buf, pair[1] ? pair[1]->buf : NULL, data) < 0) {
+		strbuf_list_free(pair);
+		return -1;
 	}
 	strbuf_list_free(pair);
-	lowercase(ct->name);
-	*config_parameters_tail = ct;
-	config_parameters_tail = &ct->next;
 	return 0;
 }
 
-static int git_config_parse_environment(void) {
+int git_config_from_parameters(config_fn_t fn, void *data)
+{
 	const char *env = getenv(CONFIG_DATA_ENVIRONMENT);
 	char *envw;
 	const char **argv = NULL;
