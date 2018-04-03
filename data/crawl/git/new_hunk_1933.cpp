			   unsigned int flags, const char *msg,
			   struct strbuf *err)
{
	assert(err);

	if (new_sha1 && !is_null_sha1(new_sha1) &&
	    check_refname_format(refname, REFNAME_ALLOW_ONELEVEL)) {
		strbuf_addf(err, "refusing to update ref with bad name '%s'",
			    refname);
		return -1;
	}

	flags |= (new_sha1 ? REF_HAVE_NEW : 0) | (old_sha1 ? REF_HAVE_OLD : 0);

	ref_transaction_add_update(transaction, refname, flags,
				   new_sha1, old_sha1, msg);
	return 0;
}

