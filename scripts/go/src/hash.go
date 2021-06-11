package main

import "C"

import (
	"crypto/md5"
)

//export Hashmd5
func Hashmd5(s string) string{
	r := md5.Sum([]byte(s))
	return string(r[:])
}

func main(){}
