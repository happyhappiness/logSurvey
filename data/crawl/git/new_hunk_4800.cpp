void wt_shortstatus_print(struct wt_status *s, int null_termination, int show_branch);
void wt_porcelain_print(struct wt_status *s, int null_termination);

void status_printf_ln(struct wt_status *s, const char *color, const char *fmt, ...)
	;
void status_printf(struct wt_status *s, const char *color, const char *fmt, ...)
	;
void status_printf_more(struct wt_status *s, const char *color, const char *fmt, ...)
	__attribute__((format(printf, 3, 4)));

#endif /* STATUS_H */