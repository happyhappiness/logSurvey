        """Write the string msg on a log file or on stderr.

        Sends the text to stderr by default, override to change the behavior."""
        write_str(sys.stderr, msg)

    def log_warning(self, msg):
        """Write the string msg on a log file or on stderr.

        Sends the text to stderr by default, override to change the behavior."""
        write_str(sys.stderr, msg)

    def log_error(self, msg):
        """Write the string msg on a log file or on stderr.

        Sends the text to stderr by default, override to change the behavior."""
        write_str(sys.stderr, msg)


class ConfigEnvironmentMixin(Environment):
