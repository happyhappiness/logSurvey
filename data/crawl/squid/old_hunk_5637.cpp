	aclParseArpList(&A->data);
	break;
#endif
    case ACL_NONE:
    case ACL_ENUM_MAX:
	fatal("Bad ACL type");
