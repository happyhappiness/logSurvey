	@cc = @initial_cc;
	@xh = ();
	my $input_format = undef;
	my $header_done = 0;
	$message = "";
	while(<F>) {
		if (!$header_done) {
			if (/^From /) {
				$input_format = 'mbox';
				next;
			}
			chomp;
			if (!defined $input_format && /^[-A-Za-z]+:\s/) {
				$input_format = 'mbox';
			}

			if (defined $input_format && $input_format eq 'mbox') {
				if (/^Subject:\s+(.*)$/) {
					$subject = $1;

				} elsif (/^(Cc|From):\s+(.*)$/) {
					if (unquote_rfc2047($2) eq $sender) {
						next if ($suppress_cc{'self'});
					}
					elsif ($1 eq 'From') {
						($author, $author_encoding)
						  = unquote_rfc2047($2);
						next if ($suppress_cc{'author'});
					} else {
						next if ($suppress_cc{'cc'});
					}
					printf("(mbox) Adding cc: %s from line '%s'\n",
						$2, $_) unless $quiet;
					push @cc, $2;
				}
				elsif (/^Content-type:/i) {
					$has_content_type = 1;
					if (/charset="?([^ "]+)/) {
						$body_encoding = $1;
					}
					push @xh, $_;
				}
				elsif (/^Message-Id: (.*)/i) {
					$message_id = $1;
				}
				elsif (!/^Date:\s/ && /^[-A-Za-z]+:\s+\S/) {
					push @xh, $_;
				}

			} else {
				# In the traditional
				# "send lots of email" format,
				# line 1 = cc
				# line 2 = subject
				# So let's support that, too.
				$input_format = 'lots';
				if (@cc == 0 && !$suppress_cc{'cc'}) {
					printf("(non-mbox) Adding cc: %s from line '%s'\n",
						$_, $_) unless $quiet;

					push @cc, $_;

				} elsif (!defined $subject) {
					$subject = $_;
				}
			}

			# A whitespace line will terminate the headers
			if (m/^\s*$/) {
				$header_done = 1;
			}
		} else {
			$message .=  $_;
			if (/^(Signed-off-by|Cc): (.*)$/i) {
				next if ($suppress_cc{'sob'});
				chomp;
				my $c = $2;
				chomp $c;
				next if ($c eq $sender and $suppress_cc{'self'});
				push @cc, $c;
				printf("(sob) Adding cc: %s from line '%s'\n",
					$c, $_) unless $quiet;
			}
		}
	}
	close F;

	if (defined $cc_cmd && !$suppress_cc{'cccmd'}) {
