 	const char *c = color(WT_STATUS_UNMERGED, s);
 	struct wt_status_change_data *d = it->util;
 	struct strbuf onebuf = STRBUF_INIT;
-	const char *one, *how = "bug";
+	const char *one, *how = _("bug");
 
 	one = quote_path(it->string, -1, &onebuf, s->prefix);
 	status_printf(s, color(WT_STATUS_HEADER, s), "\t");
 	switch (d->stagemask) {
-	case 1: how = "both deleted:"; break;
-	case 2: how = "added by us:"; break;
-	case 3: how = "deleted by them:"; break;
-	case 4: how = "added by them:"; break;
-	case 5: how = "deleted by us:"; break;
-	case 6: how = "both added:"; break;
-	case 7: how = "both modified:"; break;
+	case 1: how = _("both deleted:"); break;
+	case 2: how = _("added by us:"); break;
+	case 3: how = _("deleted by them:"); break;
+	case 4: how = _("added by them:"); break;
+	case 5: how = _("deleted by us:"); break;
+	case 6: how = _("both added:"); break;
+	case 7: how = _("both modified:"); break;
 	}
 	status_printf_more(s, c, "%-20s%s\n", how, one);
 	strbuf_release(&onebuf);
