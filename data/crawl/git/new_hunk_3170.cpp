/*
 * Verify that the reference locked by lock has the value old_sha1.
 * Fail if the reference doesn't exist and mustexist is set. Return 0
 * on success. On error, write an error message to err, set errno, and
 * return a negative value.
 */
static int verify_lock(struct ref_lock *lock,
		       const unsigned char *old_sha1, int mustexist,
		       struct strbuf *err)
{
	assert(err);

	if (read_ref_full(lock->ref_name,
			  mustexist ? RESOLVE_REF_READING : 0,
			  lock->old_sha1, NULL)) {
		int save_errno = errno;
		strbuf_addf(err, "Can't verify ref %s", lock->ref_name);
		errno = save_errno;
		return -1;
	}
	if (hashcmp(lock->old_sha1, old_sha1)) {
		strbuf_addf(err, "Ref %s is at %s but expected %s",
			    lock->ref_name,
			    sha1_to_hex(lock->old_sha1),
			    sha1_to_hex(old_sha1));
		errno = EBUSY;
		return -1;
	}
