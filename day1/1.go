package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func check(e error) {
	if e != nil {
		panic(e)
	}
}

func main() {
	file, _ := os.Open("./input")
	scanner := bufio.NewScanner(file)
	defer file.Close()

	max := 0
	sum := 0

	for {
		line := scanner.Scan()
		txt := scanner.Text()

		if !line || len(txt) == 0 {
			if sum > max { max = sum }
			sum = 0

			if !line { break }
			continue
		}

		num, err := strconv.Atoi(txt)
		check(err)
		sum += num
	}

	fmt.Println("The fattest elf has this many calories: ", max)
}