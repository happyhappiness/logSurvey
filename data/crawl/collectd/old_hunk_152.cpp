		status = parse_string (&buffer, &string);
		if (status != 0)
		{
			print_to_socket (fh, "-1 Misformatted value.\n");
			sfree (vl.values);
			return (-1);
		}
		assert (string != NULL);

		status = parse_values (string, &vl, ds);
		if (status != 0)
		{
			print_to_socket (fh, "-1 Parsing the values string failed.\n");
			sfree (vl.values);
			return (-1);
		}

		plugin_dispatch_values (&vl);
		values_submitted++;
	} /* while (*buffer != 0) */
	/* Done parsing the options. */

	if (fh!=stdout)
		print_to_socket (fh, "0 Success: %i %s been dispatched.\n",
			values_submitted,
			(values_submitted == 1) ? "value has" : "values have");

	sfree (vl.values);
	return (0);
} /* int handle_putval */

int create_putval (char *ret, size_t ret_len, /* {{{ */
	const data_set_t *ds, const value_list_t *vl)
{
	char buffer_ident[6 * DATA_MAX_NAME_LEN];
