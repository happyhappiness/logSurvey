    case ACL_IDENT:
#endif
    case ACL_DERIVED:
	fatal ("overridden");
    }
    debug(28, 0) ("aclMatchAcl: '%s' has bad type %d\n",
