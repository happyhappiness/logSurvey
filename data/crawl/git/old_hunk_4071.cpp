	    cd parent &&
	    echo "Even more text" >>file.txt &&
	    git commit -a -m "Third commit" &&
	    git send-pack ../child HEAD:refs/heads/test_auto_gc >output 2>&1 &&
	    grep "Auto packing the repository for optimum performance." output
	) &&
	test ! -e child/.git/objects/tmp_test_object
'