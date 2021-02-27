
//���
int partion2(int* arr, int begin, int end){

	int mid = getMid(arr, begin, end);
	Swap(arr, begin, mid);

	//��һ����׼ֵ,Ҳ���ǳ�ʼΪ�ӵ�λ��
	int key = arr[begin];
	while (begin < end){
		//�Ӻ���ǰ�ҵ�С��
		while (begin < end&&arr[end] >= key)
			--end;
		//�������
		arr[begin] = arr[end];
		//��ǰ�����Ҵ��
		while (begin < end&&arr[begin] <= key)
			++begin;
		//���
		arr[end] = arr[begin];
	}
	arr[begin] = key;
	return begin;
}
//˫ָ��
int partion3(int* arr, int begin, int end){

	int mid = getMid(arr, begin, end);
	Swap(arr, begin, mid);
	//��һ��С�ڻ�׼ֵ��λ��
	int prev = begin;
	//��һ��С�ڻ�׼ֵ��λ��
	int cur = begin + 1;

	int key = arr[begin];
	while (cur <= end){

		//��cur�ߵ���һ����׼ֵ��λ�õ�ʱ��,�ж��Ƿ�����
		if (arr[cur]<key && ++prev != cur) {

			//������,��������
			Swap(arr, prev, cur);
		}
		++cur;
	}
	Swap(arr, begin, prev);
	return prev;
}