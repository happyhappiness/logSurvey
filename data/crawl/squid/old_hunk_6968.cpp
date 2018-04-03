    case ACL_PROXY_AUTH:
	aclParseProxyAuth(&A->data);
	break;
    case ACL_NONE:
    default:
	debug_trap("Bad ACL type");
	break;
    }
    if (!new_acl)
