				const struct string_list *extras,
				const struct string_list *skip);

int rename_ref_available(const char *oldname, const char *newname);

/* We allow "recursive" symbolic refs. Only within reason, though */
#define SYMREF_MAXDEPTH 5