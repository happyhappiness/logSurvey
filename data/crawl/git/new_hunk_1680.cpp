	can be safely ignored such as invalid committer email addresses.
	Note: corrupt objects cannot be skipped with this setting.

receive.keepAlive::
	After receiving the pack from the client, `receive-pack` may
	produce no output (if `--quiet` was specified) while processing
	the pack, causing some networks to drop the TCP connection.
	With this option set, if `receive-pack` does not transmit
	any data in this phase for `receive.keepAlive` seconds, it will
	send a short keepalive packet.  The default is 5 seconds; set
	to 0 to disable keepalives entirely.

receive.unpackLimit::
	If the number of objects received in a push is below this
	limit then the objects will be unpacked into loose object
