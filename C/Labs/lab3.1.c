#include <stdio.h>
#include <malloc.h>

/*need to find number in buffer then change numbers positions*/
int count_pivot(int* buffer, int left, int right){
	int pivot = buffer[(left + right) / 2];

	int copy_left = left;
	int copy_right = right;

	while (copy_left <= copy_right)
	{
		while (buffer[copy_left] < pivot)
			copy_left++;

		while (buffer[copy_right] > pivot)
			copy_right--;

		if (copy_right > copy_left)
			break;

		int t = 0;
		t = buffer[copy_left];
		buffer[copy_left] = buffer[copy_right];
		buffer[copy_right] = t;

		copy_left++;
		copy_right--;
	}

	return copy_right;
}

/* need to sort part of sequence  */
void quick_sort(int* buffer, int left, int right){
	if (left < right){
		int pivot = count_pivot(buffer, left, right);
		quick_sort(buffer, left, pivot);
		quick_sort(buffer, pivot + 1, right);
	}
}

int main(){
	int buffer_length = 0;

	if (1 != scanf_s("%d", &buffer_length)){
		printf("bad input!");
		return 0;
	}

	int* buffer = (int*)malloc(buffer_length * sizeof(int));

	for (int i = 0; i < buffer_length; i++)
		scanf_s("%d", &buffer[i]);

	quick_sort(buffer, 0, buffer_length - 1);

	for (int i = 0; i < buffer_length; i++)
		printf("%d ", buffer[i]);

	free(buffer);
	return 0;
}
