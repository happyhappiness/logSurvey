
'

test_expect_success 'delete' '
	echo 1 > C &&
	test_tick &&
	git commit -m rat C &&

	echo 2 > C &&
	test_tick &&
	git commit -m ox C &&

	echo 3 > C &&
	test_tick &&
	git commit -m tiger C &&

	test 5 = $(git reflog | wc -l) &&

	git reflog delete master@{1} &&
	git reflog show master > output &&
	test 4 = $(wc -l < output) &&
	! grep ox < output &&

	git reflog delete master@{07.04.2005.15:15:00.-0700} &&
	git reflog show master > output &&
	test 3 = $(wc -l < output) &&
	! grep dragon < output
'

test_done