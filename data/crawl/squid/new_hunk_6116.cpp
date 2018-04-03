	swap_log_op_str[op],
	storeKeyText(e->key),
	e->swap_file_number);
    storeUfsDirSwapLog(e, op);
}

char *
storeDirSwapLogFile(int dirn, const char *ext)
{
    return storeUfsDirSwapLogFile(dirn, ext);
}

void
