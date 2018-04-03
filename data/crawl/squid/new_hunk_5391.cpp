#endif
    case ACL_DERIVED:
	fatal ("unused");
    case ACL_REP_MIME_TYPE:
	return aclDumpRegexList((relist *)data);
    case ACL_SRC_ASN:
