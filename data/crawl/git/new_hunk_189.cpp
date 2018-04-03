
	flags &= REF_TRANSACTION_UPDATE_ALLOWED_FLAGS;

	flags |= (new_oid ? REF_HAVE_NEW : 0) | (old_oid ? REF_HAVE_OLD : 0);

	ref_transaction_add_update(transaction, refname, flags,
				   new_oid, old_oid, msg);
	return 0;
}

int ref_transaction_create(struct ref_transaction *transaction,
			   const char *refname,
			   const struct object_id *new_oid,
			   unsigned int flags, const char *msg,
			   struct strbuf *err)
{
	if (!new_oid || is_null_oid(new_oid))
		die("BUG: create called without valid new_oid");
	return ref_transaction_update(transaction, refname, new_oid,
				      &null_oid, flags, msg, err);
}

int ref_transaction_delete(struct ref_transaction *transaction,
			   const char *refname,
			   const struct object_id *old_oid,
			   unsigned int flags, const char *msg,
			   struct strbuf *err)
{
	if (old_oid && is_null_oid(old_oid))
		die("BUG: delete called with old_oid set to zeros");
	return ref_transaction_update(transaction, refname,
				      &null_oid, old_oid,
				      flags, msg, err);
}

int ref_transaction_verify(struct ref_transaction *transaction,
			   const char *refname,
			   const struct object_id *old_oid,
			   unsigned int flags,
			   struct strbuf *err)
{
	if (!old_oid)
		die("BUG: verify called with old_oid set to NULL");
	return ref_transaction_update(transaction, refname,
				      NULL, old_oid,
				      flags, NULL, err);
}

