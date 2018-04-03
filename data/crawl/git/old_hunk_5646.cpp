	count=$1 &&
	git config core.notesRef refs/notes/commits &&
	git log | grep "^    " > output &&
	i=1 &&
	while [ $i -le $count ]; do
		echo "    $(($count-$i))" &&
		echo "    note $i" &&
		i=$(($i+1));
	done > expect &&
	git diff expect output
}

cat > time_notes << \EOF