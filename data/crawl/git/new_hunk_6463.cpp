	@cc = @initial_cc;
	@xh = ();
	my $input_format = undef;
	my @header = ();
	$message = "";
	# First unfold multiline header fields
	while(<F>) {
		last if /^\s*$/;
		if (/^\s+\S/ and @header) {
			chomp($header[$#header]);
			s/^\s+/ /;
			$header[$#header] .= $_;
	    } else {
			push(@header, $_);
		}
	}
	# Now parse the header
	foreach(@header) {
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
			}
			elsif (/^From:\s+(.*)$/) {
				($author, $author_encoding) = unquote_rfc2047($1);
				next if $suppress_cc{'author'};
				next if $suppress_cc{'self'} and $author eq $sender;
				printf("(mbox) Adding cc: %s from line '%s'\n",
					$1, $_) unless $quiet;
				push @cc, $1;
			}
			elsif (/^Cc:\s+(.*)$/) {
				foreach my $addr (parse_address_line($1)) {
					if (unquote_rfc2047($addr) eq $sender) {
						next if ($suppress_cc{'self'});
					} else {
						next if ($suppress_cc{'cc'});
					}
					printf("(mbox) Adding cc: %s from line '%s'\n",
						$addr, $_) unless $quiet;
					push @cc, $addr;
				}
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
	}
	# Now parse the message body
	while(<F>) {
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
	close F;

	if (defined $cc_cmd && !$suppress_cc{'cccmd'}) {
