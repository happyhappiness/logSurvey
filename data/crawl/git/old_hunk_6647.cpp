			*sizep = size;
		break;
	default:
		die("pack %s contains unknown object type %d",
		    p->pack_name, type);
	}
	unuse_pack(&w_curs);
	return type;
