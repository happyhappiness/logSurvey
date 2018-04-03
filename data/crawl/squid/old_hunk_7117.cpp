	/* NOTREACHED */
	break;
    default:
	debug_trap("storeGeneratePublicKey: Unsupported request method");
	break;
    }
    return NULL;
