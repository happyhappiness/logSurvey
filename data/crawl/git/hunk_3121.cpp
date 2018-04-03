 	return sigc->result != 'G' && sigc->result != 'U';
 }
 
+void print_signature_buffer(const struct signature_check *sigc, unsigned flags)
+{
+	if (flags & GPG_VERIFY_VERBOSE && sigc->payload)
+		fputs(sigc->payload, stdout);
+
+	if (sigc->gpg_output)
+		fputs(sigc->gpg_output, stderr);
+}
+
 /*
  * Look at GPG signed content (e.g. a signed tag object), whose
  * payload is followed by a detached signature on it.  Return the
