 should not try to access the file on disk, but only act as filters on the
 content provided to them on standard input.
 
+Long Running Filter Process
+^^^^^^^^^^^^^^^^^^^^^^^^^^^
+
+If the filter command (a string value) is defined via
+`filter.<driver>.process` then Git can process all blobs with a
+single filter invocation for the entire life of a single Git
+command. This is achieved by using a packet format (pkt-line,
+see technical/protocol-common.txt) based protocol over standard
+input and standard output as follows. All packets, except for the
+"*CONTENT" packets and the "0000" flush packet, are considered
+text and therefore are terminated by a LF.
+
+Git starts the filter when it encounters the first file
+that needs to be cleaned or smudged. After the filter started
+Git sends a welcome message ("git-filter-client"), a list of supported
+protocol version numbers, and a flush packet. Git expects to read a welcome
+response message ("git-filter-server"), exactly one protocol version number
+from the previously sent list, and a flush packet. All further
+communication will be based on the selected version. The remaining
+protocol description below documents "version=2". Please note that
+"version=42" in the example below does not exist and is only there
+to illustrate how the protocol would look like with more than one
+version.
+
+After the version negotiation Git sends a list of all capabilities that
+it supports and a flush packet. Git expects to read a list of desired
+capabilities, which must be a subset of the supported capabilities list,
+and a flush packet as response:
+------------------------
+packet:          git> git-filter-client
+packet:          git> version=2
+packet:          git> version=42
+packet:          git> 0000
+packet:          git< git-filter-server
+packet:          git< version=2
+packet:          git< 0000
+packet:          git> capability=clean
+packet:          git> capability=smudge
+packet:          git> capability=not-yet-invented
+packet:          git> 0000
+packet:          git< capability=clean
+packet:          git< capability=smudge
+packet:          git< 0000
+------------------------
+Supported filter capabilities in version 2 are "clean" and
+"smudge".
+
+Afterwards Git sends a list of "key=value" pairs terminated with
+a flush packet. The list will contain at least the filter command
+(based on the supported capabilities) and the pathname of the file
+to filter relative to the repository root. Right after the flush packet
+Git sends the content split in zero or more pkt-line packets and a
+flush packet to terminate content. Please note, that the filter
+must not send any response before it received the content and the
+final flush packet.
+------------------------
+packet:          git> command=smudge
+packet:          git> pathname=path/testfile.dat
+packet:          git> 0000
+packet:          git> CONTENT
+packet:          git> 0000
+------------------------
+
+The filter is expected to respond with a list of "key=value" pairs
+terminated with a flush packet. If the filter does not experience
+problems then the list must contain a "success" status. Right after
+these packets the filter is expected to send the content in zero
+or more pkt-line packets and a flush packet at the end. Finally, a
+second list of "key=value" pairs terminated with a flush packet
+is expected. The filter can change the status in the second list
+or keep the status as is with an empty list. Please note that the
+empty list must be terminated with a flush packet regardless.
+
+------------------------
+packet:          git< status=success
+packet:          git< 0000
+packet:          git< SMUDGED_CONTENT
+packet:          git< 0000
+packet:          git< 0000  # empty list, keep "status=success" unchanged!
+------------------------
+
+If the result content is empty then the filter is expected to respond
+with a "success" status and a flush packet to signal the empty content.
+------------------------
+packet:          git< status=success
+packet:          git< 0000
+packet:          git< 0000  # empty content!
+packet:          git< 0000  # empty list, keep "status=success" unchanged!
+------------------------
+
+In case the filter cannot or does not want to process the content,
+it is expected to respond with an "error" status.
+------------------------
+packet:          git< status=error
+packet:          git< 0000
+------------------------
+
+If the filter experiences an error during processing, then it can
+send the status "error" after the content was (partially or
+completely) sent.
+------------------------
+packet:          git< status=success
+packet:          git< 0000
+packet:          git< HALF_WRITTEN_ERRONEOUS_CONTENT
+packet:          git< 0000
+packet:          git< status=error
+packet:          git< 0000
+------------------------
+
+In case the filter cannot or does not want to process the content
+as well as any future content for the lifetime of the Git process,
+then it is expected to respond with an "abort" status at any point
+in the protocol.
+------------------------
+packet:          git< status=abort
+packet:          git< 0000
+------------------------
+
+Git neither stops nor restarts the filter process in case the
+"error"/"abort" status is set. However, Git sets its exit code
+according to the `filter.<driver>.required` flag, mimicking the
+behavior of the `filter.<driver>.clean` / `filter.<driver>.smudge`
+mechanism.
+
+If the filter dies during the communication or does not adhere to
+the protocol then Git will stop the filter process and restart it
+with the next file that needs to be processed. Depending on the
+`filter.<driver>.required` flag Git will interpret that as error.
+
+After the filter has processed a blob it is expected to wait for
+the next "key=value" list containing a command. Git will close
+the command pipe on exit. The filter is expected to detect EOF
+and exit gracefully on its own. Git will wait until the filter
+process has stopped.
+
+If you develop your own long running filter
+process then the `GIT_TRACE_PACKET` environment variables can be
+very helpful for debugging (see linkgit:git[1]).
+
+Please note that you cannot use an existing `filter.<driver>.clean`
+or `filter.<driver>.smudge` command with `filter.<driver>.process`
+because the former two use a different inter process communication
+protocol than the latter one.
+
+
 Interaction between checkin/checkout attributes
 ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 
