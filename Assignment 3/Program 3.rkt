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

(define (binaryToDecimal binary count)
(if (equal? binary 0)
0
(+ (* (modulus binary 10) (expt 2 count))
(binaryToDecimal (quotient binary 10) (+ count 1))
)
)
)

(binaryToDecimal 0 0)
(binaryToDecimal 1011 0)
(binaryToDecimal 111111 0)
(binaryToDecimal 10001 0)