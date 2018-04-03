
const char *current_config_origin_type(void)
{
	const char *type;
	if (current_config_kvi)
		type = current_config_kvi->origin_type;
	else if(cf)
		type = cf->origin_type;
	else
		die("BUG: current_config_origin_type called outside config callback");
	return type ? type : "command line";
}

const char *current_config_name(void)
