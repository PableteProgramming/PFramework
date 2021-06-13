package main

import "C"

import (
	//"golgang.org/x/crypto/md4"
	"crypto/md5"
	"crypto/sha1"
	"crypto/sha256"
	"crypto/sha512"
	"encoding/hex"
	/*"golang.org/x/crypto/ripemd160"
	"golang.org/x/crypto/sha3"
	"golang.org/x/crypto/blake2s"
	"golang.org/x/crypto/blake2b"*/
)

//export Hashmd5
func Hashmd5(s *C.char) *C.char{
	ss := C.GoString(s)
	h := md5.New()
	h.Write([]byte(ss))
	r := hex.EncodeToString(h.Sum(nil))
	str := string(r[:])
	rr := C.CString(str)
	return rr
}

//export Hashsha1
func Hashsha1(s *C.char) *C.char{
	ss := C.GoString(s)
	h := sha1.New()
	h.Write([]byte(ss))
	r := hex.EncodeToString(h.Sum(nil))
	str := string(r[:])
	rr := C.CString(str)
	return rr
}

//export Hashsha256
func Hashsha256(s *C.char) *C.char{
	ss := C.GoString(s)
	h := sha256.New()
	h.Write([]byte(ss))
	r := hex.EncodeToString(h.Sum(nil))
	str := string(r[:])
	rr := C.CString(str)
	return rr
}

//export Hashsha512
func Hashsha512(s *C.char) *C.char{
	ss := C.GoString(s)
	h := sha512.New()
	h.Write([]byte(ss))
	r := hex.EncodeToString(h.Sum(nil))
	str := string(r[:])
	rr := C.CString(str)
	return rr
}

func main(){}
