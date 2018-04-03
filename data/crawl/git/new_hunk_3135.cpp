#define DIRENT_SORT_HINT(de) ((de)->d_ino)
#endif

static void objreport(struct object *obj, const char *msg_type,
			const char *err)
{
	fprintf(stderr, "%s in %s %s: %s\n",
		msg_type, typename(obj->type), sha1_to_hex(obj->sha1), err);
}

static int objerror(struct object *obj, const char *err)
{
	errors_found |= ERROR_OBJECT;
	objreport(obj, "error", err);
	return -1;
}

static int fsck_error_func(struct object *obj, int type, const char *message)
{
	objreport(obj, (type == FSCK_WARN) ? "warning" : "error", message);
	return (type == FSCK_WARN) ? 0 : 1;
}

