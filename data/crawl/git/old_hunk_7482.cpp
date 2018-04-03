	}

	if (!value)
		return error("%s: lacks value", var);
	drv->cmd = strdup(value);
	return 0;
}