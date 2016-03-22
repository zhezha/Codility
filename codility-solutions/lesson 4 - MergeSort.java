
public class MergeSort {
	
	public static void sort(int[] array) {
		int length = array.length;
		int[] tmp = new int[length];
		mergeSort(array, tmp, 0, length - 1);
	}
	
	private static void mergeSort(int[] array, int[] tmp, int low, int high) {
		if (low < high) {
			int middle = (high + low) / 2;
			mergeSort(array, tmp, low, middle);
			mergeSort(array, tmp, middle + 1, high);
			merge(array, tmp, low, middle, high);
		}
	}

	private static void merge(int[] array, int[] tmp, int low, int middle, int high) {
		for (int i = low; i <= high; i++) {
			tmp[i] = array[i];
		}
		
		int i = low;
		int j = middle + 1;
		int k = low;
		while (i <= middle && j <= high) {
			if (tmp[i] <= tmp[j]) {
				array[k] = tmp[i];
				i++;
			}
			else {
				array[k] = tmp[j];
				j++;
			}
			k++;
		}
		
		while(i <= middle) {
			array[k] = tmp[i];
			i++;
			k++;
		}
	}
}
