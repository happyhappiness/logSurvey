__attribute__((format (printf, 3, 4)))
void status_printf(struct wt_status *s, const char *color, const char *fmt, ...);

/* The following function expects that the caller took care of reading the index. */
int require_clean_work_tree(const char *action, const char *hint, int gently);

#endif /* STATUS_H */