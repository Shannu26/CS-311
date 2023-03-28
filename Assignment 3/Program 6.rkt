#lang racket

(define (removeAtom atom list)
(if (null? list)
list
(if (equal? atom (car list))
(removeAtom atom (cdr list))
(cons (car list) (removeAtom atom (cdr list)))
)
)
)

(removeAtom 'a '())
(removeAtom 'a '(a))
(removeAtom 'a '(a b c d a b a a))
(removeAtom 'a '(x y z))
(removeAtom 'a '(a (x y z) (r s t a)))
(removeAtom 'a '(((a (l a) b) a) m a))