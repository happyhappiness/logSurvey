				    "existing: $existing\n",
				    " globbed: $refname\n";
			}
			my $u = (::cmt_metadata("$refname"))[0] or die
			    "$refname: no associated commit metadata\n";
			$u =~ s!^\Q$url\E(/|$)!! or die
			  "$refname: '$url' not found in '$u'\n";
			if ($pathname ne $u) {