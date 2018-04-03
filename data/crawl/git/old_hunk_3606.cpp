				# Other errors. Shouldn't happen => just die()
				die 'Fatal: Error ' .
				    $mediawiki->{error}->{code} .
				    ' from mediwiki: ' . $mediawiki->{error}->{details};
			}
		}
		$newrevid = $result->{edit}->{newrevid};
