	message[511] = '\0';
	va_end (ap);

	syslog (level, message);
}
