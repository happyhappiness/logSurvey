	if (transaction->state != REF_TRANSACTION_OPEN)
		die("BUG: update called for transaction that is not open");

	if ((flags & REF_ISPRUNING) && !(flags & REF_NODEREF))
		die("BUG: REF_ISPRUNING set without REF_NODEREF");

	if (new_sha1 && !is_null_sha1(new_sha1) &&
	    check_refname_format(refname, REFNAME_ALLOW_ONELEVEL)) {
		strbuf_addf(err, "refusing to update ref with bad name '%s'",
