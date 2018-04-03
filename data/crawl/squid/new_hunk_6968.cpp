    case ACL_PROXY_AUTH:
	aclParseProxyAuth(&A->data);
	break;
    case ACL_SRC_ASN:
    case ACL_DST_ASN:
	aclParseIntlist(&A->data);
	break;
    case ACL_NONE:
    default:
	fatal("Bad ACL type");
	break;
    }
    if (!new_acl)
