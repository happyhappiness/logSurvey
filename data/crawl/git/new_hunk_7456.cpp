			mmbuffer_t result_buf;
			int merge_status;

			merge_status = merge_3way(&result_buf, o, a, b,
						  branch1, branch2);

			if ((merge_status < 0) || !result_buf.ptr)
				die("Failed to execute internal merge");