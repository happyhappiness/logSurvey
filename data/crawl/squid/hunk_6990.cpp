 	    break;
 	case ACL_NONE:
 	default:
-	    fatal_dump("aclDestroyAcls: Found ACL_NONE?");
+	    assert(0);
 	    break;
 	}
 	safe_free(a->cfgline);
