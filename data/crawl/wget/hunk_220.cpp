+This document describes the working of the GNU Wget Test Suite.
+
+Install Instructions:
+================================================================================
+
+This Test Suite exploits the Parallel Test Harness available in GNU Autotools.
+Since it uses features from a relatively recent verion of Autotools, the minimum
+required version as been bumped up to 1.11.
+Run the './configure' command to generate the Makefile and then run 'make check'
+to execute the Test Suite. Use the '-j n' option with 'make check' to execute
+n tests simultaneously.
+
+File List:
+================================================================================
+
+    * HTTPServer.py: This file contains a custom, programmatically configurable
+    HTTP Server for testing Wget. It runs an instance of Python's http.server
+    module.
+
+    * WgetTest.py: This file contains various functions and global variables for
+    each instance of the server that is initiated. It includes functions to
+    start and stop the server, to initialze the test environment and to cleanup
+    after a test.
+
+    * Test-Proto.py: This is a prototype Test Case file. The file defines all
+    the acceptable elements and their uses. Typically, one must copy this file
+    and edit it for writing Test Cases.
+
+    * ColourTerm.py: A custom library for printing coloured output to the
+    terminal. Currently it only supports 4 colours in a *nix environment.
+
+Working:
+================================================================================
+
+The Test Files are valid Python scripts and the default mask for them is 755.
+A singular Test must be invoked in the following manner:
+$ ./python3 <Name of Test File>      OR
+$ ./<Name of Test File>
+The script will then initialize the various elements and pass them to an object
+of the respective Test Class. A directory with the name <Test name>-test will be
+created and the PWD will be changed to this directory. The server is then
+spawned with the required configuration elements. A blocking call to Wget is
+made with the command line arguments specified in the Test Case along with the
+list of URLs that it must download. The server is killed once Wget returns and
+the following checks are used to determine the pass/fail status of the test:
+    * Return Code: The Exit code of Wget is matched against the expected Exit
+    Code as mentioned in the Test Case File.
+    * Downloaded Files: Check whether the expected downloaded files exist on
+    disk.
+    * File Content: Test whether the file contents were correctly downloaded by
+    Wget and not corrupted mid-way.
+    * Excess Files: Check to see whether any unexpected files were downloaded
+    by Wget.
+
+Exit Codes:
+===============================================================================
+
+Following is a list of Exit Status Codes for the tests:
+*   0  Test Successful
+*  66  Errors/Warnings Reported by Thread Sanitizer (If built with -fsanitize)
+*  77  Test Skipped
+*  99  Hard Error
+* 100  Test Failed
+
+Tests are skipped when they are either not supported by the platform, or Wget
+is not compiled with support for that feature. This feature has not yet been
+implemented.
+
+Hard Errors occur when there are problems with the Environment code. Hard
+Error reporting is currently not enabled and all errors are reported as
+failures.
+
+All exceptions should ideally be handled gracefully. If you see any unhandled
+exceptions, please file a bug report at <bug-wget@gnu.org>
+
+Environment Variables:
+================================================================================
+
+TODO: Set variables for ONLY_SERVER and WGET_PATH too.
+* NO_CLEANUP: Do not remove the temporary files created by the test.
+  This will prevent the ${testname}-test directory from being deleted
+
+
+File Structure:
+================================================================================
+
+The test case files are Python scripts. It is believed that Python is a simple
+yet elegant language and should be easy for everyone to comprehend. This test
+suite is written with the objective of making it easy to write new tests. The
+structure has been kept as intuitive as possible and should not require much
+effort to get accustomed to.
+
+All Test Files MUST begin with the following Three Lines:
+#!/usr/bin/python3
+from sys import exit
+from WgetTest import {HTTPTest|FTPTest}, WgetFile
+
+It is recommended that a small description of the Test Case is provided next.
+This would be very helpful to future contributors.
+Next, is the const variable, TEST_NAME that defines the name of the Test.
+
+Each File in the Test must be represented as a WgetFile object. The WgetFile
+Class has the following prototype:
+WgetFile (String name, String contents, String timestamp, dict rules)
+None except name is a mandatory paramter, one may pass only those parameters
+that are required by the File object.
+
+The timestamp string should be a valid Unix Timestamp as defined in RFC xxxx.
+The rules object is a dictionary element, with the key as the Rule Name and
+value as the Rule Data. In most cases, the Rule Data is another dictionary.
+
+Various variables used consistently across all tests are:
+    * WGET_OPTIONS: The command line string passed to Wget upon invokation. This
+    string may contain URLs, like in the case where in-URL authentication is
+    used. Variable names passed like {{var_name}} will be replaced by the
+    contents of the variable self.var_name before being passed to Wget
+    * WGET_URLS: This is a list of filenames which will be appended as the URLs
+    to Wget during invokation. This is a list of lists, where WGET_URLS[0]
+    represents the list of Filenames called from Server[0], WGET_URLS[1] is a
+    list of files downloaded from Server[2], etc.
+    * Files: This variable defines the files that exist in the Server's
+    filesystem. The Files variable is a list of lists of WgetFile objects.
+    This means that File[0] is a list of WgetFile objects that lie on Server[0],
+    File[1] a list of files on Server[1] and so on.
+    * Existing_Files: This is a list of files that already exist in the
+    directory from which Wget is invoked.
+    * ExpectedReturnCode: The Exit Code expected to be returned by Wget after
+    the test.
+    * ExpectedDownloadedFiles: A list of files that are expected in the local
+    directory after Wget has finished executing. This does not include the files
+    already existing before Wget was launched and must be mentioned again.
+    * Request_List: An unordered list of Requests that each server must receive.
+    This too is a list of lists and follows the same convention as others above.
+
+Both, the HTTPTest and FTPTest modules have the same prototype:
+{
+    name,
+    pre_hook,
+    test_options,
+    post_hook,
+    servers
+}
+name expects the string name, and is usually passed the TEST_NAME variable,
+the three hooks, expect python dictionary objects and servers is an integer.
+
+Valid File Rules:
+================================================================================
+
+This section lists the currently supported File Rules and their structure.
+
+    * Authentication: Used when a File must require Authorization for access.
+    The value for this key is the following dictionary:
+    |-->Type        :   Basic|Digest|Both|Both_inline
+    |-->User        :   <Username>
+    --->Pass        :   <Password>
+
+    * ExpectHeader  : The following Headers MUST exist in every Request for the
+    File. The value for this key is a dictionary object where each header is
+    represented as:
+    |-->Header Name :   <Header Data>
+
+    * RejectHeader  : This list of Headers must NEVER occur in a request. It
+    uses the same value format as ExpectHeader.
+
+    * SendHeader    : This list of Headers will be sent in EVERY response to a
+    request for the respective file. It follows the same value format as
+    ExpectHeader.
+
+    * Response      : The HTTP Response Code to send to a request for this File.
+    The value is an Integer that represents a valid HTTP Response Code.
+
+Pre Test Hooks:
+================================================================================
+
+The Pre-Test Hooks are executed just after starting the server and just before
+spawning an instance of the server. These are usually used for setting up the
+Test Environment and Server Rules. The currently supported Pre-Test Hooks are:
+
+    * ServerFiles   : A list of WgetFile objects that must exist on the Server
+    * LocalFiles    : A list of WgetFile objects that exist locally on disk
+    before Wget is executed.
+
+Since pre_test is a dictionary, one may not assume that the hooks will be
+executed in the same order as they are defined.
+
+Test Options:
+================================================================================
+
+The test_options dictionary defines the commands to be used when the Test is
+executed. The currently supported options are:
+
+    * Urls          : A list of the filenames that Wget must attempt to
+    download. The complete URL will be created and passed to Wget automatically.
+    * WgetCommands  : A string consisting of the various commandline switches
+    sent to Wget upon invokation. Any data placed between {{ }} in this string
+    will be replaced with the contents of self.<data> before being passed to
+    Wget. This is particularly useful for getting the hostname and port for a
+    file. While all Download URL's are passed to Urls, a notable exception is
+    when in-url authentication is used. In such a case, the URL is specified in
+    the WgetCommands string.
+
+Post-Test Hooks:
+================================================================================
+
+These hooks are executed as soon as the call to Wget returns. The post-test
+hooks are usually used to run checks on the data, files downloaded, return code,
+etc. The following hooks are currently supported:
+
+    * ExpectedRetcode : This is an integer value of the ReturnCode with which
+    Wget is expected to exit.
+    * ExpectedFiles   : This is a list of WgetFile objects of the files that
+    must exist locally on disk in the Test directory.
+    * FilesCrawled    : This requires a list of the Requests that the server is
+    expected to receive. The order is un-important since it will vary on the
+    parallel-wget branch. This hook is used in tests for Recursive mode to
+    ensure that the website is traversed correctly.
+
+Writing New Tests:
+================================================================================
+
+See Test-Proto.py for an example of how to write Test Case files. The
+recommended method for writing new Test Case files is to copy Test-Proto.py and
+modify it to ones needs.
+
+In case you require any functionality that is not currently defined in List of
+Rules defined above, you should add the required code in WgetTest.py.
+In most cases, one requires a new Rule to be added for the Server to follow.
+In such a case, create a new Class in WgetTest.py with the same name as the Rule
+and define an __init__ () function to handle the data. A method must also be
+defined in HTTPTest / FTPTest modules to handle the said Rule.
+
+Once a new Test File is created, it must be added to the TESTS variable in
+Makefile.am. This way the Test will be executed on running a 'make check'.
+If a Test is expected to fail on the current master branch, then the Test should
+also be added to the XFAIL_TESTS variable. This will allow expected failures to
+pass through. If a test mentioned in the XFAIL_TESTS variable passes, it gets
+red-flagged as a XPASS.
+
+Remember to always name the Test correctly using the TEST_NAME variable. This
+is essential since a directory with the Test Name is created and this can
+cause synchronization problems when the Parallel Test Harness is used.
+One can use the following command on Unix systems to check for TEST_NAME
+clashes:
+$ grep -r -h "TEST_NAME =" | cut -c13- | uniq -c -d
+
+Work Remaining:
+================================================================================
+
+Some amount of work still remains to be done.
+    * Errors in server-side checks need to be handled more explicitly
+    * Support parallel-wget branch
+        * Support to spawn multiple servers is already in place. Need to handle
+        multiple requests to a server simultaneously. Use THreading MixIn.
+    * SSL Tests. Use xyne's HTTPS server implemention
+    * Complete support for FTP Tests
+    * IRI Support. This shouldn't require much effort
+
+Requirements:
+================================================================================
+
+1. Python   >= 3.0
+2. Automake >= 1.11