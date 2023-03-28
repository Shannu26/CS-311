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

(define (addBinaryNumbers binaryNumbersList)
(if (null? binaryNumbersList)
0
(+ (binaryToDecimal (car binaryNumbersList) 0)
(addBinaryNumbers (cdr binaryNumbersList))
)
)
)

(addBinaryNumbers '(1101 111 10 101))
(addBinaryNumbers '(0))
(addBinaryNumbers '(11011))