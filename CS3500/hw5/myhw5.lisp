;Jimmy Lin
(defun myLast (L)
	(if (eq (cdr L) nil)
		(car L)
		(myLast (cdr L)))))

(defun myCount (X L)
	(if (eq L nil)
		0
		(if (eq x (car L))
			(+ 1 (myCount X (cdr L)))
		(+ 0 (myCount X (cdr L))))))
		
(defun myMember (X L)
	(if (eq L nil)
		nil
		(if (eq X (car L))
			t
			(myMember X (cdr L)))))
			
(defun myPurge (L) 
	(if (eq L nil)
		nil
		(if (eq (myCount (car L) L) 1)
			(cons (car L) (myPurge (cdr L)))
			(myPurge (cdr L)))))
			
(defun myCommon (L1 L2)
	(if (eq L1 nil)
		nil
		(if (myMember (car L1) L2) 
			(cons (car L1) (myCommon (cdr L1) L2))
			(myCommon (cdr L1) L2))))

(defun myGen (X Y Z)
	(if (> X Y)
		nil	
		(cons X (myGen (+ X Z) Y Z))))

(defun myMap (F L) 
	(if (eq L nil)
		nil
		(cons (funcall F (car L))
		(myMap F (cdr L)))))

(defun myReduce (foo L)
	(if (eq (cdr (cdr L)) nil)
		(+ (funcall foo (car L) (car (cdr L))))
		(myReduce foo (cons (+ (funcall foo (car L) (car (cdr L)))) (cdr (cdr L))))))
		