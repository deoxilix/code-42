(defn- show [obj]
  prn obj)

(defn hello [addressee]
  (show (str "hello" addressee)))

(hello "moto")
