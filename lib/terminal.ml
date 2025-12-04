let none = ""
let space = ' '
let newLine = "\n"
let textLength = Stdlib.String.length
let splitLines text = text |> Base.String.split_lines |> List.map String.trim

let repeat ?(between = "") times str =
  if times > 0 then
    Array.init times (fun _ -> str) |> Array.to_list |> String.concat between
  else none

let calculateWidestLine text =
  text |> splitLines
  |> List.fold_left (fun current acc -> max current (textLength acc)) 0

let renderSpace value = if value > 0 then String.make value space else none
let row = String.concat newLine
let stack = String.concat ""

let columns () =
  match Sys.getenv_opt "COLUMNS" with
  | Some value -> int_of_string value
  | None -> 80
