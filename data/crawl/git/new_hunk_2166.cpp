#undef config_error_nonbool
int config_error_nonbool(const char *var)
{
	return error("missing value for '%s'", var);
}

int parse_config_key(const char *var,