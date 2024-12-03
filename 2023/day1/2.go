package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func catch(e error) {
	if e != nil {
		panic(e)
	}
}

func add(n int, ns []int) {
	min := n
	for i := 0; i < len(ns); i++ {
		if min > ns[i] {
			tmp := ns[i]
			ns[i] = min
			min = tmp
		}
	}
}

func main() {
	file, _ := os.Open("./input")
	scanner := bufio.NewScanner(file)
	defer file.Close()

	top := []int{0, 0, 0}
	sum := 0

	for {
		line := scanner.Scan()
		txt := scanner.Text()

		if !line || len(txt) == 0 {
			if sum > top[2] { add(sum, top) }
			sum = 0

			if !line { break }
			continue
		}

		num, err := strconv.Atoi(txt)
		catch(err)
		sum += num
	}

	fmt.Println("The top three fattest elves: ", top)
	fmt.Println("The top three fattest elves combined: ", top[0] + top[1] + top[2])
}