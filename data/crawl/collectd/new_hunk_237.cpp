	return (0);
}

static int pf_init (void)
{
	struct pf_status	status;
	int			pfdev = -1;

	if ((pfdev = open(pf_device, O_RDONLY)) == -1) {
		ERROR("unable to open %s", pf_device);
		return (-1);
	}

	if (ioctl(pfdev, DIOCGETSTATUS, &status) == -1) {
		ERROR("DIOCGETSTATUS: %i", pfdev);
		close(pfdev);
		return (-1);
	}

	close(pfdev);
	if (!status.running)
		return (-1);

	return (0);
}

void module_register (void)
{
	plugin_register_init("pf", pf_init);
	plugin_register_read("pf", pf_read);
}
