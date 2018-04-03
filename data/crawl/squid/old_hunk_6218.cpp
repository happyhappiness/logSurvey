extern const char *gb_to_str(const gb_t *);
extern void gb_flush(gb_t *);	/* internal, do not use this */
extern int stringHasWhitespace(const char *);

#if USE_HTCP
extern void htcpInit(void);
