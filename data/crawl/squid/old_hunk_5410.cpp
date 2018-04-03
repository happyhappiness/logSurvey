    case ACL_IDENT:
#endif
    case ACL_DERIVED:
    case ACL_PROXY_AUTH:
	fatal ("overridden");
    }
    debug(28, 0) ("aclMatchAcl: '%s' has bad type %d\n",
