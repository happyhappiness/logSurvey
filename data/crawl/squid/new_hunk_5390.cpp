    case ACL_EXTERNAL:
	aclParseExternal(&data);
	break;
    case ACL_NONE:
    case ACL_ENUM_MAX:
	fatal("Bad ACL type");
