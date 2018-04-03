
#define quote_path quote_path_relative

static void wt_status_print_unmerged_data(struct wt_status *s,
					  struct string_list_item *it)
{
	const char *c = color(WT_STATUS_UNMERGED, s);
	struct wt_status_change_data *d = it->util;
	struct strbuf onebuf = STRBUF_INIT;
	const char *one, *how = _("bug");

	one = quote_path(it->string, s->prefix, &onebuf);
	status_printf(s, color(WT_STATUS_HEADER, s), "\t");
	switch (d->stagemask) {
	case 1: how = _("both deleted:"); break;
	case 2: how = _("added by us:"); break;
	case 3: how = _("deleted by them:"); break;
	case 4: how = _("added by them:"); break;
	case 5: how = _("deleted by us:"); break;
	case 6: how = _("both added:"); break;
	case 7: how = _("both modified:"); break;
	}
	status_printf_more(s, c, "%-20s%s\n", how, one);
	strbuf_release(&onebuf);
}

static const char *wt_status_diff_status_string(int status)
