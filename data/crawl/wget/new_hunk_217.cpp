2014-07-23  Darshit Shah  <darnir@gmail.com>

	* test/base_test.py (BaseTest.gen_cmd_line): Add support for running all
	tests through valgrind if the relevant environment variable is set
	* conf/expected_ret_code (ExpectedRetCode.__call__): Valgrind returns error
	code 45 when it detects a memory leak.
	* Readme: Update with details about valgrind tests

2014-07-22  Darshit Shah  <darnir@gmail.com>

	* (README): Remove old TODO and document SERVER_WAIT variable
