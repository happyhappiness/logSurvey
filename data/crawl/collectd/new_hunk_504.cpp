	message[511] = '\0';
	va_end (ap);

	plugin_log (level, message);
}
