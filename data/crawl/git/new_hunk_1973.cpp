	printf("value=%s\n", value ? value : "(null)");
	printf("origin=%s\n", current_config_origin_type());
	printf("name=%s\n", current_config_name());
	printf("scope=%s\n", scope_name(current_config_scope()));

	return 0;
}
