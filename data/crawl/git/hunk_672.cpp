 }
 
 /*
- * Die if refs is for a submodule (i.e., not for the main repository).
- * caller is used in any necessary error messages.
+ * Die if refs is not the main ref store. caller is used in any
+ * necessary error messages.
  */
 static void files_assert_main_repository(struct files_ref_store *refs,
 					 const char *caller)
 {
-	/* This function is to be fixed up in the next patch */
+	if (refs->store_flags & REF_STORE_MAIN)
+		return;
+
+	die("BUG: operation %s only allowed for main ref store", caller);
 }
 
 /*
  * Downcast ref_store to files_ref_store. Die if ref_store is not a
- * files_ref_store. If submodule_allowed is not true, then also die if
- * files_ref_store is for a submodule (i.e., not for the main
- * repository). caller is used in any necessary error messages.
+ * files_ref_store. required_flags is compared with ref_store's
+ * store_flags to ensure the ref_store has all required capabilities.
+ * "caller" is used in any necessary error messages.
  */
-static struct files_ref_store *files_downcast(
-		struct ref_store *ref_store, int submodule_allowed,
-		const char *caller)
+static struct files_ref_store *files_downcast(struct ref_store *ref_store,
+					      unsigned int required_flags,
+					      const char *caller)
 {
 	struct files_ref_store *refs;
 
