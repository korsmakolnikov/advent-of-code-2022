package optimization

// TODO pick random partition element to optimize worst case
// TODO benchmark vs original function in package main
func ReverseQuickSort(a []int, low int, high int) {
	if low < high {
		pi := partition(a, low, high)
		ReverseQuickSort(a, low, pi-1)
		ReverseQuickSort(a, pi+1, high)
	}
}

func partition(a []int, low, high int) int {
	pivot := a[high]
	i := low - 1

	for j := low; j <= high; j++ {
		if a[j] > pivot {
			i++
			swap(&a[i], &a[j])
		}
	}

	swap(&a[i+1], &a[high])
	return i + 1
}

func swap(i1, i2 *int) {
	*i1, *i2 = *i2, *i1
}
