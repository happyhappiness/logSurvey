union block *start_private_header (const char *name, size_t size);
void write_eot (void);
void check_links (void);

#define GID_TO_CHARS(val, where) gid_to_chars (val, where, sizeof (where))
#define MAJOR_TO_CHARS(val, where) major_to_chars (val, where, sizeof (where))
#define MINOR_TO_CHARS(val, where) minor_to_chars (val, where, sizeof (where))
