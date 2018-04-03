            self.importP4Labels(self.gitStream, missingP4Labels)

        self.gitStream.close()
        if self.importProcess.wait() != 0:
            die("fast-import failed: %s" % self.gitError.read())
        self.gitOutput.close()
        self.gitError.close()
