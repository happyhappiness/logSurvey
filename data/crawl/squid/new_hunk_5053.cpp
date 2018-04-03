            }
        } else {
            credentials(Failed);
            digest_request->setDenyMessage("Incorrect password");
            return;
        }

