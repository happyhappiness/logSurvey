	message[511] = '\0';
	va_end (ap);

	plugin_log (level, message);
}

void plugin_relief (int level, complain_t *c, const char *format, ...)
