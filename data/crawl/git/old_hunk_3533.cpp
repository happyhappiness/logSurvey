void wt_shortstatus_print(struct wt_status *s);
void wt_porcelain_print(struct wt_status *s);

void status_printf_ln(struct wt_status *s, const char *color, const char *fmt, ...)
	;
void status_printf(struct wt_status *s, const char *color, const char *fmt, ...)
	;

#endif /* STATUS_H */