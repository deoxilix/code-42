(defn- show [x]
  (prn x))

(defn hello [addressee]
  (show (str "hello " addressee "!")))

(defn greet [greetfunc addressee]
  (greetfunc addressee))

(greet hello "moto")
