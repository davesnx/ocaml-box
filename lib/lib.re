open Border;
open Base;

let split_lines = String.split_lines;

let repeat = (~sep: string, times, str) => {
  let listOfStrings = Array.init(times, ~f=_ => str) |> Array.to_list;
  String.concat(~sep, listOfStrings);
};

let widestLine = str => {
  str
  |> split_lines
  |> List.fold_left(
       ~f=(current, acc) => max(current, String.length(acc)),
       ~init=0,
     );
};

let newLine = "\n";

let makeEmpty = value => String.make(value, ' ');

let getTerminalColumns = () => {
  Sys.getenv("COLUMNS")
  |> Option.bind(~f=Caml.int_of_string_opt)
  |> Option.value(~default=80);
};

let box = (~padding=0, ~margin=0, ~kind=Round, text) => {
  let _columns = getTerminalColumns();
  let bordersWidth = 2;
  let symbols = Border.symbols(kind);
  let paddingLeftValue = padding + bordersWidth;
  let marginLeftValue = margin * 2;
  let marginLeft = makeEmpty(marginLeftValue);
  let paddingLeft = makeEmpty(paddingLeftValue);
  let contentWidth = widestLine(text) + paddingLeftValue * 2;
  let marginTop = repeat(~sep="", margin, newLine);
  let marginBottom = repeat(~sep="", margin, newLine);
  let horitzontalTop = repeat(~sep="", contentWidth, symbols.top);
  let horitzontalBottom = repeat(~sep="", contentWidth, symbols.bottom);

  let renderLine = line => {
    let paddingRightValue =
      contentWidth - String.length(line) - padding - bordersWidth;
    let paddingRight = makeEmpty(paddingRightValue);
    let content = String.concat(~sep="", [paddingLeft, line, paddingRight]);
    String.concat(
      ~sep="",
      [marginLeft, symbols.left, content, symbols.right],
    );
  };

  let lines = text |> split_lines;
  let content =
    lines |> List.map(~f=renderLine) |> String.concat(~sep=newLine);
  let paddingTop = repeat(~sep=newLine, padding, renderLine(""));
  let paddingBottom = repeat(~sep=newLine, padding, renderLine(""));

  let top =
    String.concat(
      ~sep="",
      [
        marginTop,
        marginLeft,
        symbols.topLeft,
        horitzontalTop,
        symbols.topRight,
      ],
    );
  let middle =
    padding == 0
      ? String.concat(~sep=newLine, [content])
      : String.concat(~sep=newLine, [paddingTop, content, paddingBottom]);

  let bottom =
    String.concat(
      ~sep="",
      [
        marginLeft,
        symbols.bottomLeft,
        horitzontalBottom,
        symbols.bottomRight,
        marginBottom,
      ],
    );

  String.concat(~sep=newLine, [top, middle, bottom]);
};
