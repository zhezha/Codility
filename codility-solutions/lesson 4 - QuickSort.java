
public class QuickSort {
	
	// sorting entry
	public static void sort(int[] array) {
		if (array == null || array.length == 0) {
			return;
		}
		
		quickSort(array, 0, array.length - 1);	
	}
	
	// sorting recursion
	private static void quickSort(int[] array, int left, int right) {
		// Return p = (i, j) from the partition method, where j < i.
		int[] p = partition(array, left, right);
		
		// from left to j
		if (left < p[1]) {
			quickSort(array, left, p[1]);
		}
		
		// from i to right
		if (p[0] < right) {
			quickSort(array, p[0], right);
		}
	}
	
	/**
	 * Choose an element as pivot, i from left to right, j from right to left,
	 * when array[i] >= pivot && array[j] <= pivot, swap array[i] and array[j].
	 * The termination condition is i > j.
	 * @param array
	 * @param left
	 * @param right
	 * @return p[2] p[0] = i, p[1] = j
	 */
	private static int[] partition(int[] array, int left, int right) {
		int i = left;
		int j = right;
		// The pivot can be choosen as the header, tailer, or middle of the array.
		int pivot = array[left];
//		int pivot = array[right];
//		int pivot = array[left + (right - left) / 2];
		
		while (i <= j) {
			while (array[i] < pivot) {
				i++;
			}
			
			while (array[j] > pivot) {
				j--;
			}
			
			if (i <= j) {
				swap(array, i, j);
				i++;
				j--;
			}
		}
		
		int[] p = new int[2];
		p[0] = i;
		p[1] = j;
		return  p;
	}
	
	private static void swap(int[] array, int i, int j) {
		int tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
}
