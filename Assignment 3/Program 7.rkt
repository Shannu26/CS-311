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

(define (removeAtom atom list)
(if (null? list)
list
(if (equal? atom (car list))
(cdr list)
(cons (car list) (removeAtom atom (cdr list)))
)
)
)

(define (selectionSort numbersList)
(if (null? numbersList)
'()
(cons (findMinimum numbersList)
(selectionSort (removeAtom (findMinimum numbersList) numbersList))
)
)
)

(selectionSort '())
(selectionSort '(5))
(selectionSort '(6 10 23 12 2 9 18 1 0 15))
(selectionSort '(3 4 7 3 7 7 4 3 2 3 7))
