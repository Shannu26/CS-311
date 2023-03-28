#lang racket

(define (binomial N K)
(if (= K 0)
1
(if (= K N)
1
(+ (binomial (- N 1) K) (binomial (- N 1) (- K 1))
)
)
)
)

(binomial 4 0)
(binomial 8 8)
(binomial 3 2)
(binomial 7 4)