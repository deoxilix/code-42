;; set namespace
(ns learnclojure)

;; '/quote: to not eval seqs of data, only to eval later
'(1 2 3) ;; => (1 2 3)
(eval '(+ 2 2)) ;; => 4

;; list<-linked-list-based (has only entry point)
(class (list 1 2 3)) ;; => clojure.lang.PersistentList
;(second (1 2 3)) ;; => *error*
(seq? '(1 2 3)) ;; => true
(coll? '(1 2 3)) ;; => true

;; vector<-array-backed
(class [1 2 3]) ;; => clojure.lang.PersistentVector
;(second [1 2 3]) ;; => 2;
(seq? [1 2 3]) ;; => false
(coll? [1 2 3]) ;; => true

;; seqs can define infinite series // are lazy.
(take 6 (range)) ;; => (0 1 2 3 4 5)


; < ======================================================== > ;

;; private functions start
(defn- evnnn? [x]
  (if (even? x)
    [true x]
    [false x]))
(defn- evn-bias-inc [x]
  (let [x1 (first x)
        x2 (second x)]
    (cond-> x2
      x1 (inc)
      (not x1) (dec))))
;; private function end

;; '/quote trials
'(-> 5 evnnn? fnnn) ;; (-> 5 oddd? fnnn)

(eval '(-> 6
           evnnn?
           evn-bias-inc))
