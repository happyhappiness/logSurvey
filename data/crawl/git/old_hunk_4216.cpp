                die("Detecting current git branch failed!")
        elif len(args) == 1:
            self.master = args[0]
        else:
            return False

