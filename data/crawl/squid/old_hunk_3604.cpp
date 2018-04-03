	return;
    }

    httpHeaderPutStrf(hdr_out, header, "Basic %s",
		      base64_encode(orig_request->peer_login));
    return;
