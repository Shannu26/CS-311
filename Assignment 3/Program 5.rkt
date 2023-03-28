#lang racket

(define (findMinimum numbersList) (getMinimum (cdr numbersList) (car numbersList)))

(define (getMinimum numbersList minTillNow)
(if (null? numbersList)
minTillNow
(if (< (car numbersList) minTillNow)
(getMinimum (cdr numbersList) (car numbersList))
(getMinimum (cdr numbersList) minTillNow)
)
)
)

(findMinimum '(4 5 1 2 5))
(findMinimum '(3))
(findMinimum '(5 5 5))
(findMinimum '())