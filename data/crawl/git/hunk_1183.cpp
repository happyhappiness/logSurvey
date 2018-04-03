 				const struct string_list *extras,
 				const struct string_list *skip);
 
-int rename_ref_available(const char *oldname, const char *newname);
+/*
+ * Check whether an attempt to rename old_refname to new_refname would
+ * cause a D/F conflict with any existing reference (other than
+ * possibly old_refname). If there would be a conflict, emit an error
+ * message and return false; otherwise, return true.
+ *
+ * Note that this function is not safe against all races with other
+ * processes (though rename_ref() catches some races that might get by
+ * this check).
+ */
+int rename_ref_available(const char *old_refname, const char *new_refname);
 
 /* We allow "recursive" symbolic refs. Only within reason, though */
 #define SYMREF_MAXDEPTH 5