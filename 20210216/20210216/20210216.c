//====1.������Ԫ���Ƴ�,����ʱ�临�Ӷ���С
int removeElement(int* nums, int numsSize, int val){

	if (nums == NULL || numsSize = 0)
		return;

	int idx = 0;
	int i = 0;
	for (i = 0; i <= numsSize; ++i){
		if (nums[i] != val){
			nums[idx++] = nums[i];
		}
	}
	return idx;
}

//=======2.ɾ���ظ���,Ҫ���Ӷ�
int removeDuplicates(int* nums, int numsSize){
	if (numsSize <= 1)
		return numsSize;

	int i = 0, j = 1, idx = 0;
	while (j < numsSize){
		nums[idx++] = nums[i];
		if (nums[i] == nums[j]){
			while (j < numsSize&&nums[i] == nums[j]){
				++j;

				i = j;
				++j;
			}
		}
		else{
			++i;
			++j;
		}
	}
	if (i < numsSize)
		nums[idx++] = nums[i];
	return idx;
}