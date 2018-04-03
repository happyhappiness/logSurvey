	}

	if (!value)
		return config_error_nonbool(var);
	drv->cmd = strdup(value);
	return 0;
}