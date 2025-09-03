/* https://github.com/nothings/stb/pull/1454#issuecomment-2581308033 */

#include "../../stb_image.h"

#include <stdlib.h>

int test_1454_gif(void)
{
	const stbi_uc data[] = { 'G', 'I', 'F', '8', '9', 'a', // Magic number
		1, 0, 1, 0, // Width and height
		0, 0, 0}; // flags, bgindex, ratio
	int size = (int)sizeof(data);

	int *delays = NULL;
	int x, y, z, comp;
	stbi_uc* image = stbi_load_gif_from_memory(
		(const stbi_uc*)data, size,
		&delays,
		&x, &y, &z,
		&comp, 3);

	if (image)
	{
		stbi_image_free(image);
	}

	if (delays)
	{
		stbi_image_free(delays);
	}
	
	return EXIT_SUCCESS;
}
