{
	va_list params;

	va_start(params, err);
	die_routine(err, params);
	va_end(params);
