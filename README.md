# unicode.c

description :

a tool to give decimal, hexadecimal and binary representation of a unicode (utf-8 encoded) character or string

example1 :

```
$ ./unicode
Enter unicode string : Liberté


string is encoded in 8 bytes that represent 7 unicode characters.

unicode         :       Liberté
decimal         :       76 105 98 101 114 116 195 169 
hexadecimal     :       4c 69 62 65 72 74 c3 a9 
binary          :       01001100 01101001 01100010 01100101 01110010 01110100 11000011 10101001
```

example2 :
```
$ ./unicode 
Enter unicode string : you owe me 3€


string is encoded in 15 bytes that represent 13 unicode characters.

unicode         :       you owe me 3€
decimal         :       121 111 117 32 111 119 101 32 109 101 32 51 226 130 172 
hexadecimal     :       79 6f 75 20 6f 77 65 20 6d 65 20 33 e2 82 ac 
binary          :       01111001 01101111 01110101 00100000 01101111 01110111 01100101 00100000 01101101 01100101 00100000 00110011 11100010 10000010 10101100
```

limitations : 

- 999 input characters

*** -  this repository is mirrored from gitea ***
