}

/*
 * Die if refs is not the main ref store. caller is used in any
 * necessary error messages.
 */
static void files_assert_main_repository(struct files_ref_store *refs,
					 const char *caller)
{
	if (refs->store_flags & REF_STORE_MAIN)
		return;

	die("BUG: operation %s only allowed for main ref store", caller);
}

/*
 * Downcast ref_store to files_ref_store. Die if ref_store is not a
 * files_ref_store. required_flags is compared with ref_store's
 * store_flags to ensure the ref_store has all required capabilities.
 * "caller" is used in any necessary error messages.
 */
static struct files_ref_store *files_downcast(struct ref_store *ref_store,
					      unsigned int required_flags,
					      const char *caller)
{
	struct files_ref_store *refs;

