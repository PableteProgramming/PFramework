package main

import "C"

import (
	"crypto/md5"
)

//export Hashmd5
func Hashmd5(s *C.char) *C.char{
	ss := C.GoString(s)
	r := md5.Sum([]byte(ss))
	str := string(r[:])
	rr := C.CString(str)
	return rr
}

func main(){}
