type t = { top : int; right : int; bottom : int; left : int }

val make : ?top:int -> ?right:int -> ?bottom:int -> ?left:int -> unit -> t
val empty : t
val all : int -> t
val top : int -> t
val right : int -> t
val bottom : int -> t
val left : int -> t
val horitzontal : int -> t
val vertical : int -> t
val topLeft : int -> int -> t
val topRight : int -> int -> t
val topBottom : int -> int -> t
val bottomLeft : int -> int -> t
val bottomRight : int -> int -> t
val bottomTop : int -> int -> t
val rightBottom : int -> int -> t
val rightLeft : int -> int -> t
val leftBottom : int -> int -> t
val leftTop : int -> int -> t
val leftRight : int -> int -> t
