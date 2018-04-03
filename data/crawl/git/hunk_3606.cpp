 				# Other errors. Shouldn't happen => just die()
 				die 'Fatal: Error ' .
 				    $mediawiki->{error}->{code} .
-				    ' from mediwiki: ' . $mediawiki->{error}->{details};
+				    ' from mediwiki: ' . $mediawiki->{error}->{details} . "\n";
 			}
 		}
 		$newrevid = $result->{edit}->{newrevid};
