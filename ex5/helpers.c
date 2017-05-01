static element_t *ResizeArray(element_t *arry, size_t oldLen, size_t newLen) {
	uint32_t i;
	size_t copyLen = oldLen > newLen ? newLen : oldLen;
	element_t *newArry;

	assert(arry != NULL);

	newArry = (element_t*)malloc(newLen*sizeof(element_t));

	if (newArry == NULL)
		return NULL; // malloc error!!!

	// Copy elements to new array
	for (i = 0; i < copyLen; ++i)
		newArry[i] = arry[i];

	// Null initialize rest of new array.
	for (i = copyLen; i < newLen; ++i)
		newArry[i] = NULL;

	return newArry;
}
