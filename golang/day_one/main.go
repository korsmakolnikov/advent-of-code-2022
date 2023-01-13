package main

import (
	"bufio"
	"fmt"
	"korsmakolnikov/day_one/src/optimization"
	"log"
	"os"
	"sort"
	"strconv"
)

func main() {
	var carry []int
	var partial []string

	scanner := bufio.NewScanner(os.Stdin)

	for scanner.Scan() {
		i := scanner.Text()
		if "" != i {
			partial = append(partial, i)
		} else {
			appendToCarry(&partial, &carry)
			partial = partial[:0]
		}
	}

	if err := scanner.Err(); err != nil {
		fmt.Fprintln(os.Stderr, "reading standard input:", err)
	}

	appendToCarry(&partial, &carry)

	optimization.ReverseQuickSort(carry, 0, len(carry)-1)
	fmt.Println(carry[:3])
}

func appendToCarry(p *[]string, carry *[]int) {
	n, err := arraySum(*p)
	if err != nil {
		log.Fatalln(err)
		panic(err)
	}
	*carry = append(*carry, n)

}

// This function is deprecated since I wrote a reversed quicksort
func ReverseSort(ns []int) []int {
	sort.Sort(sort.Reverse(sort.IntSlice(ns)))
	return ns
}

func arraySum(a []string) (res int, err error) {
	for _, i := range a {
		if i != "" {
			n, err := strconv.Atoi(i)

			if err != nil {
				return 0, err
			}

			res = res + n
		}
	}

	return res, nil
}
