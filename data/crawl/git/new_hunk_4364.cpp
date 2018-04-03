
extern int diff_queue_is_empty(void);
extern void diff_flush(struct diff_options*);
extern void diff_warn_rename_limit(const char *varname, int needed, int degraded_cc);

/* diff-raw status letters */
#define DIFF_STATUS_ADDED		'A'
