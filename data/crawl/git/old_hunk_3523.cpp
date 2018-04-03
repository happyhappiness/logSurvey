		return get_colorbool_found ? 0 : 1;
}

int cmd_config(int argc, const char **argv, const char *prefix)
{
	int nongit = !startup_info->have_repository;
