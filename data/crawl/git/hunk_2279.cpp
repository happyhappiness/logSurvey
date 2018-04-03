 static struct used_atom {
 	const char *name;
 	cmp_type type;
+	union {
+		char color[COLOR_MAXLEN];
+	} u;
 } *used_atom;
 static int used_atom_cnt, need_tagged, need_symref;
 static int need_color_reset_at_eol;
 
+static void color_atom_parser(struct used_atom *atom, const char *color_value)
+{
+	if (!color_value)
+		die(_("expected format: %%(color:<color>)"));
+	if (color_parse(color_value, atom->u.color) < 0)
+		die(_("unrecognized color: %%(color:%s)"), color_value);
+}
+
 static struct {
 	const char *name;
 	cmp_type cmp_type;
