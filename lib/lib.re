open Border;

let none = "";
let empty = ' ';
let newLine = "\n";

let splitLines = (text) => text |> Base.String.split_lines |> List.map(String.trim);
let textLength = Base.String.length;
let row = String.concat(newLine);
let stack = String.concat("");

let repeat = (~between="", times, str) => {
  let listOfStrings = Array.init(times, _ => str) |> Array.to_list;
  String.concat(between, listOfStrings);
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

let getTerminalColumns = (): int => {
  switch (Sys.getenv_opt("COLUMNS")) {
  | Some(value) => int_of_string(value)
  | None => 80
  }
};

type position = [ | `Left | `Center | `Right];

let box = (~align=`Center, ~float=`Left, ~padding=0, ~margin=Margin.empty, ~kind=Round, text) => {
  let symbols = Border.symbols(kind);
  let columns = getTerminalColumns();
  let bordersWidth = 2;

  let paddingLeftValue = padding + bordersWidth;
  let paddingLeft = renderEmpty(paddingLeftValue);

  let marginTop = repeat(margin.top, newLine);
  let marginBottom = repeat(margin.bottom, newLine);

  let contentWidth = calculateWidestLine(text) + paddingLeftValue * 2;
  let horitzontalTop = repeat(contentWidth, symbols.top);
  let horitzontalBottom = repeat(contentWidth, symbols.bottom);

  let calculateMarginLeft = (~columns as _, value) => {
    switch (float) {
      | `Left => value * 2
      | `Center => contentWidth - value * 2
      | `Right => (contentWidth * 2) - value * 2
    }
  };

  let marginLeftValue = calculateMarginLeft(~columns, margin.left);
  let marginLeft = renderEmpty(marginLeftValue);

  let renderLine = (text) => {
    let paddingRightValue =
      contentWidth - textLength(text) - padding - bordersWidth;
    let paddingRight = renderEmpty(paddingRightValue);
    let text = stack([paddingLeft, text, paddingRight]);
    stack(
      [marginLeft, symbols.left, text, symbols.right],
    );
  };

  let renderContent = (text) => {
    let widestLine = calculateWidestLine(text);
    let lines = splitLines(text);
    switch (align) {
      | `Left => lines |> List.map(renderLine);
      | `Right => {
        lines |> List.map((line) => {
          let padLeft = widestLine - textLength(line);
          let left = repeat(padLeft, " ");
          stack([left, line]) |> renderLine;
        });
      }
      | `Center => {
        lines |> List.map((line) => {
          let padRight = (widestLine - textLength(line)) / 2;
          let left = repeat(padRight, " ");
          stack([left, line]) |> renderLine;
        });
      }
    }
  };

  let content = renderContent(text) |> row;
  let paddingTop = repeat(~between=newLine, padding, renderLine(""));
  let paddingBottom = repeat(~between=newLine, padding, renderLine(""));

  let header =
    stack(
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
      ? content
      : row([paddingTop, content, paddingBottom]);

  let footer =
    stack(
      [
        marginLeft,
        symbols.bottomLeft,
        horitzontalBottom,
        symbols.bottomRight,
        marginBottom,
      ],
    );

  row([header, body, footer]);
};
