	if (!value)
		return config_error_nonbool(var);
	if (parse_expiry_date(value, expire))
		return error(_("'%s' for '%s' is not a valid timestamp"),
			     value, var);
	return 0;
}