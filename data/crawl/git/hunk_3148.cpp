 		argv_array_push(arr, "-f");
 }
 
+/**
+ * If pull.ff is unset, returns NULL. If pull.ff is "true", returns "--ff". If
+ * pull.ff is "false", returns "--no-ff". If pull.ff is "only", returns
+ * "--ff-only". Otherwise, if pull.ff is set to an invalid value, die with an
+ * error.
+ */
+static const char *config_get_ff(void)
+{
+	const char *value;
+
+	if (git_config_get_value("pull.ff", &value))
+		return NULL;
+
+	switch (git_config_maybe_bool("pull.ff", value)) {
+	case 0:
+		return "--no-ff";
+	case 1:
+		return "--ff";
+	}
+
+	if (!strcmp(value, "only"))
+		return "--ff-only";
+
+	die(_("Invalid value for pull.ff: %s"), value);
+}
+
 /**
  * Appends merge candidates from FETCH_HEAD that are not marked not-for-merge
  * into merge_heads.
