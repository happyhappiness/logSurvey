		push_cert_nonce = server_feature_value("push-cert", &len);
		if (!push_cert_nonce)
			die(_("the receiving end does not support --signed push"));
		push_cert_nonce = xmemdupz(push_cert_nonce, len);
	}
