package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	text, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(text))
	text, _ = reader.ReadString('\n')
	dp = make([]int)
	for i := 0; i < n; i++ {
		if text[i] == 'B' {

		}
	}
}
