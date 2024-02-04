#include <stdint.h>
#include "../../stb_vorbis.c"

int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size)
{
	short *pcm = NULL;
	int num_channels, sample_rate, num_samples;

	/* Make sure the size_t -> int cast is valid. */
	if (size > INT_MAX)
	{
		return -1; /* Don't add this to the corpus. */
	}

	/* Attempt to decode the file from memory. */
	num_samples = stb_vorbis_decode_memory(data, (int)size, &num_channels, &sample_rate, &pcm);
	/* Clean up: */
	if (num_samples >= 0)
	{
		free(pcm);
	}

	return 0;
}