(define looking
  (lambda (a lat)
	(keep-looking a (pick 1 lat) lat)))

(define looking
  (lambda (caviar (6 2 4 caviar 5 7 3))
	(keep-looking caviar
				  (pick 1 (6 2 4 caviar 5 7 3))
				  (6 2 4 caviar 5 7 3))))

(keep-looking caviar
			  (pick 1 (6 2 4 caviar 5 7 3))
			  (6 2 4 caviar 5 7 3))

(pick 1 (6 2 4 caviar 5 7 3))
6

(keep-looking caviar
              6
			  (6 2 4 caviar 5 7 3))

; pick picks the num-th element in the lat
(define pick
  (lambda (num lat)
	(cond
	 ((= num 1) (car lat)
	  else (pick (sub1 num) (cdr lat))))))

(define keep-looking
  (lambda (a sorn lat)
	(cond
	 ((number? sorn)
	  (keep-looking a (pick sorn lat) lat))
	 (else (eq? sorn a)))))

; a lambda function where which calls itself (recurses) without ever simplifying anything. This leads to an endless loop
(define eternity
  (lambda (x)
	(eternity x)))
; Eternity is a partial function because not every input is mapped to an output

(define shift
  (lambda (pair)
	(build (first (first pair))
		   (build (second (first pair))
				  (second pair)))))

(define align
  (lambda (pora)
	(cond
	 ((atom? pora) pora)
	 ((a-pair? (first pora))
	  (align (shift pora)))
	 (else (build (first pora)
				  (align (second pora)))))))

(define shuffle
  (lambda (pora)
    (cond
     ((atom? pora) pora)
     ((a-pair? (first pora))
      (shuffle (revpair pora)))
     (else (build (first pora)
                  (shuffle (second pora)))))))

; length_0
(lambda (l) ;<- length_0
  (cond
   ((null? l) 0)
   (else (add1 (eternity (cdr l))))))

; length_1
(lambda (l) ;<- length_1
  (cond
   ((null? l) 0)
   (else (add1
		  (lambda (l) ;<- length_0
			(cond
			 ((null? l) 0)
			 (else (add1 (eternity (cdr l))))))))))

; length_2
(lambda (l) ;<- length_2
  (cond
   ((null? l) 0)
   (else (add1
		  (lambda (l) ;<- length_1
			(cond
			 ((null? l) 0)
			 (else (add1
					(lambda (l) ;<- length_0
					  (cond
					   ((null? l) 0)
					   (else (add1 (eternity (cdr l))))))))))))))

((lambda (length) ;<- length_0
   (lambda (l)
	 (cond
	  ((null? l) 0)
	  (else (add1 (length (cdr l)))))))
 eternity)

((lambda (f) ;<- length_1
   (lambda (l)
	 (cond
	  ((null? l) 0)
	  (else (add1 (f (cdr l)))))))
 ((lambda (g) ;<- length_0
	(lambda (l)
	  (cond
	   ((null? l) 0)
	   (else (add1 (g (cdr l)))))))
  eternity))

((lambda (length) ;<- length_2
   (lambda (l)
	 (cond
	  ((null? l) 0)
	  (else (add1 (length (cdr l)))))))
 ((lambda (length) ;<- length_1
	(lambda (l)
	  (cond
	   ((null? l) 0)
	   (else (add1 (length (cdr l)))))))
  ((lambda (length) ;<- length_0
	 (lambda (l)
	   (cond
		((null? l) 0)
		(else (add1 (length (cdr l)))))))
   eternity)))

((lambda (mk-length)
   (mk-length eternity)) ;<- length_0
 (lambda (length)
   (lambda (l)
	 (cond
	  ((null? l) 0)
	  (else (add1 (length (cdr l))))))))

((lambda (mk-length)
   (mk-length ;<- length_1
	(mk-length eternity))) ;<- length_0
 (lambda (length)
   (lambda (l)
	 (cond
	  ((null? l) 0)
	  (else (add1 (length (cdr l))))))))

((lambda (mk-length)
   (mk-length ;<- length_2
	(mk-length ;<- length_1
	 (mk-length eternity)))) ;<- length_0
 (lambda (length)
   (lambda (l)
	 (cond
	  ((null? l) 0)
	  (else (add1 (length (cdr l))))))))

((lambda (mk-length)
   (mk-length mk-length))
 (lambda (mk-length)
   (lambda (l)
	 (cond
	  ((null? l) 0)
	  (else (add1 (mk-length (cdr l))))))))

(((lambda (mk-length)
   (mk-length mk-length))
 (lambda (mk-length)
   (lambda (l)
	 (cond
	  ((null? l) 0)
	  (else (add1
			 ((mk-length eternity)
			  (cdr l)))))))) l)

length_0 beta reductions begin here
===================================

(((lambda (mk-length) ;<- lambda_1
	(mk-length mk-length))
  (lambda (mk-length) ;<- lambda_2
	(lambda (l) ;<- lambda_3
	  (cond
	   ((null? l) 0)
	   (else (add1
			  ((mk-length eternity) (cdr l)))))))) (apples))

; Resolve lambda_1
(((lambda (mk-length) ;<- lambda_2a
	(lambda (l) ;<- lambda_3a
	  (cond
	   ((null? l) 0)
	   (else (add1
			  ((mk-length eternity)
			   (cdr l)))))))
  (lambda (mk-length) ;<- lambda_2b
	(lambda (l) ;<- lambda_3b
	  (cond
	   ((null? l) 0)
	   (else (add1
			  ((mk-length eternity) (cdr l)))))))) (apples))

; Resolve lambda_2a
((lambda (l) ;<- lambda_3a
   (cond
	((null? l) 0)
	(else (add1
		   (((lambda (mk-length) ;<- lambda_2b
			   (lambda (l) ;<- lambda_3b
				 (cond
				  ((null? l) 0)
				  (else (add1
						 ((mk-length eternity)
						  (cdr l))))))) eternity) (cdr l)))))) (apples))

;; Note that lambda_3a's 'l' is NOT the same as lambda_3b's 'l'! Consequently, the 'l's that occur in the function are either bound to lambda_3a's 'l' or lambda_3b's 'l'. To make things clearer, let's do an alpha reduction (ten dollar word for renaming) on lambda_3b's 'l'

; Rename lambda_3b's 'l' to something else. I'm using 'm' in this case
((lambda (l) ;<- lambda_3a
   (cond
	((null? l) 0)
	(else (add1
		   (((lambda (mk-length) ;<- lambda_2b
			   (lambda (m) ;<- lambda_3b
				 (cond
				  ((null? m) 0)
				  (else (add1
						 ((mk-length eternity)
						  (cdr m))))))) eternity) (cdr l)))))) (apples))

; Resolve lambda_3a next
(cond
 ((null? (apples)) 0) ;<- false
 (else (add1 ;<- proceed to the 'else'
		(((lambda (mk-length) ;<- lambda_2b
			(lambda (m) ;<-lambda_3b
			  (cond
			   ((null? m) 0)
			   (else (add1
					  ((mk-length eternity)
					   (cdr m))))))) eternity) (cdr (apples))))))

; resolve (cdr (apples)) into ()
(add1
 (((lambda (mk-length) ;<- lambda_2b
	 (lambda (m) ;<- lambda_3b
	   (cond
		((null? m) 0)
		(else (add1
			   ((mk-length eternity)
				(cdr m))))))) eternity) ()))

; resolve lambda_2b
(add1
 (lambda (m) ;<- lambda_3b
   (cond
	((null? m) 0)
	(else (add1
		   ((eternity eternity) (cdr m)))))) ())

;resolve lambda_3b
(add1
 (cond
  ((null? ()) 0) ;<- true, return 0
  (else (add1 ;<- no need to go down here
		 ((eternity eternity) (cdr ()))))))

(add1
 0)

1
============
length_1 fin

Y Combinator beta reductions begin here
=======================================

================
Y Combinator fin

(define lookup-in-entry
  (lambda (name entry entry-f)
	(lookup-in-entry-help name
						  (first entry)
						  (second entry)
						  entry-f)))

(define lookup-in-entry-help
  (lambda (name names values entry-f)
	(cond
	 ((null? names) (entry-f name))
	 ((eq? (car names) name)
	  (car values))
	 (else (lookup-in-entry (cdr names)
							(cdr values)
							entry-f)))))

(define lookup-in-table
  (lambda (name table table-f)
	((null? table) (table-f name))
	(else (lookup-in-entry name
						   (car table)
						   (lambda (name)
							 (lookup-in-table name
											  (cdr table)
											  table-f))))))

(define expression-to-action
  (lambda (e)
	(cond
	 ((atom? e) (atom-to-action e))
	 (else (list-to-action e)))))

(define atom-to-action
  (lambda (e)
	(cond
	 ((number? e) *const)
	 ((eq? e #t) *const)
	 ((eq? e #f) *const)
	 ((eq? e (quote cons)) *const)
	 ((eq? e (quote car)) *const)
	 ((eq? e (quote cdr)) *const)
	 ((eq? e (quote null?)) *const)
	 ((eq? e (quote eq?)) *const)
	 ((eq? e (quote atom?)) *const)
	 ((eq? e (quote zero?)) *const)
	 ((eq? e (quote add1)) *const)
	 ((eq? e (quote sub1)) *const)
	 ((eq? e (quote number?)) *const)
	 (else *identifier))))

(define list-to-action
  (lambda (e)
	(cond
	 ((atom? (car e))
	  (cond
	   ((eq? (car e) (quote quote)) *quote)
	   ((eq? (car e) (quote lambda)) *lambda)
	   ((eq? (car e) (quote cond)) *cond)
	   (else *application)))
	 (else *application))))

(define value
  (lambda (e)
	(meaning e (quote ()))))

(define meaning
  (lambda (e table)
	((expression-to-action e) e table)))

(define *const
  (lambda (e table)
	(cond
	 ((number? e) e)
	 ((eq? e #t) #t)
	 ((eq? e #f) #f)
	 (else (build (quote primitive) e)))))

(define *quote
  (lambda (e table)
	(text-of e)))

(define text-of second)

(define *identifier
  (lambda (e table)
	(lookup-in-table e table initial-table)))

(define initial-table
  (lambda (name)
	(car (quote ()))))
; You can't take the car of an empty list. This function's purpose is to never be called. It induces an error when called.

(define *lambda
  (lambda (e table)
	(build (quote non-primitive)
		   (cons table (cdr e)))))

(meaning e table)
; where e is (lambda (x) (cons x y))
; & table is (((y z) ((8) 9)))

((expression-to-action () e table)

(*lambda e table)

((lambda (e table)
   (build (quote non-primitive)
		  (cons table (cdr e)))) e table)

; sub e with (lambda (x) (cons x y))
; sub table with (((y z) ((8) 9)))
(build (quote non-primitive)
	   (cons (((y z) ((8) 9)))
			 ((x) (cons x y))))

(build (quote non-primitive)
	   (cons (((y z) ((8) 9)))
			 ((x) (cons x y))))

(non-primitive  ((((y z) ((8) 9))) (x) (cons x y)))

(define table-of first)
(define formals-of second)
(define body-of third)

(define evcon
  (lambda (lines table)
	(cond
	 ((else? (question-of (car lines)))
	  (meaning (answer-of (car lines)) table))
	 ((meaning (question-of (car lines)) table)
	  (meaning (answer-of (car lines))
			   table))
	 (else (evcon (cdr lines) table)))))

(define else?
  (lambda (x)
	(cond
	 ((atom? x) (eq? x (quote else)))
	 (else #f))))

(define question-of first)
(define answer-of second)

(define *cond
  (lambda (e table)
	(evcon (cond-lines-of e) table)))

(define cond-lines-of cdr)

*cond in execution
(*cond e table)
; where e is (cond (coffee klatsch) (else party))
; & table is (((coffee) (#t)) ((klatsch party)(5 (6))))

(meaning coffee table)

(define evlis
  (lambda (args table)
	(cond
	 ((null? args) (quote ()))
	 (else
	  (cons (meaning (car args) table)
			(evlist (cdr args) table))))))

(define *application
  (lambda (e table)
	(apply
	 (meaning (function-of e) table)
	 (meaning (arguments-of e) table))))

(define function-of car)
(define arguments-of cdr)

There are two kinds of functions, primitive and non-primitive.
Representations of primitive/non-primitive functions look like this respectively:
Primitive - (primitive primitive-name)
Non-primitive (non-primitive (table formals body))
; The list (table formals body) is called a closure record

(define primitive?
  (lambda (l)
	(eq? (first l) (quote primitive))))

(define non-primitive?
  (lambda (l)
	(eq? (first l) (quote non-primitive))))

(define apply
  (lambda (fun vals)
	(cond
	 ((primitive? fun) (apply-primitive (second fun)
										vals))
	 ((non-primitive? fun) (apply-closure (second fun)
										  vals)))))

(define apply-primitive
  (lambda (name value)
	(cond
	 ((eq? name (quote cons))
	  (cons (first vals) (second vals)))
	 ((eq? name (quote car))
	  (car (first vals)))
	 ((eq? name (quote cdr))
	  (cdr (first vals)))
	 ((eq? name (quote null?))
	  (null? (first vals)))
	 ((eq? name (quote eq?))
	  (eq? (first vals)))
