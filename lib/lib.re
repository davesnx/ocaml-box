let none = "";
let empty = ' ';
let newLine = "\n";

let textLength = Base.String.length;

let splitLines = (text) => text |> Base.String.split_lines |> List.map(String.trim);

let repeat = (~between="", times, str) => {
  times > 0 ? Array.init(times, _ => str) |> Array.to_list |> String.concat(between) : none;
};

let calculateWidestLine = text => {
  text
  |> splitLines
  |> List.fold_left(
      (current, acc) => max(current, textLength(acc)),
      0,
    );
};

let renderEmpty = value => {
  value > 0
    ? String.make(value, empty)
    : none
};

let row = String.concat(newLine);
let stack = String.concat("");
