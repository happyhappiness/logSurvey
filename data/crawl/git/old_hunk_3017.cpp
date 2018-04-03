       return REF_TYPE_NORMAL;
}

int delete_ref(const char *refname, const unsigned char *sha1, unsigned int flags)
{
	struct ref_transaction *transaction;
	struct strbuf err = STRBUF_INIT;

	transaction = ref_transaction_begin(&err);
	if (!transaction ||
	    ref_transaction_delete(transaction, refname,
