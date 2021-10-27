open Border;

let splitLines = (text) => text |> Base.String.split_lines |> List.map(String.trim);
let textLength = Base.String.length; /* TODO: Implement ascii length */
let concat = String.concat("");

let repeat = (~sep, times, str) => {
  let listOfStrings = Array.init(times, _ => str) |> Array.to_list;
  String.concat(sep, listOfStrings);
};

let calculateWidestLine = text => {
  text
  |> splitLines
  |> List.fold_left(
      (current, acc) => max(current, textLength(acc)),
      0,
    );
};

let newLine = "\n";

let makeEmpty = value => {
  if (value > 0) {
    String.make(value, ' ')
  } else {
    ""
  }
};

let getTerminalColumns = () => {
  Sys.getenv_opt("COLUMNS");
};

type alignment = [ | `Left | `Center | `Right];

let box = (~align=`Center, ~padding=0, ~margin=0, ~kind=Round, text) => {
  let _columns = getTerminalColumns();
  let bordersWidth = 2;
  let symbols = Border.symbols(kind);
  let paddingLeftValue = padding + bordersWidth;
  let marginLeftValue = margin * 2;
  let marginLeft = makeEmpty(marginLeftValue);
  let paddingLeft = makeEmpty(paddingLeftValue);
  let contentWidth = calculateWidestLine(text) + paddingLeftValue * 2;
  let marginTop = repeat(~sep="", margin, newLine);
  let marginBottom = repeat(~sep="", margin, newLine);
  let horitzontalTop = repeat(~sep="", contentWidth, symbols.top);
  let horitzontalBottom = repeat(~sep="", contentWidth, symbols.bottom);

  let renderLine = (text) => {
    let paddingRightValue =
      contentWidth - textLength(text) - padding - bordersWidth;
    let paddingRight = makeEmpty(paddingRightValue);
    let text = concat([paddingLeft, text, paddingRight]);
    concat(
      [marginLeft, symbols.left, text, symbols.right],
    );
  };

  let renderContent = (text) => {
    let widestLine = text |> calculateWidestLine;
    let lines = text |> splitLines;
    switch (align) {
      | `Left => lines |> List.map(renderLine);
      | `Right => {
        lines |> List.map((line) => {
          let padLeft = widestLine - textLength(line);
          let left = repeat(~sep=" ", padLeft + 1, "");
          concat([left, line]) |> renderLine;
        });
      }
      | `Center => {
        lines |> List.map((line) => {
          let padRight = (widestLine - textLength(line)) / 2;
          let left = repeat(~sep=" ", padRight + 1, "");
          concat([left, line]) |> renderLine;
        });
      }
    }
  };

  let content = renderContent(text) |> String.concat(newLine);
  let paddingTop = repeat(~sep=newLine, padding, renderLine(""));
  let paddingBottom = repeat(~sep=newLine, padding, renderLine(""));

  let first =
    concat(
      [
        marginTop,
        marginLeft,
        symbols.topLeft,
        horitzontalTop,
        symbols.topRight,
      ],
    );

  let body =
    padding == 0
      ? String.concat(newLine, [content])
      : String.concat(newLine, [paddingTop, content, paddingBottom]);

  let last =
    concat(
      [
        marginLeft,
        symbols.bottomLeft,
        horitzontalBottom,
        symbols.bottomRight,
        marginBottom,
      ],
    );

  String.concat(newLine, [first, body, last]);
};
