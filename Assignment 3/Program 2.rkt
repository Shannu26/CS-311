#lang racket

(define (modulus N M)
(if (< N M)
N
(if (equal? N 0)
0
(modulus (- N M) M)
)
)
)

(modulus 9 5)
(modulus 7 9)
(modulus 100 37)
(modulus 20 5)
(modulus -11 3)