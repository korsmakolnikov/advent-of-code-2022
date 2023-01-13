package optimization_test

import (
	. "korsmakolnikov/day_one/src/optimization"
	"testing"
)

func TestReversedQuickSort(t *testing.T) {
	if true {
		low := 0
		high := 8
		test := make([]int, low, high)
		test = append(test, 4, 3, 8, 1, 2, 9, 6, 7, 5)

		ReverseQuickSort(test, 0, 8)

		if test[0] != 9 {
			t.Errorf("ReverseQuickSort fails: at index 0 there is %d, result = %v", test[0], test)
		}
	}
}
