}

verify_concatenated_notes () {
    git log | grep "^    " > output &&
    i=$number_of_commits &&
    while [ $i -gt 0 ]; do
        echo "    commit #$i" &&
        echo "    first note for commit #$i" &&
        echo "    second note for commit #$i" &&
        i=$(($i-1));
    done > expect &&
    test_cmp expect output
}

test_expect_success 'test notes in no fanout concatenated with 2/38-fanout' 'test_concatenated_notes "s|^..|&/|" ""'