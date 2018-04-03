				    "existing: $existing\n",
				    " globbed: $refname\n";
			}
			my $u = (::cmt_metadata("$refname"))[0];
			if (!defined($u)) {
				warn
"W: $refname: no associated commit metadata from SVN, skipping\n";
				next;
			}
			$u =~ s!^\Q$url\E(/|$)!! or die
			  "$refname: '$url' not found in '$u'\n";
			if ($pathname ne $u) {