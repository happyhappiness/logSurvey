	fatal("Bad ACL type");
	break;
    }
    if (!new_acl)
	return;
    if (A->data == NULL) {
