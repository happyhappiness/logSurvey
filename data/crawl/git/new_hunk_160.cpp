}

/*
 * Verify that the reference locked by lock has the value old_oid
 * (unless it is NULL).  Fail if the reference doesn't exist and
 * mustexist is set. Return 0 on success. On error, write an error
 * message to err, set errno, and return a negative value.
 */
static int verify_lock(struct ref_store *ref_store, struct ref_lock *lock,
		       const struct object_id *old_oid, int mustexist,
		       struct strbuf *err)
{
	assert(err);

	if (refs_read_ref_full(ref_store, lock->ref_name,
			       mustexist ? RESOLVE_REF_READING : 0,
			       &lock->old_oid, NULL)) {
		if (old_oid) {
			int save_errno = errno;
			strbuf_addf(err, "can't verify ref '%s'", lock->ref_name);
			errno = save_errno;
