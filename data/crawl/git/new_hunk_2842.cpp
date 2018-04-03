
	for_each_string_list_item(cas_option, &cas_options)
		set_helper_option(transport, "cas", cas_option->string);
	set_common_push_options(transport, data->name, flags);

	strbuf_addch(&buf, '\n');
	sendline(data, &buf);
