	if ($quiet) {
		printf (($dry_run ? "Dry-" : "")."Sent %s\n", $subject);
	} else {
		print($dry_run ? __("Dry-OK. Log says:\n") : __("OK. Log says:\n"));
		if (!file_name_is_absolute($smtp_server)) {
			print "Server: $smtp_server\n";
			print "MAIL FROM:<$raw_from>\n";
