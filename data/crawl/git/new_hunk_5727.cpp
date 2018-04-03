	GIT_COLOR_RED,    /* WT_STATUS_UNMERGED */
};

static const char *color(int slot, struct wt_status *s)
{
	return s->use_color > 0 ? s->color_palette[slot] : "";
