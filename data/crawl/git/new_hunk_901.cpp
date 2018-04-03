			$smtp->datasend("$line") or die $smtp->message;
		}
		$smtp->dataend() or die $smtp->message;
		$smtp->code =~ /250|200/ or die sprintf(__("Failed to send %s\n"), $subject).$smtp->message;
	}
	if ($quiet) {
		printf($dry_run ? __("Dry-Sent %s\n") : __("Sent %s\n"), $subject);
	} else {
		print($dry_run ? __("Dry-OK. Log says:\n") : __("OK. Log says:\n"));
		if (!file_name_is_absolute($smtp_server)) {
