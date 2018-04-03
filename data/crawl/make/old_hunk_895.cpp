@end group
@end example

There are a few of problems with this method, however.  First, any error
detected in a submake is not noted by this rule, so it will continue to
build the rest of the directories even when one fails.  This can be
overcome by adding shell commands to note the error and exit, but then
