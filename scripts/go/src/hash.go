package main

import "C"

import (
	"crypto/md4"
	"crypto/md5"
	"crypto/sha1"
	"crypto/sha256"
	"crypto/sha512"
	"crypto/ripemd160"
	"crypto/sha3"
	"crypto/blake2s"
	"crypto/blake2b"
)

//export Hashmd5
func Hashmd5(s string) string{
	return md5.Sum([]byte(s))
}

func main(){}
