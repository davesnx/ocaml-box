let none = "";
let space = ' ';
let newLine = "\n";

let textLength = Base.String.length;

let splitLines = (text) => text |> Base.String.split_lines |> List.map(String.trim);

let repeat = (~between="", times, str) => {
  times > 0
    ? Array.init(times, _ => str) |> Array.to_list |> String.concat(between)
    : none
};

let calculateWidestLine = text => {
  text
  |> splitLines
  |> List.fold_left(
      (current, acc) => max(current, textLength(acc)),
      0,
    );
};

let renderSpace = value => {
  value > 0
    ? String.make(value, space)
    : none
};

let row = String.concat(newLine);
let stack = String.concat("");


let columns = () => {
  switch (Sys.getenv_opt("COLUMNS")) {
  | Some(value) => int_of_string(value)
  | None => 80
  }
};
