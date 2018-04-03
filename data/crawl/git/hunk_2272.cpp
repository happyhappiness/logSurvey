 		die(_("unrecognized format: %%(%s)"), atom->name);
 }
 
+static void body_atom_parser(struct used_atom *atom, const char *arg)
+{
+	if (arg)
+		die("%%(body) does not take arguments");
+	atom->u.contents.option = C_BODY_DEP;
+}
+
+static void subject_atom_parser(struct used_atom *atom, const char *arg)
+{
+	if (arg)
+		die("%%(subject) does not take arguments");
+	atom->u.contents.option = C_SUB;
+}
+
+static void contents_atom_parser(struct used_atom *atom, const char *arg)
+{
+	if (!arg)
+		atom->u.contents.option = C_BARE;
+	else if (!strcmp(arg, "body"))
+		atom->u.contents.option = C_BODY;
+	else if (!strcmp(arg, "signature"))
+		atom->u.contents.option = C_SIG;
+	else if (!strcmp(arg, "subject"))
+		atom->u.contents.option = C_SUB;
+	else if (skip_prefix(arg, "lines=", &arg)) {
+		atom->u.contents.option = C_LINES;
+		if (strtoul_ui(arg, 10, &atom->u.contents.nlines))
+			die(_("positive value expected contents:lines=%s"), arg);
+	} else
+		die(_("unrecognized %%(contents) argument: %s"), arg);
+}
+
 static align_type parse_align_position(const char *s)
 {
 	if (!strcmp(s, "right"))
