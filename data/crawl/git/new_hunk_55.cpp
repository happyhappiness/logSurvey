		break;
	default:
		die("unknown object type for %s: %s",
		    oid_to_hex(oid), type_name(type));
	}

	if (!obj)
