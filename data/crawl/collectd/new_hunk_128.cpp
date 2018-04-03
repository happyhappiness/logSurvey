			if (parse_identifier (opt_value,
						&id->host, &id->plugin, &id->plugin_instance,
						&id->type, &id->type_instance,
						opts->identifier_default_host) != 0)
			{
				cmd_error (CMD_PARSE_ERROR, err,
						"Invalid identifier `%s'.", opt_value);
