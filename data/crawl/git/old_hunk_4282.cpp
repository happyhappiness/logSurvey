	strbuf_trim(pair[0]);
	if (!pair[0]->len) {
		strbuf_list_free(pair);
		return -1;
	}
	ct = xcalloc(1, sizeof(struct config_item));
	ct->name = strbuf_detach(pair[0], NULL);
	if (pair[1]) {
		strbuf_trim(pair[1]);
		ct->value = strbuf_detach(pair[1], NULL);
	}
	strbuf_list_free(pair);
	lowercase(ct->name);
	*config_parameters_tail = ct;
	config_parameters_tail = &ct->next;
	return 0;
}

static int git_config_parse_environment(void) {
	const char *env = getenv(CONFIG_DATA_ENVIRONMENT);
	char *envw;
	const char **argv = NULL;
