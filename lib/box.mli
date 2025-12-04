type position = Left | Center | Right

val render :
  ?align:position ->
  ?float:position ->
  ?padding:Padding.t ->
  ?margin:Margin.t ->
  ?border:Border.t ->
  string ->
  string

module Border = Border
module Padding = Padding
module Margin = Margin
