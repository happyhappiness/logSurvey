			buffer_copy_bytes(buf, strtouint32(arg));
			return;
		}
	case 's':
		if (!prefixcmp(command, "skip ")) {
			buffer_skip_bytes(buf, strtouint32(arg));
