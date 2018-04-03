	return ref_store;
}

/*
 * Die if refs is not the main ref store. caller is used in any
 * necessary error messages.
 */
static void packed_assert_main_repository(struct packed_ref_store *refs,
					  const char *caller)
{
	if (refs->store_flags & REF_STORE_MAIN)
		return;

	die("BUG: operation %s only allowed for main ref store", caller);
}

/*
 * Downcast `ref_store` to `packed_ref_store`. Die if `ref_store` is
 * not a `packed_ref_store`. Also die if `packed_ref_store` doesn't
