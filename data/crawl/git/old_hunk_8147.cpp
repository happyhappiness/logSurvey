		}
	}
	close F;
	if (defined $author) {
		$message = "From: $author\n\n$message";
	}


	send_message();

	# set up for the next message