}

#define free_onoff free_int
#define dump_eol dump_string
#define free_eol free_string
#define dump_debug dump_string
#define free_debug free_string

static void
dump_refreshpattern(StoreEntry * entry, const char *name, refresh_t * head)
