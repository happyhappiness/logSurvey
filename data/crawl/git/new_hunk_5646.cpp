	count=$1 &&
	git config core.notesRef refs/notes/commits &&
	git log | grep "^    " > output &&
	i=$count &&
	while [ $i -gt 0 ]; do
		echo "    commit #$i" &&
		echo "    note for commit #$i" &&
		i=$(($i-1));
	done > expect &&
	test_cmp expect output
}

cat > time_notes << \EOF