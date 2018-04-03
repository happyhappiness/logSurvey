

        self.gitStream.close()
        self.gitOutput.close()
        self.gitError.close()
        importProcess.wait()

        return True
