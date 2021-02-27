
//填坑
int partion2(int* arr, int begin, int end){

	int mid = getMid(arr, begin, end);
	Swap(arr, begin, mid);

	//第一个基准值,也就是初始为坑的位置
	int key = arr[begin];
	while (begin < end){
		//从后往前找到小的
		while (begin < end&&arr[end] >= key)
			--end;
		//进行填坑
		arr[begin] = arr[end];
		//从前往后找大的
		while (begin < end&&arr[begin] <= key)
			++begin;
		//填坑
		arr[end] = arr[begin];
	}
	arr[begin] = key;
	return begin;
}
//双指针
int partion3(int* arr, int begin, int end){

	int mid = getMid(arr, begin, end);
	Swap(arr, begin, mid);
	//上一个小于基准值的位置
	int prev = begin;
	//下一个小于基准值的位置
	int cur = begin + 1;

	int key = arr[begin];
	while (cur <= end){

		//当cur走到下一个基准值的位置的时候,判断是否连续
		if (arr[cur]<key && ++prev != cur) {

			//不连续,交换数据
			Swap(arr, prev, cur);
		}
		++cur;
	}
	Swap(arr, begin, prev);
	return prev;
}