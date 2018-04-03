 	return ret;
 }
 
+void set_diffopt_flags_from_submodule_config(struct diff_options *diffopt,
+					     const char *path)
+{
+	struct string_list_item *path_option, *ignore_option;
+	path_option = unsorted_string_list_lookup(&config_name_for_path, path);
+	if (path_option) {
+		ignore_option = unsorted_string_list_lookup(&config_ignore_for_name, path_option->util);
+		if (ignore_option)
+			handle_ignore_submodules_arg(diffopt, ignore_option->util);
+	}
+}
+
+int parse_submodule_config_option(const char *var, const char *value)
+{
+	int len;
+	struct string_list_item *config;
+	struct strbuf submodname = STRBUF_INIT;
+
+	var += 10;		/* Skip "submodule." */
+
+	len = strlen(var);
+	if ((len > 5) && !strcmp(var + len - 5, ".path")) {
+		strbuf_add(&submodname, var, len - 5);
+		config = unsorted_string_list_lookup(&config_name_for_path, value);
+		if (config)
+			free(config->util);
+		else
+			config = string_list_append(&config_name_for_path, xstrdup(value));
+		config->util = strbuf_detach(&submodname, NULL);
+		strbuf_release(&submodname);
+	} else if ((len > 7) && !strcmp(var + len - 7, ".ignore")) {
+		if (strcmp(value, "untracked") && strcmp(value, "dirty") &&
+		    strcmp(value, "all") && strcmp(value, "none")) {
+			warning("Invalid parameter \"%s\" for config option \"submodule.%s.ignore\"", value, var);
+			return 0;
+		}
+
+		strbuf_add(&submodname, var, len - 7);
+		config = unsorted_string_list_lookup(&config_ignore_for_name, submodname.buf);
+		if (config)
+			free(config->util);
+		else
+			config = string_list_append(&config_ignore_for_name,
+						    strbuf_detach(&submodname, NULL));
+		strbuf_release(&submodname);
+		config->util = xstrdup(value);
+		return 0;
+	}
+	return 0;
+}
+
 void handle_ignore_submodules_arg(struct diff_options *diffopt,
 				  const char *arg)
 {
