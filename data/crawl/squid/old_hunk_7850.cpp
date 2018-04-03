	sprintf(key_temp_buffer, "/head/%s", url);
	return key_temp_buffer;
	break;
    default:
	fatal_dump("storeGeneratePublicKey: Unsupported request method");
	break;
