 			switch (signature_check.result) {
 			case 'G':
 				break;
+			case 'U':
+				die(_("Commit %s has an untrusted GPG signature, "
+				      "allegedly by %s."), hex, signature_check.signer);
 			case 'B':
 				die(_("Commit %s has a bad GPG signature "
 				      "allegedly by %s."), hex, signature_check.signer);
