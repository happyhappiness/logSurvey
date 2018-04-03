            if (DeleteService(schService) == 0)
                fprintf(stderr, "DeleteService failed.\n");
            else
                printf("Service %s deleted successfully.\n",
                       WIN32_Service_name);

            CloseServiceHandle(schService);
        }
