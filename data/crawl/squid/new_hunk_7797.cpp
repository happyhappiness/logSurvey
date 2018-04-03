    int index;

    *tmp_error_buf = '\0';
    if (type < ERR_MIN || type > ERR_MAX)
	fatal_dump("squid_error_url: type out of range.");
    index = (int) (type - ERR_MIN);

