	return -1;
}

static int objwarning(struct object *obj, const char *err, ...)
{
	va_list params;
	va_start(params, err);
	objreport(obj, "warning", err, params);
	va_end(params);
	return -1;
}

static int mark_object(struct object *obj, int type, void *data)
