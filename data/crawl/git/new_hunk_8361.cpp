	test "z$id" = "z$embedded"
'

# If an expanded ident ever gets into the repository, we want to make sure that
# it is collapsed before being expanded again on checkout
test_expect_success expanded_in_repo '
	{
		echo "File with expanded keywords"
		echo "\$Id\$"
		echo "\$Id:\$"
		echo "\$Id: 0000000000000000000000000000000000000000 \$"
		echo "\$Id: NoSpaceAtEnd\$"
		echo "\$Id:NoSpaceAtFront \$"
		echo "\$Id:NoSpaceAtEitherEnd\$"
		echo "\$Id: NoTerminatingSymbol"
	} > expanded-keywords &&

	{
		echo "File with expanded keywords"
		echo "\$Id: 4f21723e7b15065df7de95bd46c8ba6fb1818f4c \$"
		echo "\$Id: 4f21723e7b15065df7de95bd46c8ba6fb1818f4c \$"
		echo "\$Id: 4f21723e7b15065df7de95bd46c8ba6fb1818f4c \$"
		echo "\$Id: 4f21723e7b15065df7de95bd46c8ba6fb1818f4c \$"
		echo "\$Id: 4f21723e7b15065df7de95bd46c8ba6fb1818f4c \$"
		echo "\$Id: 4f21723e7b15065df7de95bd46c8ba6fb1818f4c \$"
		echo "\$Id: NoTerminatingSymbol"
	} > expected-output &&

	git add expanded-keywords &&
	git commit -m "File with keywords expanded" &&

	echo "expanded-keywords ident" >> .gitattributes &&

	rm -f expanded-keywords &&
	git checkout -- expanded-keywords &&
	cat expanded-keywords &&
	cmp expanded-keywords expected-output
'

test_done