{
	*var = 0;
}

static void
dump_size_t(size_t var)
{
    printf("%d bytes", (int) var);
}

static void
dump_kb_size_t(size_t var)
{
    printf("%d KB", (int) var);
}

static void
parse_size_t(size_t *var)
{
    parseBytesLine(var, B_BYTES_STR);
}

static void
parse_kb_size_t(size_t *var)
{
    parseBytesLine(var, B_KBYTES_STR);
}

static void
free_size_t(size_t *var)
{
	*var = 0;
}

#define free_kb_size_t free_size_t
#define free_mb_size_t free_size_t
#define free_gb_size_t free_size_t

static void
dump_ushort(u_short var)
